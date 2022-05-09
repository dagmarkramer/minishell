#include "minishell.h"
#include <dirent.h>

int	ft_strrcmp(char *haystack, char *needle)
{
    int hl;
    int nl;

    hl = ft_strclen(haystack, '\0');    // use ft_strlen here instead
    nl = ft_strclen(needle, '\0');
    while (hl >= 0 && nl >= 0)
    {
        if (haystack[hl] != needle[nl])
            return (1);
        hl--;
        nl--;
    }
    return (nl + 1);
}

int	wildcard_compare(char *name, char *wildcard)
{
    int wci;

    wci = ft_strclen(wildcard, '*');
    if (wildcard[wci] == '\0')
        return (0);
    if (!ft_strncmp(name, wildcard, wci) && !ft_strrcmp(&name[wci], &wildcard[wci + 1]))
        return (1);
    return (0);
}

t_list	**insert_wildcard_token(t_list **wild, char *word)
{
	t_list	*new;
	t_token	*n_token;

	n_token = malloc(sizeof(t_token));
	ft_malloc_fail_check(n_token);
	new = ft_lstnew((void *)n_token);
	ft_malloc_fail_check(new);
	new->next = *wild;
	*wild = new;
	n_token->id = Str;
	n_token->word = ft_strdup(word);
	ft_malloc_fail_check(n_token->word);
	return (&new->next);
}

void	wildcard_single_expander(t_list **wild)
{
	t_list	*original;
	DIR *d;
	struct dirent *dir;

	original = *wild;
	*wild = (*wild)->next;
    d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (wildcard_compare(dir->d_name, ((t_token *)original->content)->word))
			{
				wild = insert_wildcard_token(wild, dir->d_name);
			}
		}
		closedir(d);
	}
	ms_del_token((void *)original);
}

void	wildcards_expander(t_list **tokens)
{
	t_token	*tmp;

	while (*tokens != NULL)
	{
		tmp = (t_token *)(*tokens)->content;
		if (tmp->word[ft_strclen(tmp->word, '*')] == '*')
			wildcard_single_expander(tokens);
		tokens = &((*tokens)->next);
	}
}
