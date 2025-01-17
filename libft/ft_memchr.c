/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:04:35 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/20 17:39:16 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	ac;
	size_t	i;

	i = 0;
	str = (char *)s;
	ac = (char)c;
	while (i < n)
	{
		if (str[i] == ac)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
