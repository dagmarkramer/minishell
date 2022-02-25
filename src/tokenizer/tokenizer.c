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


void	me_add_token(t_list **tokens, int start, int end)
{
	
}

void	ms_find_word(char *input, t_list **tokens)
{
	int		w_start;
	int		w_end;
	char	tmp;

	w_start = 0;
	w_end = 0;
	while (input[w_end])
	{
		w_end = ms_find_offset(input, "\"\' \t\n|><", w_start + 1);
		ms_add_token(tokens, w_start, w_end);
		w_start = w_end + 1;
		if (input[w_start] == 0)
			break ;
	}

}

t_token	*ms_tokenizer(char *input)
{
	char	**word;

	word = ms_devide()
}