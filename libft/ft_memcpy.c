/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:04:55 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/25 17:08:15 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*adest;
	const char	*asrc;

	i = 0;
	adest = dest;
	asrc = src;
	if (src == NULL && dest == NULL)
		return (NULL);
	while (i < n)
	{
		adest[i] = asrc[i];
		i++;
	}
	return (dest);
}
