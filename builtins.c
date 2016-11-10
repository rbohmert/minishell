/* ************************************************************************** */
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
	if (ptr = ft_strstr(builtins, name) && name)
		return (1);
	return (0);
}

void	exec_builtins(char *name)
{
	if (name == "cd")
		cd();
	if (name == "setenv")
		ft_setenv();
	if (name == "unsetenv")
		ft_unsetenv();
	if (name == "exit")
		exit(2);
}

void cd()
{
	ft_putstr("cddddddddd");
}

void ft_setenv()
{
	ft_putstr("setennnnnnnnvvvee");
}

void ft_unsetenv()
{
	ft_putstr("unsetenvvvvv");
}
