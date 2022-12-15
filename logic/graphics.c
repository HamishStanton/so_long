/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:01:11 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/15 17:09:56 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    place_player(Bomber *man, int height, int width)
{
    mlx_put_image_to_window(man->mlxpointer,
        man->winpointer, man->player, width * 40, height * 40);
    man->y = height;
    man->x = width;
}

void    replace(char target, char replacement, Bomber *man)
{
    int x;
    int y;

    y = 1;
    while (y < man->heightmap - 1)
    {
        x = 1;
        while (x < man->widthmap - 1)
        {
            if (man->map[y][x] == target)
                man->map[y][x] = replacement;
            x++;
        }
        y++;
    }
}

void    place_collectable(Bomber *man, int height, int width)
{
    mlx_put_image_to_window(man->mlxpointer,
        man->winpointer, man->collectable, width * 40, height * 40);
    man->ccount++;
}

void    get_bomb_txt(Bomber *man)
{
    int height;
    int width;

    man->Bomb_array = malloc(sizeof(t_bomb) * 5);

    man->Bomb_array[0].txt = mlx_xpm_file_to_image(man->mlxpointer, "images/Bomb/1.xpm", &width, &height);
    man->Bomb_array[1].txt = mlx_xpm_file_to_image(man->mlxpointer, "images/Bomb/2.xpm", &width, &height);
    man->Bomb_array[2].txt = mlx_xpm_file_to_image(man->mlxpointer, "images/Bomb/3.xpm", &width, &height);
    man->Bomb_array[3].txt = man->Bomb_array[1].txt;
    man->Bomb_array[4].txt = mlx_xpm_file_to_image(man->mlxpointer, "images/Bomb/4.xpm", &width, &height);
}

void    place_images_in_game(Bomber *man)
{
    int i;
    int j;

    man->floor = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Grass/Grass_NS_.xpm", &i, &j);
    man->floorS = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Grass/Grass_S_.xpm", &i, &j);
    man->wall = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Wall/Wall.xpm", &i, &j);
    man->Brick = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Wall/Brick.xpm", &i, &j);
    get_bomb_txt(man);
    man->Bomb = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Bomb/1.xpm", &i, &j);                
    man->player = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Player/Player_S(S).xpm", &i, &j);
    man->exit = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Exit/Exit_closed.xpm", &i, &j);
    man->collectable = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/Collectable/collectable(Light)(S)(1).xpm", &i, &j);
    man->scanner = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/scan/scanner.xpm", &i, &j);
    man->scanned = mlx_xpm_file_to_image(man->mlxpointer,
                    "images/scan/scanned.xpm", &i, &j);
}

void    draw_bomb(Bomber *man, int j, int i)
{
    if (man->map[j][i] >= 'V' && man->map[j][i] <= 91)
    {
        if (man->map[j][i] == 91 && man->map[j - 1][i] == '1')
            man->map[j][i] = 'S';
        else if (man->map[j][i] == 91 && man->map[j - 1][i] != '1')
            man->map[j][i] = '0';
        else
        {
            man->map[j][i] += 1;
            mlx_put_image_to_window(man->mlxpointer,
                man->winpointer, man->Bomb_array[man->map[j][i] - 'W'].txt, i * 40, j * 40);
        }
    }
}

void    adding_in_graphics(Bomber *man)
{
    int height;
    int width;

    man->ccount = 0;
    height = 0;
    while (height < man->heightmap)
    {
        width = 0;
        while (man->map[height][width])
        {
            draw_bomb(man, height, width);
            if (man->map[height][width] == '1')
                mlx_put_image_to_window(man->mlxpointer,
                        man->winpointer, man->wall, width * 40, height * 40);
            if (man->map[height][width] == 'B')
                mlx_put_image_to_window(man->mlxpointer,
                        man->winpointer, man->Brick, width * 40, height * 40);
            if (man->map[height][width] == 'C')
                place_collectable(man, height, width);
            if (man->map[height][width] == 'P')
                place_player(man, height, width);
            if (man->map[height][width] == 'E')
                mlx_put_image_to_window(man->mlxpointer,
                        man->winpointer, man->exit, width * 40, height * 40);
            if (man->map[height][width] == '0')
                mlx_put_image_to_window(man->mlxpointer,
                        man->winpointer, man->floor, width * 40, height * 40);
            if (man->map[height][width] == 'S')
                mlx_put_image_to_window(man->mlxpointer,
                        man->winpointer, man->floorS, width * 40, height * 40);
            if (man->map[height][width] == 'T')
                mlx_put_image_to_window(man->scanned,
                        man->winpointer, man->scanned, width * 40, height * 40);
            if (man->map[height][width] == 'Q')
                mlx_put_image_to_window(man->scanner,
                        man->winpointer, man->scanner, width * 40, height * 40);
            width++;
        }
        height++;
    }
}