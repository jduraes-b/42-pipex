/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:11:50 by jduraes-          #+#    #+#             */
/*   Updated: 2023/04/28 17:43:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i--;
	}
	if (str[i] == (unsigned char)c)
		return (&str[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	*src = "\0";
	char	*d1 = strrchr(src, 'a');
	char	*d2 = ft_strrchr(src, 'a');

	printf("%s\n%s", d1, d2);
}*/
