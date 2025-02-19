
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

int ft_atoi_base(char *str, char *base)
{	
	int base_len;
	int start;
	int sign;
	int num;

	sign = 1;
	base_len = 0;
	if (!check_base(base, &base_len))
		return 0;
	start = preproccess (str, &sign);
	num = numfy(base, base_len, str, start);
	num *= sign;
	return (num);	
}

#include <stdio.h>

int main()
{
    // Test cases
    printf("Test 1: \"1010\" (binary) -> %d\n", ft_atoi_base("1010", "01")); // Expected: 10
    printf("Test 2: \"-1010\" (binary) -> %d\n", ft_atoi_base("-1010", "01")); // Expected: -10
    printf("Test 3: \"7F\" (hex) -> %d\n", ft_atoi_base("7F", "0123456789ABCDEF")); // Expected: 127
    printf("Test 4: \"  +--42\" (decimal) -> %d\n", ft_atoi_base("  +--42", "0123456789")); // Expected: 42
    printf("Test 5: \"  -+42\" (invalid base) -> %d\n", ft_atoi_base("  -+42", "0123456789")); // Expected: -42 
    printf("Test 6: \"123\" (base 4) -> %d\n", ft_atoi_base("123", "0123")); // Expected: 27
    printf("Test 7: \"123\" (invalid base) -> %d\n", ft_atoi_base("123", "01123")); // Expected: 0 (invalid base)
    printf("Test 8: \"123\" (empty base) -> %d\n", ft_atoi_base("123", "")); // Expected: 0 (invalid base)
    printf("Test 9: \"123\" (base size 1) -> %d\n", ft_atoi_base("123", "0")); // Expected: 0 (invalid base)
    printf("Test 10: \"123\" (base with whitespace) -> %d\n", ft_atoi_base("123", "0123 ")); // Expected: 0 (invalid base)
    printf("Test 11: \"123\" (base with duplicates) -> %d\n", ft_atoi_base("123", "01234")); // Expected: 0 (invalid base)
    printf("Test 12: \"123\" (base with +) -> %d\n", ft_atoi_base("123", "01234+")); // Expected: 0 (invalid base)
    printf("Test 13: \"123\" (base with -) -> %d\n", ft_atoi_base("123", "01234-")); // Expected: 0 (invalid base)
    printf("Test 14: \"123\" (base with tab) -> %d\n", ft_atoi_base("123", "01234\t")); // Expected: 0 (invalid base)
    printf("Test 15: \"123\" (base with newline) -> %d\n", ft_atoi_base("123", "01234\n")); // Expected: 0 (invalid base)
    printf("Test 16: \"123\" (base with carriage return) -> %d\n", ft_atoi_base("123", "01234\r")); // Expected: 0 (invalid base)
    printf("Test 17: \"123\" (base with vertical tab) -> %d\n", ft_atoi_base("123", "01234\v")); // Expected: 0 (invalid base)
    printf("Test 18: \"123\" (base with form feed) -> %d\n", ft_atoi_base("123", "01234\f")); // Expected: 0 (invalid base)
    printf("Test 19: \"123\" (base with all invalid chars) -> %d\n", ft_atoi_base("123", "+- \t\n\r\v\f")); // Expected: 0 (invalid base)
    printf("Test 20: \"123\" (base with valid chars) -> %d\n", ft_atoi_base("123", "0123456789")); // Expected: 123

    return 0;
}
