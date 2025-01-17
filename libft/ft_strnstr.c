/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:38:23 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/28 18:08:30 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*abig;

	i = 0;
	j = 0;
	abig = (char *)big;
	if (*little == '\0')
		return (abig);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (abig[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (&abig[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
