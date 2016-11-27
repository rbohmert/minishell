/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 19:09:49 by rbohmert          #+#    #+#             */
/*   Updated: 2016/11/27 20:17:56 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *check(char **env, char *name)
{
	int i;
	char *path;
	char **dir;

	i = -1;
	if (check_builtins(name))
		return (name);
	if (!access(name, F_OK))
		return (name);
	if (get_env(env, "PATH="))
		dir = ft_strsplit(get_env(env, "PATH="), ':');
	else
		dir = NULL;
	while (dir && dir[++i])
	{
		path = join_path(dir[i], name);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	return (NULL);
}

void exe_com(char *name, char **arg, char **env)
{
	pid_t pid;

	if (name[0] != '/' && name[0] != '.')
		exec_builtins(name, arg, env);
	else
	{
		pid = fork();
		if (pid < 0)
			printf("fork fail\n");
		else if (pid == 0)
		{
			execve(name, arg, env);
			printf("exec fail\n");
		}
		else
			waitpid(pid,0 ,0);
		return ;
	}
}

void verif_line(char *str, char **env)
{
	char **ltab;

	if (str[0])
	{	
		ltab = ft_strsplit(str, ' ');
		if (!(str = check(env, ltab[0])))
			printf("la commande n'existe pas\n");
		else 
			exe_com(str, ltab, env);
	}
}

int main(int ac, char **av, char **env)
{
	char *line;
	char **com_tab;
	int i;

	i = 0 * (int)(av[ac]);
	ft_putstr("#>");
	while (get_next_line(0, &line) && line)
	{
		strtrim(&line);
		com_tab = ft_strsplit(line, ';');
		while (com_tab[i])
			verif_line(com_tab[i++], env);
		free(com_tab);
		i = 0;
		ft_putstr("#>");
	}
	return 0;
}
