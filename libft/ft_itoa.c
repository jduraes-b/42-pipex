/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:17:56 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/08 17:21:36 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert(char *str, long int n, int isnega)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if ((n % 10) > 9)
			str[i] = (n % 10) - 10 + 'a';
		if ((n % 10) < 10)
			str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (isnega)
		str[i++] = '-';
	str[i] = '\0';
}

static int	algcount(long int n, int isnega)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i + isnega);
}

void	rstr(char *str, int size)
{
	int		i;
	int		ii;
	char	temp;

	i = size - 1;
	ii = 0;
	if (*str == '\0')
	{
		str[i] = '0';
		str[i + 1] = '\0';
	}
	while (ii < size / 2)
	{
		temp = str[i];
		str[i] = str[ii];
		str[ii] = temp;
		i--;
		ii++;
	}
}

char	*ft_itoa(int n)
{
	long int	ln;
	int			isnega;
	int			size;
	char		*str;

	ln = n;
	isnega = 0;
	if (ln < 0)
	{
		isnega = 1;
		ln = -ln;
	}
	size = algcount(ln, isnega);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	convert(str, ln, isnega);
	rstr(str, size);
	return (str);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		n;
	char	*str;

	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		str = ft_itoa(n);
		printf("%s", str);
	}
	else
		printf("numero invalido de argumentos");
}
*/
