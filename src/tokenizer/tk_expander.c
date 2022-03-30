#include "tokenizer.h"
#include "minishell.h"

// working on this need to take care of env first!!

// using a global for env is ok?
char	*tk_replace_env(char *word, int dollar, t_list *env)
{
	char	*result;
	char	*key;
	char	*value;

	key = ft_substr(word, dollar, ft_strslen(&word[dollar], " \t\n")); // more options than just space!!
	value = ev_getenv(key, env);

	// malloc word-len plus env-len
	result = malloc(sizeof(char) * (ft_strlen(word) + ft_strlen(value)));
	if (result == NULL)
		// error!
		return (NULL);
	
	// write first part to result
	ft_memcpy(result, word, dollar);

	// write env part to result
	ft_memcpy(&result[dollar], value, ft_strlen(value));

	// write second part to result ft_strclen(&word[dollar], ' ')
	

	ft_strcpy(&result[dollar + ft_strlen(value)], &word[dollar + ft_strslen(&word[dollar], " \t\n")]); //mude
	// // strdup to get a clean string (maybe ot needed just small excess allocation) // not needed
	// free word
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
				word = tk_replace_env(word, i, env);
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

void	tk_expand_env(void *in, t_list *env) // env lst made in ms_init needed! maybe put both pointers in a struct together
{
	t_token	*token;

	token = (t_token *)in;
	token->word = tk_expander(token->word, env);
}
