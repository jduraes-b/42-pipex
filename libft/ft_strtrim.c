/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:23:00 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/05 17:06:44 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkstart(char *str, char *set)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (set[i] != str[j] && set[i])
		{
			i++;
		}
		if (set[i] == str[j])
		{
			i = 0;
			count++;
			j++;
		}
		else
			return (count);
	}
	return (count);
}

int	checkend(char *str, char *set)
{
	int	i;
	int	j;
	int	count;
	int	strsize;

	count = 0;
	strsize = ft_strlen(str);
	j = strsize - 1;
	while (j > 0)
	{
		i = 0;
		while (set[i] != str[j] && set[i])
		{
			i++;
		}
		if (set[i] == str[j])
		{
			i = 0;
			count++;
			j--;
		}
		else
			return (count);
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		mallocsize;
	int		start;
	int		s1size;
	char	*str;

	i = 0;
	s1size = ft_strlen(s1);
	start = checkstart((char *)s1, (char *)set);
	if (start == s1size)
		mallocsize = 1;
	else
		mallocsize = 1 + ft_strlen((char *)s1) - (start + checkend((char *)s1,
					(char *)set));
	str = (char *)malloc(sizeof(char) * mallocsize);
	if (str == NULL)
		return (NULL);
	str[mallocsize - 1] = '\0';
	while (i < mallocsize - 1)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	return (str);
}
