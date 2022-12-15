/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:19:19 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/02 23:46:54 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int      width_of_map(char *string)
{
    int width;

    width = 0;
    while (string[width] != '\0')
        width++;
    if (string[width - 1] == '\n')
        width--;
    return (width);
}

static int      add_line(Bomber *man, char *line)
{
    char    **temp;
    int     i;

    if (!line)
        return (0);
    i = 0;
    man->heightmap++;
    temp = (char **)malloc(sizeof(char *) * (man->heightmap + 1));
    temp[man->heightmap] = NULL;
    while (i < man->heightmap - 1)
    {
        temp[i] = man->map[i];
        i++;
    }
    temp[i] = line;
    if (man->map)
        free(man->map);
    man->map = temp;
    return (1);
}

int     map_reading(Bomber *man, char **av)
{
    char    *readmap;

    man->fd = open(av[1], O_RDONLY);
    if (man->fd < 0)
        return (0);
    while (1)
    {
        readmap = get_next_line(man->fd);
        if (!add_line(man, readmap))
            break ;
    }
    close (man->fd);
    man->widthmap = width_of_map(man->map[0]);
    return (1);
}