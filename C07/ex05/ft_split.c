#include <stdlib.h>

int	is_delimiter(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
            		return 1;
		charset++;
	}
	return 0;
}

int	count_substrings(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_delimiter(*str, charset))
			str++;
		if (*str)
            		count++;
		while (*str && !is_delimiter(*str, charset))
			str++;
	}
	return count;
}

char	**ft_split(char *str, char *charset)
{
	int	count;
	char	**result;

       	count = count_substrings(str, charset);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return NULL;
	int i = 0;
	while (*str)
	{
		while (*str && is_delimiter(*str, charset))
			str++;
		if (*str)
		{
			char *start = str;
            		while (*str && !is_delimiter(*str, charset))
			str++;
			int len = str - start;
			result[i] = (char *)malloc((len + 1) * sizeof(char));
			if (!result[i])
				return NULL;
			int j = 0;
			while (j < len)
				result[i][j++] = *start++;
			result[i][j] = '\0';
			i++;
        	}
	}
	result[i] = NULL;
	return result;
}

#include <stdio.h>

int main() {
    char *str = " ;Hello,world;this is a test ,;";
    char *charset = " ,;";
    char **result = ft_split(str, charset);
    if (result) {
        for (int i = 0; result[i]; i++) {
            printf("Substring %d: %s\n", i, result[i]);
            free(result[i]); // Free each substring
        }
        free(result); // Free the array
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
