#include "tokenizer.h"
#include "minishell.h"

// working on this need to take care of env first!!

// using a global for env is ok?
char	*tk_replace_env(char *word, int dollar, t_list *env)
{
	char	*result;
	char	*key;
	char	*value;
	char	zero;

	zero = '\0';
	key = ft_substr(word, dollar, ft_strslen(&word[dollar], " \t\n"));
	value = ev_getenv(key, env);		// getenv needs work and testing
	printf("val: %s\n", value);
	if (value == NULL)
		value = &zero;
	result = malloc(sizeof(char) * (ft_strlen(word) + ft_strlen(value) + 1));
	// if (result == NULL)
	// 	return (NULL);
	
	printf("values len1 %i len2 %i\n", (int)ft_strlen(value), ft_strslen(&word[dollar], " \t\n")); //  second strlen is just 0
	ft_memcpy(result, word, dollar);
	ft_memcpy(&result[dollar], value, ft_strlen(value));
	ft_strcpy(&result[dollar + ft_strlen(value)], &word[dollar + ft_strslen(&word[dollar], " \t\n")]);
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
				sleep(1);
				printf("%s\n", word);
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

void	tk_expand_all(t_list *tokens, t_list *env)
{
	while (tokens != NULL)
	{
		tk_expand_env(tokens->content, env);
		tokens = tokens->next;
	}
}

// val: /private/tmp/com.apple.launchd.mons8y4Duf/Render
// values len1 48 len2 0
// /private/tmp/com.apple.launchd.mons8y4Duf/Render/private/tmp/com.apple.launchd.mons8y4Duf/Render$USER
