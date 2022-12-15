/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:26:29 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/04 21:25:50 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include "../minilibx/mlx.h"

int     ft_abs(int nbr);
void	ft_strrev(char *str);
char	*ft_itoa(int n);
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

#endif
