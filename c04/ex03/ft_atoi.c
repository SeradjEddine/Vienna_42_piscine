
int preproccess (char *str, int *sign)
{
	int i;

	i  = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;		       
	while (str [i] == '-' || str[i] == '+')
	{
		if (str [i] == '-') 
			*sign *= -1;		
		i ++;
	}
	return (i);
}

int numfy (char *str, int *start)
{
	int num;

	num = 0;
	while (str[*start] > 47 && str[*start] < 58)
	{
		num = num * 10 + (str [*start] - 48);
		(*start) ++;
	}	
	return (num);
}

int ft_atoi(char *str)
{	
	int start;
	int sign;
	int num;

	sign = 1;
	start = preproccess (str, &sign);
	num = numfy(str, &start);
	num *= sign;
	return (num);	
}

#include <stdio.h>
int main (){

	printf("%d\n", ft_atoi("  +--211913"));
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
}
