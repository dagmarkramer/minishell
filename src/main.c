#include "minishell.h"

void	error_handling(char *errormessage)
{
	perror(errormessage);
	exit(EXIT_FAILURE);
}

void	ms_next(t_mini *mini)
{

	// function [] = {
	// 	"echo" = &ms_ech(mini);
	// 	"pwd" = dhhd;
	// 	int i;
	// 	while()
	// }
		mini->splitin = ft_split(mini->input, ' ');
		if (!ft_strncmp(mini->splitin[0], "echo", ft_strlen(mini->splitin[0])))
			ms_echo(mini);
		if (!ft_strncmp(mini->splitin[0], "pwd", ft_strlen(mini->splitin[0])))
			ms_pwd(mini);
		if (!ft_strncmp(mini->splitin[0], "cd", ft_strlen(mini->splitin[0])))
			ms_cd(mini);
		if (!ft_strncmp(mini->splitin[0], "export", ft_strlen(mini->splitin[0])))
			ms_export(mini);
		if (!ft_strncmp(mini->splitin[0], "unset", ft_strlen(mini->splitin[0])))
			ms_unset(mini);
		if (!ft_strncmp(mini->splitin[0], "env", ft_strlen(mini->splitin[0])))
			ms_env(mini);
		if (!ft_strncmp(mini->splitin[0], "exit", ft_strlen(mini->splitin[0])))
			ms_exit(mini);
		free(mini->splitin[0]);
		free(mini->splitin);
}

int	main(int argc, char **argv, char **newenv)
{
	t_mini	mini;

	(void)argv;
	(void)newenv;
	mini.input = NULL;
	rl_catch_signals = 0;
	signals();
	mini.environ = newenv;
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.\n");
		return (1);
	}
	while (1)
	{
		mini.input = readline("Oud Getrouwd Shell : ");
		if (mini.input == 0)
			break ;
		if (mini.input[0] != 0)
			ms_next(&mini);
	}
	printf("\b\bexit\n");
	return (0);
}