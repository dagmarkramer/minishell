#include "minishell.h"

void	ms_unset(char **args, t_mini *mini)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		ev_rem_env(args[i], &mini->env);
		i++;
	}
}
