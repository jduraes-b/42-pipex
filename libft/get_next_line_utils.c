/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:41:00 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/21 20:54:26 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenplus(char *s, char c)
{
	int	i;

	i = 0;
	if (c == '\n')
	{
		while (s && s[i] != '\0' && s[i] != '\n')
			i++;
		if (s[i] == c)
			return (i);
		return (-1);
	}
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlenplus(s1, 0) + ft_strlenplus(s2, 0))
			+ 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}
