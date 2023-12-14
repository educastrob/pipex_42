/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:07 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/14 01:55:44 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		is_error("Pipe error!");
	pid = fork();
	if (pid == -1)
		is_error("Process error!");
	if (pid == 0)
	{
		close(fd[READ]);
		dup2(fd[WRITE], STDOUT_FILENO);
		execute(av, envp);
	}
	else
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			infile = open(av[1], O_RDONLY, 0777);
			dup2(infile, STDIN_FILENO);
		}
		while (i < ac - 2)
			child_process(av[i++], envp);
		dup2(outfile, STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	usage();
}
