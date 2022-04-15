#include "minishell.h"

int		count_words(t_list *tokens)
{
	int	words;

	words = 0;
	if (((t_token *)tokens->content)->id == Pipe)
		tokens = tokens->next;
	while (tokens)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			break ;
		if (((t_token *)tokens->content)->id == Heredoc || ((t_token *)tokens->content)->id == Write || ((t_token *)tokens->content)->id == Read || ((t_token *)tokens->content)->id == Append)
		{
			tokens = tokens->next;
			if (tokens->next)
				tokens = tokens->next;
		}
		words++;
		tokens = tokens->next;
	}
	return (words);
}

char	**get_args_exec(t_list *tokens)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (count_words(tokens) + 1));
	if (((t_token *)tokens->content)->id == Pipe)
		tokens = tokens->next;
	while (new[i] && tokens)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			break ;
		if (((t_token *)tokens->content)->id == Heredoc || ((t_token *)tokens->content)->id == Write || ((t_token *)tokens->content)->id == Read || ((t_token *)tokens->content)->id == Append)
		{
			tokens = tokens->next;
			if (tokens->next)
				tokens = tokens->next;
		}
		new[i] = ft_strdup(((t_token *)tokens->content)->word);
		if (!new[i])
			ft_disruptive_exit("malloc fail", 333);
		tokens = tokens->next;
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	parser_init(t_pipe *pipe, t_mini *mini, char **tokenarr)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	(pipe)->pipe_before = mini->pipe_before;
	(pipe)->pipe_after = mini->pipe_after;
	(pipe)->tokens = tokenarr;
}

int	ms_lstadd_pipe(t_list **pipes, t_mini *mini, char **tokenarr)
{
	t_list	*new;
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (pipe == NULL)
		ft_disruptive_exit("malloc fail", 333);
<<<<<<< HEAD
	parser_init(pipe, mini, tokenarr);
=======
	parser_init(&pipe, mini, tokenarr); // we can spit this up by calling this after lstaddpipe so this funciton does not need t_mini
>>>>>>> c75b4e502017c5e6c01df71a3a9939c0fb30828b
	new = ft_lstnew((void *)pipe);
	if (new == NULL)
	{
		free(pipe);
		ft_disruptive_exit("malloc fail", 333);
	}
	ft_lstadd_back(pipes, new);
	return (0);
}