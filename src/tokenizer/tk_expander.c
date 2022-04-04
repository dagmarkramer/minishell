#include "tokenizer.h"
#include "minishell.h"

char	*tk_replace_env(char *word, int dollar, t_list *env)
{
	char	*result;
	char	*key;
	char	*value;
	char	zero;

	zero = '\0';
	key = ft_substr(word, dollar + 1, ft_strslen(&word[dollar + 1], " \t\n"));
	ft_malloc_fail_check(key);
	value = ev_getenv(key, env);
	if (value == NULL)
		value = &zero;
	result = malloc(sizeof(char) * (ft_strlen(word) + ft_strlen(value) + 1));
	ft_malloc_fail_check(result);
	ft_memcpy(result, word, dollar);
	ft_memcpy(&result[dollar], value, ft_strlen(value));
	ft_strcpy(&result[dollar + ft_strlen(value)], &word[dollar + ft_strslen(&word[dollar], " \t\n")]);
	free(key);
	free(word);
	return (result);
}

char	*tk_expander(char *word, t_list *env)
{
	int	state;
	int	i;

	i = 0;
	state = 0;
	while (word[i])
	{
		if (state == 0)
		{
			if (word[i] == '\'')
				state = 1;
			if (word[i] == '$')
			{
				if (!(i - 3 >= 0 && word[i - 3] == '<' && word[i - 2] == '<'))
				{
					word = tk_replace_env(word, i, env);
					i--;
				}
			}	
		}
		else
			if (word[i] == '\'')
				state = 0;
		i++;
	}
	return (word);
}

void	tk_expand_env(void *in, t_list *env)
{
	t_token	*token;

	token = (t_token *)in;
	token->word = tk_expander(token->word, env);
}

void	tk_expand_all(t_list *tokens, t_list *env)
{
	while (tokens != NULL)
	{
		tk_expand_env(tokens->content, env);
		tokens = tokens->next;
	}
}
