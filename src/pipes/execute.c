#include "minishell.h"

int		ft_execute(char **env, char **argv)
{
	execve(path, argv, env);
}