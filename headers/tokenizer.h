#ifndef TOKENIZER_H
# define TOKENIZER_H

#	include "libft.h"

typedef enum 	e_token_id
{
	Pipe,
	Nbr,
	Str,
	Heredoc,
	Redirection
}				t_token_id;

typedef struct	s_token
{
	t_token_id	id;
	char		*word;
}				t_token;

t_list	*ms_tokenizer(char *input);

void	ms_del_token(void *incomming);
int		ms_lstadd_token(t_list **tokens, char *word);
int		ms_find_offset(char *in, char *delimiters, int offset);
int		ms_skip_chars(char *in, char *to_skip, int offset);

#endif