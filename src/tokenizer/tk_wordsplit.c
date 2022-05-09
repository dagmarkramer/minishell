#include "tokenizer.h"

int	ms_find_word_end(char *input, int i, char state)
{
	if (state == '\'')
	{
		i = ms_find_offset(input, "\'", i);
		if (input[i] == '\0')
			return (i);
		return (ms_find_word_end(input, i + 1, 0));
	}
	if (state == '\"')
	{
		i = ms_find_offset(input, "\"", i);
		if (input[i] == '\0')
			return (i);
		return (ms_find_word_end(input, i + 1, 0));
	}
	else
	{
		i = ms_find_offset(input, "\"\' \t\n|><", i);
		if (input[i] == '\0' || ft_strchr(" \t\n|<>", input[i]))
			return (i);
		return (ms_find_word_end(input, i + 1, input[i]));
	}
}

char	*ms_claim_word(char *input, int start, int size)
{
	char	*new_word;

	new_word = malloc(size + 1);
	if (new_word == NULL)
		return (NULL);
	new_word[size] = 0;
	if (size == 0)
		return (new_word);
	return (ft_memcpy(new_word, &input[start], size));
}

int	ms_add_tokens(t_list **tokens, char *input)
{
	int		i;
	int		start;
	char	*new_word;

	i = 0;
	while (input[i])
	{
		start = ms_skip_chars(input, " \t\n", i);
		if (ft_strchr("<>", input[start]) && input[start] == input[start + 1])
			i = start + 2;
		else if (ft_strchr("|<>", input[start]))
			i = start + 1;
		else
			i = ms_find_word_end(input, start, 0);
		if (i == start)
			return (0);
		new_word = ms_claim_word(input, start, i - start);
		if (new_word == NULL)
			return (1);
		if (ms_lstadd_token(tokens, new_word))
			return (1);
		start = i;
	}
	return (0);
}
