/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:07 by edcastro          #+#    #+#             */
/*   Updated: 2023/11/15 18:02:27 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	pid_t	pid;
	int		pipefd[2];
	char	buf;

	pipe(pipefd[2]);
	pid = fork();
	if (av != 5)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[1], STDOUT_FILENO);
	}
	
	
}