/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:49:03 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/15 18:01:16 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	horizontalwall(Bomber *man)
{
	int		width;
    int		height;

	width = man->widthmap;
	height = 0;
	while (height < width)
    {
        if (man->map[0][width] == '1' && man->map[man->heightmap - 1][height] == '1')
            return (0);
        height++;
    }
    return (1);
}

static int  verticalwall(Bomber *man)
{
    int     height;
    int     width;

    height = 0;
    width = man->widthmap;
    while (height < man->heightmap)
    {
        if (!(man->map[height][0] == '1' && man->map[height][width - 1] == '1'))
            return (0);
        height++;
    }
    return (1);
    }

static void     if_walls(Bomber *man)
{
    int     verticalwalls;
    int     horizontalwalls;

    verticalwalls = verticalwall(man);
    horizontalwalls = horizontalwall(man);
    if (!verticalwalls || !horizontalwalls)
    {
        printf("\e31m\e[1mError\nThis map is missing the walls\e[0m \n");
        exit_point(man);
    }
}

static void     count_checker(Bomber *man, int height, int width)
{
    if(man->map[height][width] != '1' &&
        man->map[height][width] != '0' &&
        man->map[height][width] != 'S' &&
        man->map[height][width] != 'B' &&
        man->map[height][width] != 'P' &&
        man->map[height][width] != 'E' &&
        man->map[height][width] != 'C' &&
        man->map[height][width] != '\n')
    {
        printf("\e[31m\e[1mError\nError Here!%c\n", man->map[height][width]);
        exit_point(man);
    }
    if (man->map[height][width] == 'C')
        man->ccount++;
    if (man->map[height][width] == 'P')
        man->pcount++;
    if (man->map[height][width] == 'E')
        man->ecount++;
}

void    character_valid(Bomber *man)
{
    int height;
    int width;
    
    height = 0;
    while (height < man->heightmap - 1)
    {
        width = 0;
        while (width <= man->widthmap)
        {
            count_checker(man, height, width);
            width++;
        }
        height++;
    }
    if (!(man->pcount == 1 || man->ccount > 1 
        || man->ecount == 1))
    {
        printf("\e[31m\e[1mError\n Something is wrong, ");
        printf("either player, exit or collectable issue \e[0m \n");
        exit_point(man);
    }
}

void    check_errors(Bomber *man)
{
    if_walls(man);
    character_valid(man);
}