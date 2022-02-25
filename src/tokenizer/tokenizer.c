#include "minishell.h"

// in = one string with everything

// (tokenize?) take care of "" and '' 

// (tokenize) take care of redirections <<, >>, > and < 

// (tokenize) pipes

// handle $ and



// out = everything set up per pipe (ready to be forked or processed)


// cat -e infile | grep $echo | grep "a | a" >> outfile
// cat -e infile
// 			grep $echo
// 					grep "a | a"
// 								>> outfile

// word splitting on tabs spaces newlines and pipes and redirections
// find pipes and split on them with info
// find redirections 
// environ vars expanded
// take care of
// de quoting "" and ''

// 1 quotes
// 2 whitespace + newlines
// 3 pipes 
// 4 redirections
// 5 environment variables

// void	me_add_token(t_list **tokens, int start, int end)
// {
	
// }

// void	ms_find_words(char *input, t_list **tokens)
// {
// 	int		w_start;
// 	int		w_end;
// 	char	tmp;

// 	w_start = 0;
// 	w_end = 0;
// 	while (input[w_end])
// 	{
// 		w_end = ms_find_offset(input, "\"\' \t\n|><", w_start + 1);
// 		ms_add_token(tokens, w_start, w_end);
// 		w_start = w_end + 1;
// 		if (input[w_start] == 0)
// 			break ;
// 	}

// }
void	ft_print2darray(char **array2d)
{
	int	i;

	i = 0;
	while (array2d[i])
	{
		printf("%s\n", array2d[i]);
		i++;
	}
}

t_token	*ms_tokenizer(char *input)
{
	char	**word;

	word = ft_split(input, '\'');
	ft_print2darray(word);
}