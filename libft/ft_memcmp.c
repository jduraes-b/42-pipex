/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:40:04 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/25 18:00:33 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*as1;
	const unsigned char	*as2;
	size_t				i;

	as1 = (const unsigned char *)s1;
	as2 = (const unsigned char *)s2;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			if (as1[i] != as2[i])
				return (as1[i] - as2[i]);
			i++;
		}
	}
	return (0);
}
