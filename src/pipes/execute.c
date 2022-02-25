#include "minishell.h"

int		ft_execute(char **env, char *path, char **argv)
{
	execve(path, argv, env);
}