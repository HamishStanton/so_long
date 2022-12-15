/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:13 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/15 16:57:20 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    mark(int x, int y, Bomber *man)
{
    if (man->map[y][x] == '0' || man->map[y][x] == 'S')
        man->map[y][x] = 'q';
    else if(man->map[y][x] == 'C') //mark collectable
    {
        man->map[y][x] = 'q';
        man->sccount++;
    }
    else if(man->map[y][x] == 'E') //mark exit
    {
        man->map[y][x] = 'q';
        man->secount++;
    }
}

int     is_walkable(int x, int y, Bomber *man)
{
    if (man->map[y][x] == '0' || man->map[y][x] == 'C' || man->map[y][x] == 'E' || man->map[y][x] == 'S')
        return (1);
    return (0);
}

void    scan_directions(int x, int y, Bomber *man)
{
    if (is_walkable(x - 1, y, man)) // west
        mark(x - 1, y, man);
    if (is_walkable(x + 1, y, man)) // east
        mark(x + 1, y, man);
    if (is_walkable(x, y - 1, man)) // north
        mark(x, y - 1, man);
    if (is_walkable(x, y + 1, man)) // south
        mark(x, y + 1, man);

    if (man->map[y][x] != 'P')
        man->map[y][x] = 'T';
    if (man->map[y][x] == 'P')
        man->map[y][x] = 'P';
}

int step(Bomber *man)
{
    int edits;

    edits = 0;
    int x;
    int y;

    y = 1; //set to one cause edges should be walled in anyways
    while(y < man->heightmap - 1)
    {
        x = 1;
        while (x < man->widthmap - 1)
        {
            if (man->map[y][x] == 'Q' || man->map[y][x] == 'P')
            {
                scan_directions(x, y, man);
                edits++;
            }
            x++;
        }
        y++;
    }
    return (edits); //if edits remains 0, will have either completed on the final scan, or failed to find a path.
}
