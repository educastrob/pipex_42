/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:56:06 by edcastro          #+#    #+#             */
/*   Updated: 2023/11/15 21:11:08 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	is_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	cant_find_cmd(int fd, int *pipefd, char **cmd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	free_strs(cmd);
	write(2, "Command not found\n", 18);
	exit(EXIT_FAILURE);
}