#ifndef MINISHELL_H
# define MINISHELL_H

// #  include <stdlib.h>
#  include <stdio.h>
#  include <readline/readline.h>
#  include <readline/history.h>
#  include <stdlib.h>
#  include "../Libft/libft.h"

typedef struct s_mini
{
	char	**split;
	char	*ls;
	char	*options;
	char	*path;
	char	**path2d;
	char	*prompt;
	// char	*hs;
	// char	*hs2;
	// char	*hs3;
	// char	**args;
	// int		fd;
	// char	*extraoptions;
	// pid_t	cpid;
	// int		malloc;
}				t_mini;

void	getpathoptions(char *prompt, t_mini *mini, char **newenv);
void	error_handling(char *errormessage);

#endif