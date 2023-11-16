/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:04:35 by edcastro          #+#    #+#             */
/*   Updated: 2023/11/15 23:49:12 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

//paths
char	**get_paths(char **envp);
char	*path(char **envp, char *cmd);

// utils
void	free_strs(char **strs);
void	is_error(char *str);
void	cant_find_cmd(int fd, int *pipefd, char **cmd);

#endif