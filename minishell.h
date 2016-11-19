#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/get_next_line.h"

char *get_env(char **env, char *key);
char *join_path(char *s1, char *s2);
char *check(char **dir, char *name);
void exe_com(char *file, char **arg, char **env);
int		check_builtins(char *name);
void	exec_builtins(char *name, char **arg, char **env);
void	cd(char **arg, char **env);
void	ft_setenv(char **arg, char **env);
void	ft_unsetenv(char **arg, char **env);
#endif
