#include "minishell.h"

void	ms_redirect(t_mini *mini, char *c)
{
	int	fd;
	// struct stat *buf;
	// int	ret;
	// int	i;
	// char	*line;

	(void)mini;
	if (!ft_strncmp(">>", c, ft_strlen("c")))
	{
		fd = open("outfile", O_WRONLY | O_APPEND);
		if (fd == -1)
			error_handling("outfile");
		if (dup2(fd, 0) == -1)
			error_handling("dup2() error");
	}
	else if (!ft_strncmp("<", c, ft_strlen("c")))
	{
		printf("hi");
		fd = open("infile", O_RDONLY);
		if (fd == -1)
			error_handling("infile");
		if (dup2(fd, 1) == -1)
			error_handling("dup2() error");
	}
	else if (!ft_strncmp(">", c, ft_strlen("c")))
	{
		printf("hi2");
		fd = open("outfile",  O_WRONLY | O_CREAT, 0666);
		if (fd == -1)
			error_handling("outfile");
		if (dup2(fd, 0) == -1)
			error_handling("dup2() error");
	}

	free2darr(mini);
	
}