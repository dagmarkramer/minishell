int		ms_add_env(char *key, char *value, t_list **envlst)
{
	t_list	*new;

	new = ms_keyval_lst_add(key, value);
	if (new == NULL)
		return (1); // error
	// add new to the list in sorted spot, maybe already made in dagmar codes for sorting.
}