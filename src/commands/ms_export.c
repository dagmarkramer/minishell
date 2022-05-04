#include "minishell.h"

void	ms_export(t_mini *mini, char **array)
{
	char **exportvar;

	ev_sort_alfa(mini->env);
	if (array[1])
	{
		exportvar = ft_split(array[1], '=');
		ev_change_env(exportvar[0], exportvar[1], &mini->env);
	}
	else
		ft_printlst(mini->env, "export");
}
