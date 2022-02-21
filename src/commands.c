#include "minishell.h"

void	ms_echo(t_mini *mini)
{
	if (!ft_strncmp(mini->splitin[1], "-n", ft_strlen(mini->splitin[1])))
	{
		printf("%s", mini->splitin[2]);
		free (mini->splitin[1]);
		free (mini->splitin[2]);
	}
	else
	{
		printf("%s\n", mini->splitin[1]);
		free (mini->splitin[1]);
	}
}

// relative path: the hierarchical path that locates a file or folder on a file system starting from the current directory
// absolute path: the complete details needed to locate a file or folder
void	ms_cd(t_mini *mini)
{
	chdir(mini->splitin[1]);
	free (mini->splitin[1]);
}

void	ms_pwd(t_mini *mini)
{
	char buf[PATH_MAX];

	(void)mini;
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
}

void	ms_export(t_mini *mini)
{
	(void)mini;
	// static char termbuf[50];
	// char *term;
	// extern char *tgetstr(), *getenv();
	// char entry[1024];

	// term = getenv("PATH");
	// printf("%s\n", term);
	// // term = NULL;
	// if (tgetent(termbuf, term) != 1)
	// 	return;
	// char *loc = termbuf;
	// printf("%s\n", tgetstr("a", &loc));
	// // int fd = open("/Users/dkramer/MINISHELLfolder/minishell", O_RDWR | O_NOCTTY | O_NDELAY);
	// // // (void)mini;
	// // // printf("%s\n", getenv(NULL));
	// // struct termios  config;
	// // if(tcgetattr(fd, &config) < 0) 
	// // 	return ;
	// // config.c_lflag |= (unsigned long)mini->splitin[1];
	// // if(tcsetattr(fd, TCSAFLUSH, &config) < 0)
	// // 	return ;
}

void	ms_unset(t_mini *mini)
{
	(void)mini;
}

void	ms_env(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->environ[i])
	{
		printf("%s\n", mini->environ[i]);
		i++;
	}
}

void	ms_exit(t_mini *mini)
{
	(void)mini;
}