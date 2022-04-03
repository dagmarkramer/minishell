#include "minishell.h"

void	error_handling(char *errormessage)
{
	perror(errormessage);
}

void	perror_handling(char *err_msg)
{
	error_handling(err_msg);
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

void	ms_next(t_mini *mini)
{
	//return error check
	if (!ft_strncmp(mini->input, "env", ft_strlen("env"))) // plus 1? for null terminator '\0'
		ms_env(mini);
	if (!ft_strncmp(mini->input, "export", ft_strlen("export")))
		ms_export(mini);
	if (!ft_strncmp(mini->input, "unset", ft_strlen("unset")))
		ms_unset(mini);
	if (!ft_strncmp(mini->input, "echo", ft_strlen("echo")))
		ms_echo(mini);
	if (!ft_strncmp(mini->input, "pwd", ft_strlen("pwd")))
		ms_pwd(mini);
	if (!ft_strncmp(mini->input, "cd", ft_strlen("cd")))
		ms_cd(mini);
	// if (!ft_strncmp(mini->splitin[0], "<", ft_strlen(mini->splitin[0])))
	// 	ms_redirect(mini, "<");
	// if (!ft_strncmp(mini->splitin[0], ">", ft_strlen(mini->splitin[0])))
	// 	ms_redirect(mini, ">");
	// if (!ft_strncmp(mini->splitin[0], ">>", ft_strlen(mini->splitin[0])))
	// 	ms_redirect(mini, ">>");
}

void	ms_print_word(void *ptr)
{
	t_token	*token;

	token = (t_token *)ptr;
	printf("%s\n", token->word);
}

void	ms_one_row(t_mini *data)
{
	t_list	*tokens;

	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input, data->env);
	if (tokens == NULL)
		return ;
	ft_lstiter(tokens, ms_print_word);
}

int	ms_init(t_mini *mini, int argc, char **argv, char **newenv)
{
	(void)argv;
	mini->input = NULL;
	mini->environ = newenv;
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.\n");
		return (1);
	}
	mini->env = ev_init_env(newenv);
	if (mini->env == NULL)
		return (1);
	ms_signals();
	return (0);
}

void	ms_exit(t_mini *mini)
{
	ft_lstclear(&mini->env, ev_del_keyval);
	rl_clear_history();
	printf("exit\n");
}

int	main(int argc, char **argv, char **newenv)
{
	t_mini	mini;

	if (ms_init(&mini, argc, argv, newenv))
		return (1);
	while (1)
	{
		mini.input = readline("Oud Getrouwd Shell : ");
		if (mini.input == 0 || !ft_strncmp(mini.input, "exit", 5))
			break ;
		if (mini.input[0] != 0)
		{
			add_history(mini.input);
			ms_one_row(&mini);
			ms_next(&mini);
		}
	}
	ms_exit(&mini);
	return (0);
}
