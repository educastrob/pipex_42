/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 01:33:36 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/14 02:06:58 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	writing_doc(char *delimiter, char *line, int *fd)
{
	close(fd[READ]);
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
			exit(EXIT_SUCCESS);
		ft_putstr_fd(line, fd[WRITE]);
		free(line);
	}
}

void	here_doc(char *delimiter, int ac)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	line = NULL;
	if (ac < 6)
		usage();
	if (pipe(fd) == -1)
		is_error("Pipe error!");
	reader = fork();
	if (reader == 0)
		writing_doc(delimiter, line, fd);
	else
	{
		close(fd[WRITE]);
		dup2(fd[READ], STDIN_FILENO);
		wait(NULL);
	}
}
