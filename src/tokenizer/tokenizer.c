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

word splitting on tabs spaces newlines and pipes and redirections
find pipes and split on them with info
find redirections 
environ vars expanded
take care of
de quoting "" and ''

1 quotes
2 whitespace + newlines
3 pipes 
4 redirections
5 environment variables


// void	ft_print2darray(char **array2d)
// {
// 	int	i;

// 	i = 0;
// 	while (array2d[i])
// 	{
// 		printf("%s\n", array2d[i]);
// 		i++;
// 	}
// }


// use finite state maybe with an int which saves the state so i can recursively
// go over the loop and is the state is " opened then it needs to be closed to switch to an lower state which can end the 
// word
// state 0 every delimiter can cange the state to end space, newline, tab, redirection, or end of string (\0)
// state 1 a " is open this needs to be closed or \0 can end the state 
// state 2 same but with '
// need more states?
// recursively go over it with different states but recursive call is last and only needs to return the end of the word
// pass on recursively the state we are in the index and also the string we are working on
// the start / beginning of the word is saved one state higher that is also where whitespace is skipped
void	ms_find_word(t_list **tokens, char *input, int start)
{
	int		i;

	if (start !=0)
		start++;
	start = ms_offset_find(input, " \t\n", start);
	i = start;
	i = ms_find_offset(input, "\"\' \t\n|><", i);
	if (input[i] == '\0')
		// this is the end
	if (ft_strchr("", input[i]))


	// int		w_start;
	// int		w_end;
	// char	tmp;

	// w_start = 0;
	// w_end = 0;
	// while (input[w_end])
	// {
	// 	w_end = ms_find_offset(input, "\"\' \t\n|><", w_start + 1);
	// 	ms_add_token(tokens, w_start, w_end);
	// 	w_start = w_end + 1;
	// 	if (input[w_start] == 0)
	// 		break ;
	// }

}

char	*ms_claim_word()
{

}

int	ms_add_token(t_list **tokens, char *input, int start)
{
	int		i;

	if (start !=0)
		start++;
	i = start;
	while (input[i])
	{
		i = ms_find
	}
}

char	**ms_tokenizer(char *input)
{
	t_list	*tokens;
	int		i;

	i = 0;
	tokens = 0;
	while (input[i])
	{
		i = ms_add_token(&tokens, input, i);
		if (i == -1)
			return(EXITFUNCTION);
	}
	return(ft_list_to_array(tokens));
}


// change list to array												ft_list_to_array
// 	keep track of tokens and request next token						ms_tokenizer
// 		add one token to list found by next function				ms_add_token
// 			malloc token and return it (is this needed?)			ms_claim_word
// 				search for token and return location				ms_find_word