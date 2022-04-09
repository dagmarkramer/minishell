#include "minishell.h"

char	*environment_variables(t_mini *mini)
{
	char	*str;
	int	i;
	int	a;

	i = 1;
	a = 0;
	str = getenv(&mini->splitin[i][a + 1]);//getenv from after $ sign
	if (!str)
		return (NULL);
	return (str);
}

// relative path: the hierarchical path that locates a file or folder on a file system starting from the current directory
// absolute path: the complete details needed to locate a file or folder
