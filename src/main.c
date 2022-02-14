#include "../headers/minishell.h"
// #  include <stdio.h>
// #  include <readline/readline.h>
// #  include <readline/history.h>
// d

void	error_handling(char *errormessage, t_mini *mini)
{
	perror(errormessage);
	exit(EXIT_FAILURE);
}

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

