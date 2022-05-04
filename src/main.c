#include "minishell.h"

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
	mini->save_in = dup(0);
	mini->save_out = dup(1);
	return (0);
}

void	ms_exit_cleanup(t_mini *mini)
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
		mini.input = readline("\033[38:5:208mOud Getrouwd Shell : \033[0;0m");
		if (mini.input == 0)
			break ;
		if (mini.input[0] != 0)
		{
			add_history(mini.input);
			ms_line_executer(&mini);
			// system("leaks minishell");
		}
	}
	ms_exit_cleanup(&mini);
	return (0);
}
