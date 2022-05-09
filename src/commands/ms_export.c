#include "minishell.h"

void	ms_export(t_mini *mini, char **array)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	ev_sort_alfa(mini->env);
	while (array[i] != NULL)
	{
		key = ft_strcdup(array[i], '=');
		ft_malloc_fail_check(key);
		value = ft_strdup(&array[i][ft_strclen(array[i], '=') + 1]);
		if (ev_change_env(key, value, &mini->env))
			ft_disruptive_exit("malloc fail", 333);
		i++;
	}
	if (array[1] == NULL)
		ft_printlst(mini->env, "export");
}
