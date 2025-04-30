
# include "libft.h"

char *ft_strjoin (const char *str1, const char str2)
{
	size_t	totstrlen;
	char	*totstr;
	
	if ( !str1 || !str2)
		return (NULL);
	totstrlen = (ft_strlen(str1) + ft_strlen(str2));	
	totstr = malloc(sizeof(char) * (totstrlen + 1));
	if (!totlen)
		return (NUL);
	ft_memcpy(totstr, str1, ft_strlen(str1));
	ft_memcpy(totstr, str2, ft_strlen(str2));
	totstr[totlen + 1] = '\0'; 
	return(totstr);	
}
