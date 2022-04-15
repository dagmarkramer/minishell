#include "minishell.h"

<<<<<<< HEAD
// void	find_redirects(char **new, t_mini *mini)
// {
// 	(void)mini;
// 	// printf("%s\n", new[0]);
// 	int	i;

// 	i = 0;
// 	while (new[i])
// 	{
// 		// if (ft_strncmp(new[i], ">", 1))
// 		// 	mini->input_fd = new[i + 1];
// 		i++;
// 	}
// }


int ms_parser(t_list **tokens, t_mini *mini)
=======
t_list	*ms_parser(t_list **tokens, t_mini *mini)
>>>>>>> c75b4e502017c5e6c01df71a3a9939c0fb30828b
{
	t_list *pipes;
	int     i;
	char    **new;
	
	i = 0;
	pipes = 0;
	mini->pipe_before = 0;
<<<<<<< HEAD
	mini->pipe_after = 0;
=======
	mini->pipe_after = 0; // changed to 1 from 0 for stdout instead of stdin
	// mini->tokenarr = malloc(sizeof(char *) * (10 + 1));
>>>>>>> c75b4e502017c5e6c01df71a3a9939c0fb30828b
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
<<<<<<< HEAD
	ft_printpipes(pipes);
	return (0);
=======
	// ft_printpipes(pipes);
	return (pipes);
>>>>>>> c75b4e502017c5e6c01df71a3a9939c0fb30828b
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