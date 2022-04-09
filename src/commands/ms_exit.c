#include "minishell.h"

void	ms_exit(char **array)
{
	int	exitcode;
	int	errorcode;
	int	arraylen;

	errorcode = 0;
	arraylen = ft_arraylen((void *)array);
	if (arraylen > 2)
	{
		printf("OGS: exit: too many arguments\n");
		return ;
	}
	if (arraylen == 1)
		exit(0);
	exitcode = ph_atoi(array[1], &errorcode);
	if (errorcode != 0)
	{
		printf("OGS: exit: %s: numeric argument required\n", array[1]);
		exit(255);
	}
	exit(exitcode);
}
