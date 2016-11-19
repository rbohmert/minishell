/ * ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 22:39:24 by rbohmert          #+#    #+#             */
/*   Updated: 2016/05/19 03:16:09 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_builtins(char *name)
{
	char *builtins;

	builtins = "cd;unsetenv;setenv;exit";
	if (ft_strstr(builtins, name) && name)
		return (1);
	return (0);
}

void	exec_builtins(char *name, char **arg, char **env)
{
	if (!(ft_strcmp(name, "cd")))
		cd(arg, env);
	if (!(ft_strcmp(name, "setenv")))
		ft_setenv(arg, env);
	if (!(ft_strcmp(name, "unsetenv")))
		ft_unsetenv(arg, env);
	if (!(ft_strcmp(name, "exit")))
		exit(2);
}

void cd(char **arg, char **env)
{
 	if (arg[1] == NULL)
	{
		if (!chdir(get_env(env, "HOME=")))
		{
			ft_strcpy(get_env(env, "OLDPWD="), get_env(env, "PWD="));
			ft_strcpy(get_env(env, "PWD="), get_env(env, "HOME="));
		}
		else 
			printf("impossible mamene");
	}
	else
	{
		if (!chdir(arg[1]))
		{
			ft_strcpy(get_env(env, "OLDPWD="), get_env(env, "PWD="));
			ft_strcpy(get_env(env, "PWD="), arg[1]);
		}
		else
			printf("impossible mamene");
	}
}

void ft_setenv(char **arg, char **env)
{
	int i;
	int j;
	char **nenv;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	if (!(nenv = (char **)malloc((i + 1) * sizeof(char *))))
		exit(2);
	bzero(nenv, (i + 1) * sizeof(char *));
	while 
	
 env = env;
	ft_putstr("setennnnnnnnvvvee");
}

void ft_unsetenv(char **arg, char **env)
{
 arg = arg;
 env = env;
	ft_putstr("unsetenvvvvv");
}
