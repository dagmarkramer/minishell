#include "minishell.h"

int	exe_pipe_and_run(t_list *pipes, t_mini *data)
{
	int	pipefd[2];

	if (pipes->next == NULL && is_buildin(((t_pipe *)pipes->content)->tokens[0]))
		return (exe_pre_buildin((t_pipe *)pipes->content, data));
	while(pipes->next != NULL)
	{
		if (pipe(pipefd) == -1)
			ft_disruptive_exit("pipe failed", 42);
		fd_replacer(&((t_pipe *)pipes->content)->output_fd, pipefd[1]);
		fd_replacer(&((t_pipe *)pipes->next->content)->input_fd, pipefd[0]);
		exe_pre_fork((t_pipe *)pipes->content, data);
		pipes = pipes->next;
	}
	return (exe_pre_fork((t_pipe *)pipes->content, data));
}

void	ms_line_executer(t_mini *data)
{
	t_list	*tokens;
	t_list	*pipes;

	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input, data->env);
	if (tokens == NULL)
		return ;
	ft_lstiter(tokens, tk_remove_quotes);
	if (ms_lexer(tokens) == 0)
	{
		ft_lstclear(&tokens, ms_del_token);
		return ;
	}
	pipes = ms_parser(&tokens);
	data->last_return = exe_pipe_and_run(pipes, data);
	if (data->last_return == 127)
		printf("\n");
	ft_lstclear(&tokens, ms_del_token);
}
