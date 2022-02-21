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
	printf("%s\n", getenv(NULL));
}

void	ms_unset(t_mini *mini)
{

}

void	ms_env(t_mini *mini)
{

}

void	ms_exit(t_mini *mini)
{

}