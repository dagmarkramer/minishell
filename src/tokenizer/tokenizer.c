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

int		ms_find(char *in, char *c, int offset)
{
	int	i;

	i = 0
	while (in[i])
	{
		if (in[i] == c[0] || in[i] == c[1])
			return (i + offset);
		i++;
	}
	return (i);
}

char	*ms_word_finder(char *input)
{
	int	tmp;
	int	tmp2;

	tmp = ms_find(input, "\'\"", 0);
	if (input[tmp] != 0)
	{
		if (input[tmp] == '\'')
			tmp2 = ms_find(input, "\'", tmp + 1);
		else
			tmp2 = ms_find(input, "\"", tmp + 1);
		while (input[tmp2] != 0 && !ft_isspace(input[tmp2]))
			tmp2++;
		while (tmp != 0 && !ft_isspace(input[tmp]))
			tmp--;
		// input[tmp] - input[tmp2] = een word;
	}
}

char	**ms_devide(char *input)

t_token	*ms_tokenizer(char *input)
{
	char	**word;

	word = ms_devide()
}