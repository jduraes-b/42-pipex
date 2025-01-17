/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:37:51 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/18 19:51:06 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	algcount(unsigned int x)
{
	int	contador;

	contador = 1;
	while (x / 10 > 0)
	{
		contador++;
		x = x / 10;
	}
	return (contador);
}

int	ft_isu(unsigned int n)
{
	char			vec[11];
	unsigned int	i;
	unsigned int	alg;

	alg = algcount(n);
	i = alg;
	vec[i] = '\0';
	while (i > 0)
	{
		vec[i - 1] = ((char)(n % 10) + '0');
		n = n / 10;
		i--;
	}
	write(1, vec, alg);
	return (alg);
}
