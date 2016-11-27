/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:09:58 by rbohmert          #+#    #+#             */
/*   Updated: 2016/11/27 17:54:33 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/get_next_line.h"

char	*check(char **dir, char *name);
void	exe_com(char *file, char **arg, char **env);

void	exec_builtins(char *name, char **arg, char **env);
void	cd(char **arg, char **env);
void	add_env(char **arg, char **env, int ac);
void	ft_setenv(char **arg, char **env);
void	ft_unsetenv(char **arg, char **env);

int		check_builtins(char *name);
void	ptabstr(char **str);
char	*get_env(char **env, char *key);
char	*join_path(char *s1, char *s2);
void	strtrim(char **str);

void 	ft_env(char **arg, char **env);
#endif
