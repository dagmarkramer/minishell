/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:45:02 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/11 15:34:14 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_disruptive_exit(char *exit_status, int exit_int)
{
	ft_putendl_fd(exit_status, 2);
	exit(exit_int);
}

void	ft_malloc_fail_check(void *status)
{
	if (status == NULL)
		ft_disruptive_exit("malloc fail", 333);
}

int	ms_init(t_mini *mini, int argc, char **newenv)
{
	mini->input = NULL;
	mini->environ = newenv;
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.\n");
		return (1);
	}
	mini->env = ev_init_env(newenv);
	if (!mini->env)
		ft_disruptive_exit("malloc fail", 333);
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

	(void)argv;
	if (ms_init(&mini, argc, newenv))
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
		}
	}
	ms_exit_cleanup(&mini);
	return (0);
}
