/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:25:00 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/15 17:07:58 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "../minilibx/mlx.h"

typedef struct s_bomb
{
    void    *txt;
} t_bomb;

typedef struct  Bomb
{
    int fd; //used to read in the map (argv)
    int heightmap; //used to set the height of the map (heightmap = 0 being at the top)
    int widthmap; //used to set the width of the map (widthmap = 0 being on the left)
    int pcount; //used to count no. of players (for errorchecking)
    int ccount; //used to count collectables (for errorchecking)
    int ecount; //used to count exits (for errorchecking)
    int sccount; //used to count scanned coins (for flood fill)
    int secount; //used to count scanned exits (for flood fill)
    int x;
    int y;
    int stepcounter; //--
    int direction; //used to determine direction of PC for bomb placement (W=1, E=2, N=3, S=4)
    //int lock; //locks mode

    char    **map; //pointer for map
    char    *folder;
    char    *file;
    char    *xpm;

    //void    *img; // --
    void    *floor; //var Grass_NS_.xpm >> images
    void    *floorS; //var Grass_S_.xpm >> images
    void    *wall; //var Wall.xpm >> images
    void    *Brick; //var Brick.xpm >> images
    void    *Bomb; //var Bomb.xpm >> images
    t_bomb  *Bomb_array;
    void    *player; //var player.xpm >> images
    void    *exit; //var exit.xpm >> images
    void    *collectable; //var collectable.xpm >> images
    void    *scanned; //scanned tile >> images
    void    *scanner; //scanning tile >> images
    void    *mlxpointer; //pntr to mlx (placing)
    void    *winpointer; //pntr to window (adding)
 
} Bomber;

int     exit_point(Bomber *man);
int     map_reading(Bomber *man, char **av);
int     controls_working(int command, Bomber *man);
void    adding_in_graphics(Bomber *man);
void    place_images_in_game(Bomber *man);
void    check_errors(Bomber *man);
int     render_next_frame(Bomber *man);
char    *ft_itoa(int n);
void    *ft_memset(void *b, int c, size_t len);
int     step(Bomber *man);
int     run_algo(Bomber *man);
void    replace(char target, char replacement, Bomber *man);

#endif
