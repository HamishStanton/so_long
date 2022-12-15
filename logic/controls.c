/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:06:50 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/15 17:57:39 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	right_move(Bomber *man, int i, int j);

static int	keyboard_w_s(Bomber *man, int movement)
{
	int		i;
	int		j;
	int		k;

	i = man->x;
	j = man->y;
	if (movement == 13)
	{
		if (man->direction != 3 && man->map[j - 1][i] == '1')
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_N(S).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 3;
			return (0);
		}
		else if (man->direction != 3)
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_N(NS).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 3;
			return (0);
		}
		if (man->direction == 3)
		{
			j--;
			if (man->map[j][i] == '1' || man->map[j][i] == 'B' ||
				man->map[j][i] == 'X')
			{
				return (0);
			}
			k = right_move(man, i, j);
			if (!k)
				return (0);
			man->map[j + 1][i] = '0';
			if (man->map[j - 1][i] == '1')
			{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_N(S).xpm", &i, &j);
			}
			else
			{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_N(NS).xpm", &i, &j);
			}
		}
	}
	else if (movement == 1)
	{
		if (man->direction != 4 && man->map[j - 1][i] == '1')
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_S(S).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 4;
			return (0);
		}
		else if (man->direction != 4)
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_S(NS).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 4;
			return (0);
		}
		if (man->direction == 4)
		{
			j++;
			if (man->map[j][i] == '1' || man->map[j][i] == 'B' ||
				man->map[j][i] == 'X' || man->map[j][i] == 'V' ||
				man->map[j][i] == 'Y' || man->map[j][i] == 'Z' ||
				man->map[j][i] == 91)
			{	
				return (0);
			}
			k = right_move(man, i, j);
			if (!k)
				return (0);
			if (man->map[j - 2][i] == '1')
				man->map[j - 1][i] = 'S';
			else
				man->map[j - 1][i] = '0';
			if (man->map[j - 1][i] == '1')
			{
				man->player = mlx_xpm_file_to_image(man->mlxpointer,
					"images/Player/Player_S(S).xpm", &i, &j);
			}
			else
			{
				man->player = mlx_xpm_file_to_image(man->mlxpointer,
					"images/Player/Player_S(NS).xpm", &i, &j); 
			}
		}
	}
	printf("\nSteps Taken: \e[32m\e[1m%i\e[0m \n", man->stepcounter);
	printf("Collectables Left: \e[33m\e[1m%i\e[0m \n", man->ccount);
	return (1);
}

static int	keyboard_a_d(Bomber *man, int movement)
{
	int		i;
	int		j;
	int		k;

	i = man->x;
	j = man->y;
	if (movement == 0)
	{
		if (man->direction != 1 && man->map[j - 1][i] == '1')
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_W(S).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 1;
			return (0);
		}
		else if (man->direction != 1)
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_W(NS).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 1;
			return (0);
		}
		if (man->direction == 1)
		{
			i--;
			if (man->map[j][i] == '1' || man->map[j][i] == 'B' ||
				man->map[j][i] == 'X' || man->map[j][i] == 'V' ||
				man->map[j][i] == 'Y' || man->map[j][i] == 'Z' ||
				man->map[j][i] == 91)
			{
				return (0);
			}
			k = right_move(man, i, j);
			if (!k)
				return (0);
			if (man->map[j - 1][i + 1] == '1')
				man->map[j][i + 1] = 'S';
			else
				man->map[j][i + 1] = '0';
			if (man->map[j - 1][i] == '1')
			{
				man->player = mlx_xpm_file_to_image(man->mlxpointer,
					"images/Player/Player_W(S).xpm", &i, &j);
			}
			else
			{
				man->player = mlx_xpm_file_to_image(man->mlxpointer,
					"images/Player/Player_W(NS).xpm", &i, &j);
			}
		}
	}
	else if (movement == 2)
	{
		if (man->direction != 2 && man->map[j - 1][i] == '1')
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_E(S).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 2;
			return (0);
		}
		else if (man->direction != 2)
		{
			man->player = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Player/Player_E(NS).xpm", &i, &j);
			adding_in_graphics(man);
			man->direction = 2;
			return (0);
		}
		if (man->direction == 2)
		{
			i++;
			if (man->map[j][i] == '1' || man->map[j][i] == 'B' ||
				man->map[j][i] == 'X' || man->map[j][i] == 'V' ||
				man->map[j][i] == 'Y' || man->map[j][i] == 'Z' ||
				man->map[j][i] == 91)
			{
				return (0);
			}
			k = right_move(man, i, j);
			if (!k)
				return (0);
			if (man->map[j - 1][i - 1] == '1')
				man->map[j][i - 1] = 'S';
			else
				man->map[j][i - 1] = '0';
			if (man->map[j - 1][i] == '1')
			{
				man->player = mlx_xpm_file_to_image(man->mlxpointer,
					"images/Player/Player_E(S).xpm", &i, &j);
			}
			else
			{
				man->player = mlx_xpm_file_to_image(man->mlxpointer,
					"images/Player/Player_E(NS).xpm", &i, &j);
			}
		}
	}
	printf("\nSteps Taken: \e[32m\e[1m%i\e[0m \n", man->stepcounter);
	printf("Collectables Left: \e[33m\e[1m%i\e[0m \n", man->ccount);
	return (1);
}

