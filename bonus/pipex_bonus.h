/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educastro <educastro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:39:29 by educastro         #+#    #+#             */
/*   Updated: 2023/12/11 17:30:26 by educastro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# define READ 0
# define WRITE 1

typedef struct	s_pipex
{
	int		nb_cmds;
	int		fd[2];
	int		pipe_a[2];
	int		pipe_b[2];
	int		here_doc;
	pid_t	pid;
	char	**cmd;
	char	*path;
	int		index;
}				t_pipex;

// paths_bonus.c
char	**get_paths(char **envp);
char	*path(char **envp, char *cmd);

// utils_bonus.c
void	is_error(char *str, t_pipex *d);
void	free_strs(char **strs);
void	cant_find_cmd(char **cmd, t_pipex *d);
void	close_all(t_pipex *d);
void	closefd(t_pipex *d);

#endif