/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:17 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/27 16:49:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*asrc;
	size_t	i;
	size_t	sizedst;

	i = 0;
	asrc = (char *)src;
	sizedst = ft_strlen(dst);
	while (asrc[i] != '\0' && (sizedst + 1 + i) < size)
	{
		dst[sizedst + i] = asrc[i];
		i++;
	}
	dst[sizedst + i] = '\0';
	if (size > sizedst)
		return (sizedst + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
