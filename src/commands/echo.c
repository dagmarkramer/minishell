#include "minishell.h"

// void	ms_echo(t_mini *mini)
// {
// 	int	i;
// 	int	a;
	
// 	a = 0;
// 	if (!ft_strncmp(mini->splitin[1], "-n", ft_strlen(mini->splitin[1])))
// 	{
// 		i = 2;
// 		while (mini->splitin[i])
// 		{
// 			if (!getenv(&mini->splitin[i][a + 1]))
// 			{
// 				printf("%s", mini->splitin[i]);
// 				if (mini->splitin[i + 1])
// 					printf(" ");
// 			}
// 			else
// 			{
// 				printf("%s", getenv(&mini->splitin[i][a + 1]));
// 				if (mini->splitin[i + 1])
// 					printf(" ");
// 			}
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		i = 1;
// 		while (mini->splitin[i])
// 		{
// 			if (!getenv(&mini->splitin[i][a + 1]))
// 			{
// 				printf("%s", mini->splitin[i]);
// 				if (mini->splitin[i + 1])
// 					printf(" ");
// 			}
// 			else
// 			{
// 				printf("%s", getenv(&mini->splitin[i][a + 1]));
// 				if (mini->splitin[i + 1])
// 					printf(" ");
// 			}
// 			i++;
// 		}
// 		printf("\n");
// 	}
// 	free2darr(mini);
// }

void	eo_printarray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		write(1, array[i], ft_strlen(array[i]));
		if (array[i +1] != NULL)
			write(1, " ", 1);
		i++;
	}
}

void	ms_echo(char **array)
{
	int	i;
	int	p;

	i = 0;
	p = 1;
	if (ft_strncmp(array[0], "echo", 5) != 0)
		return ;
	if (array[1] && array[1][0] == '-' && array[1][1] == 'n')
	{
		p = 2;
		while (array[1][i])
			if (array[1][i] != 'n')
				p = 1;
		i++;
	}
	if (p == 1)
	{
		eo_printarray(&array[1]);
		write(1, "\n", 1);
	}
	else
		eo_printarray(&array[1]);
	free2darr(array);
}
