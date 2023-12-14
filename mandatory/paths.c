/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:33:35 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/14 02:08:03 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	paths = get_paths(envp);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoinf(path, cmd);
		if (!access(path, F_OK))
		{
			free_strs(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_strs(paths);
	return (0);
}
