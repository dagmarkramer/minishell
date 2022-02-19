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

int	main(int argc, char **argv, char **newenv)
{
	t_mini	mini;

	(void)argv;
	(void)newenv;
	mini.prompt = NULL;
	signals();
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.");
		return (1);
	}
	while (1)
	{
		mini.prompt = readline("hi");
		ms_echo(&mini);
		// getpathoptions(mini.prompt, &mini, newenv);
	}
	return (0);
}
