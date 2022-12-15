/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:24:08 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/15 17:07:27 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int		run_algo(Bomber *man)
{
	if (man->sccount >= man->ccount && man->secount >= man->ecount)
	{
		printf("Pathing completed - viable path found!\n");
		return (0);
	}
	else if (step(man) > 0)
	{
		man->stepcounter++;
		replace('q', 'Q', man);
		adding_in_graphics(man);
		printf("%d collectables, %d scanned\n%d exits, %d scanned\n%d steps taken.\n\n", man->ccount, man->sccount, man->ecount, man->secount, man->stepcounter);
		return (1);
	}
	else
		printf("Pathing completed - NO viable path found!\n");
	adding_in_graphics(man);
	return (0);
}

int		exit_point(Bomber *man)
{
	int		line;

	line = 0;
	if (man->winpointer)
		mlx_destroy_window(man->mlxpointer, man->winpointer);
	free(man->mlxpointer);
	while (line < man->heightmap - 1)
		free(man->map[line++]);
	free(man->map);
	exit(0);
}

int main(int argc, char **argv)
{
    Bomber   man;

	if (argc != 2)
        return (0);
    ft_memset(&man, 0, sizeof(Bomber));
	map_reading(&man, argv);
	check_errors(&man);
	man.mlxpointer = mlx_init();
	man.winpointer = mlx_new_window(man.mlxpointer, (man.widthmap * 40), (man.heightmap * 40), "Bomberman");
	//mlx_loop_hook(man.mlxpointer, render_next_frame, &man);
	place_images_in_game(&man);
	adding_in_graphics(&man);
	mlx_key_hook(man.winpointer, controls_working, &man);
	mlx_hook(man.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(man.mlxpointer);
}