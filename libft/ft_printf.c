/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:44:29 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/24 18:35:11 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checktype(int i, va_list args)
{
	if (i == 'c')
		return (ft_ischar(va_arg(args, int)));
	if (i == 's')
		return (ft_isstring(va_arg(args, char *)));
	if (i == 'p')
		return (ft_ispointer(va_arg(args, unsigned long long)));
	if (i == 'i' || i == 'd')
		return (ft_isint(va_arg(args, int)));
	if (i == 'u')
		return (ft_isu(va_arg(args, unsigned int)));
	if (i == 'x')
		return (lowhex(va_arg(args, unsigned int)));
	if (i == 'X')
		return (caphex(va_arg(args, unsigned int)));
	if (i == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		total;

	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			total += checktype(str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			total++;
		}
		i++;
	}
	va_end(args);
	return (total);
}
