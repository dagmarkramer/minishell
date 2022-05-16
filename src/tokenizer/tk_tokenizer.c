/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_tokenizer.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:45:54 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/14 15:35:21 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
 *	This function turns the input string into tokens
 *	it uses the same rules as bash for splitting up words but
 *	changes closes quotes instead of giving a newline when quotes
 *	are unclused at the end
 */

t_list	*ms_tokenizer(char *input)
{
	t_list	*tokens;

	tokens = 0;
	if (ms_add_tokens(&tokens, input))
	{
		ft_lstclear(&tokens, ms_del_token);
		ft_disruptive_exit("malloc fail", 1);
	}
	ft_lstiter(tokens, tk_name_token);
	return (tokens);
}
