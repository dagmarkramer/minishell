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
		printf("Error\nDo not use arguments, a prompt will pop up.\n");
		return (1);
	}
	while (1)
	{
		mini.prompt = readline("Oud Getrouwd Shell :\t");
		if (mini.prompt == 0)
			break ;
		printf("%s\n", mini.prompt);
	}
	printf("\b\b  \b\bexit\n");
	return (0);
}
