#include "minishell.h"

int	ms_lstadd_pipe(t_list **pipes, bool pipebefore)
{
	t_list	*new;
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (pipe == NULL)
		return (1);
	pipe->pipe_before = pipebefore;
	new = ft_lstnew((void *)pipe);
	if (new == NULL)
	{
		free(pipe);
		return (1);
	}
	ft_lstadd_back(pipes, new);
    printf("%d\n", (int)((t_pipe *)(* pipes)->content)->pipe_before);
	return (0);
}