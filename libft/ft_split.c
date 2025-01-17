/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:59:11 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/05 18:23:42 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fillvec(char *s, char **str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			str[j][k] = s[i];
			k++;
			i++;
			str[j][k] = '\0';
		}
		j++;
	}
}

int	ft_wc(char *str, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			wc++;
		}
		i++;
	}
	return (wc);
}

int	ft_ws(char *s, char c, int *jj)
{
	int	ws;
	int	j;

	j = *jj;
	ws = 0;
	while (s[j] == c)
		j++;
	while (s[j] != c && s[j] != '\0')
	{
		ws++;
		j++;
	}
	*jj = j;
	return (ws);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*ss;
	int		i;
	int		wc;
	int		j;

	j = 0;
	ss = (char *)s;
	wc = ft_wc(ss, c);
	str = malloc(sizeof(char *) * (wc + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		str[i] = malloc(sizeof(char) * (ft_ws(ss, c, &j) + 1));
		if (!str[i])
			return (NULL);
		i++;
		j++;
	}
	str[wc] = NULL;
	fillvec(ss, str, c);
	return (str);
}
/*
int	main(int argc, char *argv[])
{
	int	i = 0;
	int	j = 0;
	char	**vec;
	if (argc == 3)
	{
		vec = ft_split(argv[1], argv[2][0]);
		while (vec[i] != NULL)
		{
			j = 0;
			while(vec[i][j] != '\0')
			{
				write(1, &vec[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	write (1, "\n", 1);
}*/
