#include "minishell.h"

void	ms_print_word(void *ptr)
{
	t_token	*token;

	token = (t_token *)ptr;
	printf("%s\n", token->word);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	return(ft_strncmp(s1, s2, 1 + (size_t)ft_strlen(s2)));
}

// echo cd pwd export unset env exit
int	is_buildin(char *command)
{
	return (!ft_strcmp(command, "echo") || !ft_strcmp(command, "cd")
		|| !ft_strcmp(command, "pwd") || !ft_strcmp(command, "export")
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "env")
		|| !ft_strcmp(command, "exit"));
}

// link the buildin functions with if statements
int	exe_buildin(t_execute *info, t_mini *data)
{
	if (ft_strcmp(info->arg[0], "echo") == 0)
		ms_echo(info->arg);
	if (ft_strcmp(info->arg[0], "cd") == 0)
		ms_cd(info->arg);
	if (ft_strcmp(info->arg[0], "env") == 0)
		ms_env(data, info->arg);
	if (ft_strcmp(info->arg[0], "exit") == 0)
		ms_exit(info->arg);
	if (ft_strcmp(info->arg[0], "export") == 0)
		ms_export(data, info->arg);
	if (ft_strcmp(info->arg[0], "pwd") == 0)
		ms_pwd(info->arg);
	if (ft_strcmp(info->arg[0], "unset") == 0)
		ms_unset(data);
	return (0);
}

int	exe_pre_buildin(t_pipe *pipe, t_mini *data)
{
	t_execute	info;
	int			tmp;

	exe_pipe_to_execute(pipe, &info, data);
	info.arg = fd_redirections(&info);
	tmp = exe_buildin(&info, data);
	return (tmp);
}

int	exe_pipe_and_run(t_list *pipes, t_mini *data)
{
	int	pipefd[2];
	int	child_exit;

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
	// make the last pipe go brrrrr with last pipe read end 
	// needs NULL pointer protection?
	child_exit = exe_pre_fork((t_pipe *)pipes->content, data);
	return (child_exit);
}

void	ms_line_executer(t_mini *data)
{
	t_list	*tokens;
	t_list	*pipes;

	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input, data->env);
	if (tokens == NULL)
		return ;
	// tk_expand_all(tokens, data->env);
	ft_lstiter(tokens, tk_remove_quotes);
	// ft_lstiter(tokens, ms_print_word);
	if (ms_lexer(tokens) == 0)
	{
		ft_lstclear(&tokens, ms_del_token);
		return ;
	}
	ms_count(tokens, data);
	// if (data->pipes == 0)
	// 	ex_nopipes();
	pipes = ms_parser(&tokens, data);
	exe_pipe_and_run(pipes, data);
	// go to execution
	// free everything in the linked token list
	ft_lstclear(&tokens, ms_del_token);
}
