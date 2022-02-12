#include "minishell.h"
// #  include <stdio.h>
// #  include <readline/readline.h>
// #  include <readline/history.h>

int	main(int argc, char **newenv)
{
	char    *prompt;
	// int		i;

	// i = 0;
	t_mini mini;
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.");
		return (1);
	}
	while (1)
	{
		readline(prompt);
		getpathoptions(prompt, &mini, newenv);
	}

    // {
	
	// i++;
	// }


	return (0);
}