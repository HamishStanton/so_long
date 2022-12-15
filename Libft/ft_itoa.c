/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstanton <hstanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:32:50 by hstanton          #+#    #+#             */
/*   Updated: 2022/12/04 21:13:14 by hstanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int     ft_abs(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    return (nbr);
}

void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i++ - 1] = tmp;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		s;
	size_t	length;

	s = (n < 0);
	str = ft_calloc(11 + s, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (s)
		str[length] = '-';
	ft_strrev(str);
	return (str);
}
