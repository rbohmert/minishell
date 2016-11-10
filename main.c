#include "minishell.h"

char **getpath(char **env)
{
	int i;
	
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_strsplit(env[i] + 5, ':'));
	}
	return (NULL);
}

char *join_path(char *s1, char *s2)
{
	char *s;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	ft_strcpy(s, s1);
	ft_strcat(s, "/");
	ft_strcat(s, s2);
	return (s);
}
	
char *check(char **dir, char *name)
{
	int i;
	char *path;

	i = -1;
	while (dir[++i])
	{
		path = join_path(dir[i], name);
		if (!access(path, F_OK))
			return (path);
		free(path);
	}
	if (check_builtins(name))
		return (name);
	return (NULL);
}

void exe_com(char *name, char **arg, char **env)
{
	pid_t pid;

	if (name[0] != '/')
		exec_builtins(name);
	else
	{
		pid = fork();
		if (pid < 0)
			printf("fork fail \n");
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
int main(int ac, char **ag, char **env)
{
	char *line;
	char **ltab;

	ft_putstr("#>");
	while (get_next_line(0, &line))
	{
		ltab = ft_strsplit(line, ' ');
		if (!(line = check(getpath(env), ltab[0])))
			printf("la commande n'existe pas\n");
		else 
			exe_com(line, ltab, env);
		ft_putstr("#>");
	}
	return 0;
}
