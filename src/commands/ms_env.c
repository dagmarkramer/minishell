#include "minishell.h"

// void	ms_env(t_mini *mini)
// {
// 	ft_printlst(mini->env, "env");
// }

void	ms_env(t_mini *mini, char **array)
{
	if (ft_strncmp(array[0], "env", 4) != 0)
		return ;
	ft_printlst(mini->env, "env");
}
