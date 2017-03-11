/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:09:58 by rbohmert          #+#    #+#             */
/*   Updated: 2016/12/03 21:05:42 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft/get_next_line.h"

char	*check(char **dir, char *name, int no_built);
void	exe_com(char *file, char **arg, char **env);
void	verif_line(char *str, char **env);

void	exec_builtins(char *name, char **arg, char **env);
void	cd(char **arg, char **env);
void	ft_unsetenv(char **arg, char **env);
void	echo(char **arg);

void	add_env(char **arg, char **env, int ac);
void	ft_setenv(char **arg, char **env);

int		check_builtins(char *name);
char	*get_env(char **env, char *key);
char	*join_path(char *s1, char *s2);
void	strtrim(char **str);

char	**cp_env(char **env);
void	clr_env(char **nenv);
void	add_key(char *str, char **nenv);
void	env_opt(char **arg, char **nenv, int *i);
void	ft_env(char **arg, char **env);
#endif
