/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:32 by jduraes-          #+#    #+#             */
/*   Updated: 2023/10/23 19:00:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**cmdpparam;
	char	*path;

	cmdpparam = ft_split(cmd, 32);
	if (!cmd[0])
		return ;
	if (cmd[0] == '/')
		path = cmd;
	else
		path = findpath(cmdpparam[0], envp);
	if (!path)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("%s: command not found\n", cmdpparam[0]);
		free(path);
		doublefree(cmdpparam);
		exit(127);
	}
	if (execve(path, cmdpparam, envp) == -1)
	{
		free(path);
		doublefree(cmdpparam);
		perror("execution error");
		exit(EXIT_FAILURE);
	}
}

void	parent(int *f, int *p, char **argv, int pid)
{
	if (!argv[3][0])
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("command '' not found\n");
	}
	waitpid(pid, NULL, WNOHANG);
	close(p[1]);
	dup2(p[0], STDIN_FILENO);
	dup2(f[1], STDOUT_FILENO);
}

void	child(int *f, int *p, char **argv, char **envp)
{
	if (access(argv[1], R_OK) != 0)
	{
		perror("infile");
		exit(1);
	}
	close(p[0]);
	dup2(f[0], STDIN_FILENO);
	dup2(p[1], STDOUT_FILENO);
	if (!argv[2][0])
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("Command '' not found\n");
	}
	execute(argv[2], envp);
}

void	pipex(int *f, int *p, char **argv, char **envp)
{
	int	pid;

	if (pipe(p) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid == 0)
		child(f, p, argv, envp);
	else
	{
		if (f[1] == -1)
		{
			perror("outfile");
			exit(1);
		}
		parent(f, p, argv, pid);
		execute(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	f[2];
	int	p[2];

	if (argc == 5)
	{
		f[0] = open(argv[1], O_RDONLY, 0644);
		f[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		pipex(f, p, argv, envp);
	}
	else
	{
		perror("wrong number of arguments");
		exit(1);
	}
	return (0);
}
