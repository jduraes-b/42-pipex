/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:33:43 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/20 17:02:22 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*adest;
	char	*asrc;
	char	*temp;

	adest = (char *)dest;
	asrc = (char *)src;
	temp = (char *)src;
	if (adest > asrc)
	{
		while (n != 0)
		{
			n--;
			adest[n] = temp[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
