/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:02:07 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/24 18:12:50 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	algcount(unsigned int n)
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

int	ft_puthex(unsigned int nb, char *base)
{
	long	n;

	n = nb;
	if (n < 16)
	{
		ft_putchar(base[n]);
	}
	if (n >= 16)
	{
		ft_puthex((n / 16), base);
		ft_puthex((n % 16), base);
	}
	return (algcount(nb));
}

int	lowhex(unsigned int n)
{
	return (ft_puthex(n, "0123456789abcdef"));
}

int	caphex(unsigned int n)
{
	return (ft_puthex(n, "0123456789ABCDEF"));
}
