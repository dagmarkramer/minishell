#include "tokenizer"

// working on this need to take care of env first!!

// using a global for env is ok?
char	*tk_replace_env(char *word, int dollar, t_list *env)
{
	char	*result;
	char	*key;
	char	*value;

	key = ft_substr(word, dollar, ft_strslen(&word[dollar], " \t\n")); // more options than just space!!
	value = ms_getenv(key, env);

	result = malloc(sizeof(char) * (ft_strlen(word) + ft_strlen(value)));
	if (result == NULL)
		// error!
	
							// malloc word-len plus env-len
	// write first part to result
	ft_memcpy(result, word, dollar);
	// write env part to result
	ft_memcpy(&result[dollar], value, ft_strlen(value));
	// write second part to result ft_strclen(&word[dollar], ' ')
	ft_memcpy(&result[dollar + ft_strlen(value)], /* after the env var $env in word string */)
	// // strdup to get a clean string (maybe ot needed just small excess allocation) // not needed
	return (result);
}

char	*tk_expander(char *word, t_list *env)
{
	int	state;
	int	i;

	i - 0;
	state = 0;
	while (word[i])
	{
		if (state == 0)
		{
			if (word[i] == '\'')
				state = 1;
			if (word[i] == '$')
			{
				word = tk_repace_env(word, i, env);
				i--;
			}	
		}
		else
			if (word[i] == '\'')
				state = 0;
		i++;
	}
	return (word);
}

void	tk_expand_env(void *in, t_list *env) // env lst made in ms_init needed!
{
	t_list	*token;

	token = (t_list *)in;
	token->word = tk_expander(token->word, env);
}
