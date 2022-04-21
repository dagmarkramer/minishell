#include "minishell.h"

void	ms_unset(t_mini *mini)
{
	char **split;
	char **exportvar;

	split = ft_split(mini->input, ' ');
	if (split[1])
	{
		exportvar = ft_split(split[1], '=');
		ev_rem_env(exportvar[0], &mini->env);
	}
}
