#ifndef LEXER_H
# define LEXER_H

#	include "libft.h"
#	include "minishell.h"

typedef struct	s_pipe
{
	int	pipe_before;
	int	pipe_after;
	int		input_fd;
	int		output_fd;
	char	**tokens;
	int		pipe_fd[2];
}				t_pipe;

int	ms_lstadd_pipe(t_list **pipes, int pipebefore, int pipeafter);

#endif