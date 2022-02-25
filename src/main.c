#include "minishell.h"

void	error_handling(char *errormessage)
{
	perror(errormessage);
}

void	free2darr(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->splitin[i])
	{
		free (mini->splitin[i]);
		i++;
	}
	free (mini->splitin);
}

void	ms_redirect(t_mini *mini, char *c)
{
	int	fd;
	// struct stat *buf;
	// int	ret;
	// int	i;
	// char	*line;

	(void)mini;
	if (!ft_strncmp(">>", c, ft_strlen("c")))
	{
		fd = open("outfile", O_WRONLY | O_APPEND);
		if (fd == -1)
			error_handling("outfile");
		if (dup2(fd, 0) == -1)
			error_handling("dup2() error");
	}
	else if (!ft_strncmp("<", c, ft_strlen("c")))
	{
		printf("hi");
		fd = open("infile", O_RDONLY);
		if (fd == -1)
			error_handling("infile");
		if (dup2(fd, 1) == -1)
			error_handling("dup2() error");
	}
	else if (!ft_strncmp(">", c, ft_strlen("c")))
	{
		printf("hi2");
		fd = open("outfile",  O_WRONLY | O_CREAT, 0666);
		if (fd == -1)
			error_handling("outfile");
		if (dup2(fd, 0) == -1)
			error_handling("dup2() error");
	}

	free2darr(mini);
	
}

void	ms_next(t_mini *mini, char **newenv)
{

	// function [] = {
	// 	"echo" = &ms_ech(mini);
	// 	"pwd" = dhhd;
	// 	int i;
	// 	while()
	// }
		mini->splitin = ft_split(mini->input, ' ');
		if (!ft_strncmp(mini->splitin[0], "echo", ft_strlen(mini->splitin[0])))
		{
			ms_echo(mini, newenv);
			return ;
		}
		// if (!ft_strncmp(mini->splitin[0], "pwd", ft_strlen(mini->splitin[0])))
		// 	ms_pwd(mini);
		// if (!ft_strncmp(mini->splitin[0], "cd", ft_strlen(mini->splitin[0])))
		// 	ms_cd(mini);
		// if (!ft_strncmp(mini->splitin[0], "export", ft_strlen(mini->splitin[0])))
		// 	ms_export(mini);
		// if (!ft_strncmp(mini->splitin[0], "unset", ft_strlen(mini->splitin[0])))
		// 	ms_unset(mini);
		// if (!ft_strncmp(mini->splitin[0], "env", ft_strlen(mini->splitin[0])))
		// 	ms_env(mini);
		// if (!ft_strncmp(mini->splitin[0], "exit", ft_strlen(mini->splitin[0])))
		// 	ms_exit(mini);
		// if (!ft_strncmp(mini->splitin[0], "<", ft_strlen(mini->splitin[0])))
		// 	ms_redirect(mini, "<");
		// if (!ft_strncmp(mini->splitin[0], ">", ft_strlen(mini->splitin[0])))
		// 	ms_redirect(mini, ">");
		if (!ft_strncmp(mini->splitin[0], ">>", ft_strlen(mini->splitin[0])))
			ms_redirect(mini, ">>");
}

int	main(int argc, char **argv, char **newenv)
{
	t_mini	mini;

	(void)argv;
	mini.input = NULL;
	mini.environ = newenv;
	ms_signals();
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.\n");
		return (1);
	}
	while (1)
	{
		mini.input = readline("Oud Getrouwd Shell : ");
		if (mini.input == 0 || !ft_strncmp(mini.input, "exit", 5))
			break ;
		if (mini.input[0] != 0)
		{
			add_history(mini.input);
			ms_next(&mini, newenv);
		}
	}
	rl_clear_history();
	printf("exit\n");
	return (0);
}