static int	keyboard_e_bomb(Bomber *man, int press)
{
	int		i;
	int		j;
	int		k;
	
	i = man->x;
	j = man->y;
	k = man->direction;
	if (press == 14)
	{
		if (k == 1)
			i--;
		if (k == 2)
			i++;
		if (k == 3)
			j--;
		if (k == 4)
			j++;
		if (man->map[j][i] == '1' || man->map[j][i] == 'B' ||
			man->map[j][i] == 'C' || man->map[j][i] == 'E' ||
			man->map[j][i] == 'V' || man->map[j][i] == 'Y' ||
			man->map[j][i] == 'Z' || man->map[j][i] == 91)
		{
			return (0);
		}
		if (man->map[j][i] == '0' || man->map[j][i] == 'S')
			man->map[j][i] = 'V';
	}
	return (1);
}

static int	right_move(Bomber *man, int i, int j)
{
	if (man->map[j][i] == 'E')
	{
		if (man->ccount != 0)
		{
			printf("\e[31m\e[1m\nThe Exit seems shut...\e[0m\n");
			printf("\e[31m\e[1m(Hint: Look for the collectables!)\e[0m\n");
			return (0);
		}
		printf("\e[31m\e[1m\nYou Have Won, Congrats! \e[0m \n");
		exit_point(man);
	}
	if (man->map[j][i] == '0' || man->map[j][i] == 'S')
	{
		man->map[j][i] = 'P';
		man->x = i;
		man->y = j;
		man->stepcounter++;
	}
	if (man->map[j][i] == 'C')
	{
		man->map[j][i] = 'P';
		man->x = i;
		man->y = j;
		man->ccount--;
		man->stepcounter++;
		if (man->ccount == 0)
		{
			man->exit = mlx_xpm_file_to_image(man->mlxpointer,
				"images/Exit/Exit_open.xpm", &i, &j);
			printf("\e[31m\e[1m\n*BOOM*\nYou hear something open..!\e[0m\n");
		}
	}
	return (1);
}

int	controls_working(int command, Bomber *man)
{
	int	works;

	if (command == 49)
		works = run_algo(man);
	if (command == 13)
		works = keyboard_w_s(man, command);
	if (command == 1)
		works = keyboard_w_s(man, command);
	if (command == 0)
		works = keyboard_a_d(man, command);
	if (command == 2)
		works = keyboard_a_d(man, command);
	if (command == 14)
		works = keyboard_e_bomb(man, command);
	if (command == 53)
		exit_point(man);
	if (works)
		adding_in_graphics(man);
	return (1);
}
