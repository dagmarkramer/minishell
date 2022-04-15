#include "minishell.h"

t_list	*ms_parser(t_list **tokens, t_mini *mini)
{
	t_list *pipes;
	int     i;
	char    **new;
	
	i = 0;
	pipes = 0;
	mini->pipe_before = 0;
	mini->pipe_after = 0;
	if (mini->pipes > 0)
		mini->pipe_after = 1;
	new = get_args_exec((*tokens));
	if (!new)
		ft_disruptive_exit("malloc fail", 333);
	ms_lstadd_pipe(&pipes, mini, new);
	printf("pipes%d\n", mini->pipe_after);
	// find_redirects(new, mini);
	while ((*tokens) && (*tokens)->next)
	{
		if (((t_token *)(*tokens)->content)->id == Pipe)
		{
			i++;
			if (mini->pipes - i > 0)
				mini->pipe_after = 1;
			mini->pipe_before = 1;
			new = get_args_exec((*tokens));
			if (!new)
				ft_disruptive_exit("malloc fail", 333);
			// find_redirects(new, mini);
			ms_lstadd_pipe(&pipes, mini, new);
		}
		mini->pipe_after = 0;
		(*tokens) = (*tokens)->next;
	}
	ft_printpipes(pipes);
	return (0);
}

void	ms_count(t_list *tokens, t_mini *mini)
{
	mini->pipes = 0;
	// mini->tokens = 1;
	while (tokens && tokens->next)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			mini->pipes++;
		// mini->tokens++;
		tokens = tokens->next;
	}
}