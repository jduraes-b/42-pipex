/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:00:30 by jduraes-          #+#    #+#             */
/*   Updated: 2023/02/13 03:01:04 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	ii;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		ii = 0;
		while (str[i + ii] != '\0' && str[i + ii] == to_find[ii])
		{
			if (to_find[ii + 1] == '\0')
				return (&str[i]);
			++ii;
		}
		++i;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "Sera que t3m bandido?";
	char *to_find = "3";

	printf("%s\n", ft_strstr(str, to_find));
}*/
