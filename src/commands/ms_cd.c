#include "minishell.h"

void	ms_cd(char **array)
{
	if (ft_strncmp(array[0], "cd", 3) != 0)
		return ;
	chdir(array[1]);
}
