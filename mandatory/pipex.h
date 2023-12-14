/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:04:35 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/14 02:13:10 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include <sys/stat.h> // open access
# include <fcntl.h> // open access
# include <unistd.h> // open close read write access dup dup2 execve fork pipe
# include <sys/types.h> // fork waitpid
# include <sys/wait.h> // waitpid
# include <stdio.h> // perror
# include <errno.h> // perror
# include <stdlib.h> // free
# include <string.h> // strerror

// paths.c
char	**get_paths(char **envp);
char	*path(char **envp, char *cmd);

// utils.c
void	free_strs(char **strs);
void	is_error(char *str);
void	cant_find_cmd(int fd, int *pipefd, char **cmd);

#endif