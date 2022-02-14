#include "minishell.h"
// #  include <stdio.h>
// #  include <readline/readline.h>
// #  include <readline/history.h>

int	main(int argc, char **newenv)
{
	char	*prompt;
	t_mini	mini;

	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.");
		return (1);
	}
	while (1)
	{
		printf("%s\n", readline(prompt));
		getpathoptions(prompt, &mini, newenv);
	}
	return (0);
}