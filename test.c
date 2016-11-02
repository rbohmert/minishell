#include <stdio.h>
#include <unistd.h>
#include "libft/get_next_line.h"

char *getpath(char **env)
{
	int i;
	
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (strdup(&env[i][5]));
	}
	return (NULL);
}
	
int main(int ac, char **ag, char **env)
{
	char *s;

	printf("%s\n", getpath(env));
	get_next_line(0, &s);
	return 0;
}
