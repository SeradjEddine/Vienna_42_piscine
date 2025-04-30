

#include "libft.h"
char *ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	sublen;
	char	*substr;

	if ( start >= ft_strlen(str))
		return(ft_strdup(""));
	sublen = ft_strlen(str + start);
	if (sublen > len)
		sublen = len;
	substr = malloc(sizeof(char) * (sublen + 1));
	if(!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, (sublen + 1));
	return (substr);
}
