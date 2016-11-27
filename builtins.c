/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 22:39:24 by rbohmert          #+#    #+#             */
/*   Updated: 2016/11/27 19:32:15 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtins(char *name, char **arg, char **env)
{
	if (!(ft_strcmp(name, "cd")))
		cd(arg, env);
	if (!(ft_strcmp(name, "env")))
		ft_env(arg, env);
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
			printf("impossible mamene\n");
	}
	else
	{
		if (!chdir(arg[1]))
		{
			ft_strcpy(get_env(env, "OLDPWD="), get_env(env, "PWD="));
			ft_strcpy(get_env(env, "PWD="), arg[1]);
		}
		else
			printf("impossible mamene\n");
	}
}

void	add_env(char **arg, char **env, int ac)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	if (ac == 2)
		env[i] = ft_strjoin(arg[1], "=");
	else
		env[i] = ft_strjoin(ft_strjoin(arg[1], "="), arg[2]);
	env[i+1] = NULL;
}

void ft_setenv(char **arg, char **env)
{
	int ac;
	char *str;

	ac = 0;
	while (arg[ac])
		ac++;
	if (ac == 1)
		ptabstr(env);
	else if (ac > 3)
		ft_putendl("usage setenv: setnenv VAR VALUE");
	else
	{
		if (!(str = get_env(env, ft_strjoin(arg[1], "="))))
			add_env(arg, env, ac);
		else if (ac == 2)
			str[0] = 0;
		else
			ft_strcpy(str, arg[2]);
	}
}

void ft_unsetenv(char **arg, char **env)
{
	int ac;
	int i;

	ac = 0;
	i = 0;
	while (arg[ac])
		ac++;
	if (ac == 1)
		ptabstr(env);
	if (ac == 2 || !ft_strcmp(arg[0], "-u"))
	{
		while (env[i])
		{
			if (!ft_strncmp(env[i], arg[1], ft_strlen(arg[1])))
			{
				env[i] = NULL;
				while (env[++i])
					env[i - 1] = env[i];
				env[i - 1] = NULL;
			}
			i++;
		}
	}
}
