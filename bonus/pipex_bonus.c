/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:16:07 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/11 18:30:44 by educastro        ###   ########.fr       */
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

int	main(int ac, char **av, char **envp)
{
	t_pipex	d;

	d = init(ac, av);
	return (0);
}