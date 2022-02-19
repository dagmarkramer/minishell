#include "minishell.h"

void	ms_echo(t_mini *mini)
{
	if (!ft_strncmp(mini->splitin[1], "-n", ft_strlen(mini->splitin[1])))
	{
		printf("%s", mini->splitin[2]);
		free (mini->splitin[1]);
		free (mini->splitin[2]);
	}
	else
	{
		printf("%s\n", mini->splitin[1]);
		free (mini->splitin[1]);
	}
}