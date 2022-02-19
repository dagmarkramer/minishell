#include "../headers/minishell.h"

void	ms_echo(t_mini *mini)
{
	(void)mini;
	int fd = open("outfile", O_RDWR | O_CREAT, 0666);		
	dup2(fd, 1);
	printf("bye");
	printf("bye");
}