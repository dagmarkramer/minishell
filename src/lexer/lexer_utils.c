#include "minishell.h"

// int		count_words(char **array)
// {
// 	int	a;
// 	int	words;

// 	a = 0;
// 	words = 0;
// 	while (array[a])
// 	{
// 		if (ft_strncmp("|", array[a], 1))
// 			a++;
// 		if (ft_strncmp(">", array[a], 1) || ft_strncmp("<", array[a], 1) || ft_strncmp(">>", array[a], 1) || ft_strncmp("<<", array[a], 1))
// 		{
// 			a++;

// 			countwords
// 		}
// 	}
// }

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
	printf("%d\n", count_words(tokens));
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
		printf("%s\n", new[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	parser_init(t_pipe **pipe, t_mini *mini)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	(*pipe)->pipe_before = mini->pipe_before;
	(*pipe)->pipe_after = mini->pipe_after;
	(*pipe)->tokens = malloc(sizeof(char *) * (1 + 1));
	while (mini->tokenarr[i] && (*pipe)->tokens[a])
	{
		printf("|%s|\n", mini->tokenarr[i]);
		(*pipe)->tokens[a] = ft_strdup(mini->tokenarr[i]);
		if (!(*pipe)->tokens[a])
			ft_disruptive_exit("malloc fail", 333);
		i++;
		a++;
	}
}

int	ms_lstadd_pipe(t_list **pipes, t_mini *mini)
{
	t_list	*new;
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (pipe == NULL)
		ft_disruptive_exit("malloc fail", 333);
	parser_init(&pipe, mini);
	new = ft_lstnew((void *)pipe);
	if (new == NULL)
	{
		free(pipe);
		ft_disruptive_exit("malloc fail", 333);
	}
	ft_lstadd_back(pipes, new);
    // printf("%d\n", (int)((t_pipe *)(* pipes)->content)->pipe_before);
	return (0);
}