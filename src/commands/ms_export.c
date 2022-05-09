#include "minishell.h"

void	ms_export(t_mini *mini, char **array)
{
	char	**exportvar;
	int		i;

	i = 1;
	ev_sort_alfa(mini->env);
	while (array[i] != NULL)
	{
		exportvar = ft_split(array[i], '=');
		if (!exportvar)
			ft_disruptive_exit("malloc fail", 333);
		if (ev_change_env(exportvar[0], exportvar[1], &mini->env))
			ft_disruptive_exit("malloc fail", 333);
		i++;
	}
	if (array[1] == NULL)
		ft_printlst(mini->env, "export");
}
