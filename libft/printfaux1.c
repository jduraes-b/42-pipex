/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:39:54 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/18 19:37:03 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ischar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_isstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
	return (i);
}

int	ft_isint(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = ft_isstring(str);
	free(str);
	return (i);
}
/*
int	ft_isu(unsigned int n)
{
        char    *str;
        int     i;

	
	i = 0;
	str = ft_unsigneditoa(n);
	i = i + ft_isstring(str);
	free (str);
	return (i);
}
*/
