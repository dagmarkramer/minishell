#ifndef LEXER_H
# define LEXER_H

#	include "libft.h"
#	include "minishell.h"

typedef struct	s_pipe
{
	bool	pipe_before;
	bool	pipe_after;
	int		input_fd;
	int		output_fd;
	char	**tokens;
	int		pipe_fd[2];
}				t_pipe;

#endif