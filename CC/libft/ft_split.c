#include "libft.h"

static char **set_free(char **str,size_t x)
{
	while (x-- > 0)
		free(str[x]);
	free(str);
	return (NULL);
}

static size_t word_counter( const char *str, char c)
{
	size_t i ;
	size_t count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i ++;
		if (str[i])
		{
			count ++;
			while (str[i] && str[i] != c)
				i ++;
		}
	}
	return (count);
}

static char **populate (char *str, char c, char **arr, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	x;

        i = 0;
	j = 0; 
	x = 0;
        while (x ++ < count)
        {
                while (str[i] == c)
                        i ++;
                j = i;
                while (str[i] && str[i] != c)
                        i ++;
                split[x] = malloc (sizeof ( char) * (i - j + 1));
                if (!split[x])
                        return (set_free(split, x);
                ft_strlcpy(split[x],str + j, i - j + 1);
        }
	return (arr)
}

char **ft_split(char const *str, char c)
{
	size_t count;
	char **arr;

	if (!str)
		return (NULL);
	count = word_counter(str, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return(NULL);
	arr[count] = NULL;
	return (populate(str, c, arr, count));
}
