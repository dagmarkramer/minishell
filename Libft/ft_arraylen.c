int	ft_arraylen(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
