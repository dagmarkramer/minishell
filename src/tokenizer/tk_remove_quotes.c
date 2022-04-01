#include "minishell.h"

void	tk_remove_quotes(void *token)
{
	int		i;
	char	state;
	char	*word;

	word = ((t_token *)token)->word;
	state = '\0';
	i = 0;
	while (word[i] != '\0')
	{
		if ((word[i] == '\'' || word[i] == '\"') && state == '\0')
		{
			state = word[i];
			ft_memmove(&word[i], &word[i + 1], ft_strlen(&word[i]));
		}
		else if (word[i] == state)
		{
			ft_memmove(&word[i], &word[i + 1], ft_strlen(&word[i]));
			state = '\0';
		}
		else
			i++;
	}
}
