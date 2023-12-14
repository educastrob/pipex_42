/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:07 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/14 02:08:33 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_and_close(int fd, int *pipefd, int process)
{
	if (process == 1)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fd);
	}
	else if (process == 2)
	{
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		close(fd);
	}
}

void	child_one(int *fd, int *pipefd, char **av, char **envp)
{
	pid_t	pid;
	char	*cmd_path;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		is_error("Fork error");
	if (pid == 0)
	{
		fd[0] = open(av[1], O_RDONLY);
		if (fd[0] < 0)
			is_error(av[1]);
		cmd = ft_split(av[2], ' ');
		cmd_path = path(envp, cmd[0]);
		if (cmd[0] != NULL && cmd_path)
		{
			dup_and_close(fd[0], pipefd, 1);
			execve(cmd_path, cmd, envp);
		}
		else
		{
			free(cmd_path);
			cant_find_cmd(fd[0], pipefd, cmd);
		}
	}
}

void	child_two(int *fd, int *pipefd, char **av, char **envp)
{
	pid_t	pid;
	char	*cmd_path;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		is_error("Fork error");
	if (pid == 0)
	{
		fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			is_error(av[4]);
		cmd = ft_split(av[3], ' ');
		cmd_path = path(envp, cmd[0]);
		if (cmd[0] != NULL && cmd_path)
		{
			dup_and_close(fd[1], pipefd, 2);
			execve(cmd_path, cmd, envp);
		}
		else
		{
			free(cmd_path);
			cant_find_cmd(fd[1], pipefd, cmd);
		}
	}
}

void	pipex_process(int *fd, int *pipefd, char **av, char **envp)
{
	child_one(fd, pipefd, av, envp);
	child_two(fd, pipefd, av, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pipefd[2];

	if (ac != 5)
	{
		ft_putendl_fd("Wrong arguments, try: ./pipex file1 cmd1 cmd2 file2", 2);
		return (0);
	}
	if (!envp || envp[0][0] == '\0')
		is_error("Envp error");
	if (pipe(pipefd) < 0)
		is_error("Pipefd error");
	pipex_process(fd, pipefd, av, envp);
	return (0);
}
