/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:29:04 by jduraes-          #+#    #+#             */
/*   Updated: 2023/09/27 18:17:10 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char *cmd, char **envp)
{
	char	**pathlines;
	char	*path;
	char	*temp;
	int		i;

	i = -1;
	while (envp[++i] && !ft_strnstr(envp[i], "PATH=", 5))
		;
	pathlines = ft_split(envp[i] + 5, ':');
	i = -1;
	while (pathlines[++i])
	{
		temp = ft_strjoin(pathlines[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
		{
			doublefree(pathlines);
			return (path);
		}
		free(path);
	}
	doublefree(pathlines);
	return (NULL);
}
