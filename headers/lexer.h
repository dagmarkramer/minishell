#ifndef LEXER_H
# define LEXER_H

#	include "libft.h"
#	include "minishell.h"

typedef struct	s_pipe
{
	bool	pipe_before; // where do we use this for now?
	bool	pipe_after; // i think is not needed
	int		input_fd; // 0
	int		output_fd;
	char	**tokens;
	int		pipe_fd[2]; // where do we use this now?
}				t_pipe;

#endif