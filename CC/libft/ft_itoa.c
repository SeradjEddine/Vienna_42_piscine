#include "libft.h"
char *ft_itoa(int n)
{	
	char	*str;
	size_t	count;
	long	num;

	num = n;
	count = (1 * (num < 0) + 1);
	while (num /= 10)
		count ++;
	str = malloc (sizeof(char) * (count +1));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	if ( num == 0)
		str[0] ='0';
	else if ( num < 0)
		str[0] = '-';
	while(num)
	{
	str[count--] = '0' + (num % 10);
	num /= 10;
	}
	return (str);
}
