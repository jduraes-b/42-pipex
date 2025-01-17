/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:15:36 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/24 18:48:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	algcount(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putp(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		ft_putchar(base[n]);
	}
	if (n >= 16)
	{
		ft_putp(n / 16);
		ft_putp(n % 16);
	}
	return (algcount(n));
}

int	ft_ispointer(unsigned long long n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		return (2 + ft_putp(n));
	}
}
