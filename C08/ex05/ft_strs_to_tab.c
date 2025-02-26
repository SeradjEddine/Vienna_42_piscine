#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i]) 
		i ++;
	return i;
}

char	*ft_strcpy(char *dest, char *src)
{
	int j;

	j=0; 
	while(src[j]) 
	{	
		dest [j] = src [j];
		j ++;
	}
	dest[j] = '\0';
	return (dest);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*sa;
	int		i;

	sa =(t_stock_str *) malloc (sizeof(t_stock_str) * (ac + 1));
	if (!sa) 
		return NULL;
	i = -1;
	while (++i < ac)
	{
		sa[i].size = ft_strlen(av[i]);
		sa[i].str = av[i];
		sa[i].copy =(char*)malloc(sizeof(char)*(ft_strlen(av[i]) + 1));
		//sa[i] = (t_stock_str){len, av[i], malloc(len+1)};
	if (!sa[i].copy)
	{
		while (i-- > 0)
			free(sa[i].copy);
		free(sa);
		return NULL;
	}
	ft_strcpy(sa[i].copy, av[i]);
	}
	sa[i].str = 0;
	sa[i].size = 0;
	sa [i].copy = 0;
//	sa[i] = (t_stock_str){0, 0, 0};
	return sa;
}
