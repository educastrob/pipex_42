/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:07 by edcastro          #+#    #+#             */
/*   Updated: 2023/11/08 17:43:59 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	pid_t	pid;
	int		pipefd[2];
	char	buf;

	
	if (ac != 5)
	{
		fprintf(stderr, "invalid arguments");
		return (1);
	}
	
}