#include "../headers/minishell.h"
// #  include <stdio.h>
// #  include <readline/readline.h>
// #  include <readline/history.h>
// d

void	error_handling(char *errormessage)
{
	perror(errormessage);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **newenv)
{
	t_mini	mini;

	mini.prompt = NULL;
	signals();
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.");
		return (1);
	}
	while (1)
	{
		printf("%s\n", readline(mini.prompt));
		getpathoptions(mini.prompt, &mini, newenv);
	}
	return (0);
}
