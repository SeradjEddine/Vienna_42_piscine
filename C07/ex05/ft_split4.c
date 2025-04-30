
int	ft_strlen (char *str, char *charset, int index)
{
	int len;

	len = 0;
	while (
}

char **ft_split(char *str, char *charset)
{
	int	i;
	int	j;
	int	tot_len;
	int	new_word;
	int	word_count;
	char	**my_array;

	word_count = 0;
	new_word = 0;
	tot_len = 0;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{	//handle edge case when sep char is at end of string (or more than one)
			if (str[i] == charset[j] && new_word &)
			{
				new_word = 0;
				tot_len ++;
				word_count ++;
				break ;
			}	
			j ++;
		}
		tot_len ++;
		i ++;
	}
	my_array = (char**)malloc((word_count+1) *sizeof(char*));
	if (!myarray)
		return (0);
	i = 0;
	while ( i < word_count)
	{
		myarray[i] = (char*)malloc((ft_strlen(str, i) +1) * sizeof(char);
	}


}
