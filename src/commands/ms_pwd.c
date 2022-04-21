#include "minishell.h"

void	ms_pwd(char **array)
{
	char buf[PATH_MAX];

	if (ft_strncmp(array[0], "pwd", 4) != 0)
		return ;
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
}
