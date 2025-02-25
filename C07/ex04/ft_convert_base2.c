#include <stdlib.h>

int check_base(char *b, int *len)
{
	int	j;

	*len = 0;
	while (b[*len])
	{
		if (b[*len] == '+' || b[*len] == '-' || 
			b[*len] == ' ' || (b[*len] >= 9 && b[*len] <= 13))
			return (0);
		j = *len;
		while (j >= 0)
		{
			j--;

			if (b[*len] == b[j])
			return 0;
		}
		(*len)++;
		}
	return (*len > 1);
}

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

int numfy (char *base, int base_len, char *str, int start)
{
	int num;
	int j;

	num = 0;
	while (str [start])
	{
		j = 0;
		while ( j < base_len)
		{
			if (str[start] == base[j])
				break ;
			j ++;
		}
		if (j == base_len)
			break;
		num = num * (base_len) + j;
		start ++;
	}

	return (num);
}
void swap (char *str, int end)
{
	char	tmp;
	int	start;

	if (str[0] == '-')
		start = 1;
	else
		start = 0;
	while (start < end)
	{
		tmp = str [start];
		str [start] = str [end];
		str [end] = tmp;
		start ++;
		end --;
	}
}

char *strfy(int num, char *base_to, int base_to_len, int sign)
{
	int	i;
	int	size;
	int 	tmp;
	char	*mystring;


	size = 0;
	tmp = num;
	while (tmp)
	{
		tmp /= base_to_len;
		size ++;
	}
	if (sign == 1)
		mystring = malloc (size + 1);
	else
		mystring = malloc (size + 2);
	if (!mystring)
		return (0);
	i = 0;
	if (sign == -1)
		mystring [i++] = '-';

	while (num > 0)
	{
		mystring[i++] = base_to[(num % base_to_len)];
		num /= base_to_len;
        }
	swap (mystring, i-1);	
	mystring[i] = '\0';
	return (mystring);
}

