#include "minishell.h"

void    ms_pipe(t_list *pipes)
{
    int pipefd[2];
    int savepipe;

    savepipe = 0;
    while (pipes)
    {
        if (pipes->next)
            if (pipe(pipefd) == -1)//read is 0 write is 1
			    ft_disruptive_exit("pipe", 333);
        if (savepipe)
            pipefd[1] = savepipe;
        if ((t_pipe *)pipes->content)->pipe_before && savepipe)
            (t_pipe *)pipes->content)->input_fd = pipefd[];
        if ((t_pipe *)pipes->content)->pipe_after)
            (t_pipe *)pipes->content)->output_fd = pipefd[1];
		savepipe = pipefd[0];
        pipes = pipes->next;
    }
}

cat 1 | cat 2
read 2
write 1