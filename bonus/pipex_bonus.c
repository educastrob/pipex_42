/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:07 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/13 14:15:34 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_pipex	init(int ac, char **av)
{
	t_pipex	d;

	d.here_doc = check_heredoc(av[1]);
	d.nb_cmds = ac - 3 - d.here_doc;
	if (d.here_doc == 1)
		here_doc(av[2], &d);
	else
	{
		d.fd[0] = open(av[1], O_RDONLY);
		if (d.fd[0] < 0)
			is_error("infile error", &d);
	}
	d.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d.fd[1] < 0)
		is_error("output error", &d);
	d.index = 0;
	return (d);
}

void	dup_io(t_pipex *d)
{
	if (d->index == 0)
	{
		dup2(d->fd[0], STDIN_FILENO);
		dup2(d->pipe_b[WRITE], STDOUT_FILENO);
	}
	else if (d->index == d->nb_cmds - 1)
	{
		dup2(d->fd[1], STDOUT_FILENO);
		if (d->index % 2 == 0)
			dup2(d->pipe_b[READ], STDIN_FILENO);
		else
			dup2(d->pipe_a[READ], STDIN_FILENO); 
	}
	else if (d->index % 2 == 0)
	{
		dup2(d->pipe_a[READ], STDIN_FILENO);
    	dup2(d->pipe_b[WRITE], STDOUT_FILENO);
	}
	else if (d->index % 2 != 0)
	{
		dup2(d->pipe_b[READ], STDIN_FILENO);
		dup2(d->pipe_a[WRITE], STDOUT_FILENO);
	}
}

void	child(t_pipex *d, char **envp)
{
	dup_io(d);
	close_all(d);
	if (d->cmg[0] != NULL && d->path)
		execve(d->path, d->cmd, envp);
	else
		cant_find_cmd(d->cmd, d);
}

void	start_process(t_pipex *d, char **argv, char **envp)
{
	pid_t pid;

	while (d->index < d->nb_cmds)
	{
		if (d->index % 2 == 0)
			if (pipe(d->pipe_b) < 0)
				is_error("Pipefd error", d);
		if (d->index % 2 != 0)
			if (pipe(d->pipe_a) < 0)
				is_error("Pipefd error", d);
		d->cmd = ft_split(argv[d->index + 2 + d->here_doc], ' ');
		d->path = path(envp, d->cmd[0]);
		pid = fork();
		if (pid < 0)
			is_error("Fork error", d);
		else if (pid == 0)
			child(d, envp);
		closefd(d);
		waitpid(pid, NULL, 0);
		free_strs(d->cmd);
		free(d->path);
		d->index++;
	}
	close_all(d);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	d;

	d = init(ac, av);
	start_process(&d, av, envp);
	return (0);
}