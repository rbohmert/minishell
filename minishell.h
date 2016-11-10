#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/type.h>
# include <sys/wait.h>
# include "libft/get_next_line.h"

char **getpath(char **env);
char *join_path(char *s1, char *s2);
char *check(char **dir, char *name);
void exe_com(char *file, char **arg, char **env);
int		check_builtins(char *name);
void	exec_builtins(char *name);
void	cd();
void	ft_setenv();
void	ft_unsetenv();
#endif
