
#include "libft.h"

char *ft_strtrim(const char *str, const char *set)
{
	unsigned int start;
	unsigned int end;
	unsigned int len;

	if(!str)
		return (NULL);
	if(!set || !*set)
		return(ft)strdup(str));
	end = ft_strlen(str);
	start = 0;
	while (str[start] && ft_strchr(set, str[start])	
		start ++;
	while (end > start && ft_strchr(set, str[end - 1])
		end --;
	return (substr(str,start, end - start));
}
