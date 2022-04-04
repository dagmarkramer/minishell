#include "tokenizer.h"

/*
 *	Change a part of a list into an **array.
 *	Good on paper but not what we need for minishell.
 */

/*
 *	Do the same but for a list of tokens into an array of words.
 *	Puts n amount of items into an array of tokens.
 */

/*
 *	These pointers are not malloced again BUT the array they are in is newly malloced.
 *	So the array needs to be freed but the content not, that is done while freeing the list.
 */

char	**token_list_to_array(t_list *tokens, int n)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(char *) * (n + 1));
	t_malloc_fail_check(array);
	array[n] = '\0';
	while (i < n && tokens != NULL)
	{
		array[i] = ((t_token *)tokens->content)->word;
		tokens = tokens->next;
		i++;
	}
	return (array);
}
