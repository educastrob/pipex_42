/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:04:35 by edcastro          #+#    #+#             */
/*   Updated: 2023/12/14 02:13:49 by edcastro         ###   ########.fr       */
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

// here_doc_bonus.c
void	here_doc(char *delimiter, int ac);

// paths_bonus.c
char	*get_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

// utils_bonus.c
void	free_strs(char **strs);
void	is_error(char *str);
void	usage(void);

#endif