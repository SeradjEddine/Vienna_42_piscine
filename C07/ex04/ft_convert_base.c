#include <stdlib.h>

int check_base(char *b, int *len);
int preproccess (char *str, int *sign);
int numfy (char *base, int base_len, char *str, int start);
void swap (char *str, int end);
char *strfy(int num, char *base_to, int base_to_len, int sign);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{	
	char	*converted;
	int	base_from_len;
	int	base_to_len;
	int	start;
	int	sign;
	int	num;

	sign = 1;
	if (!check_base(base_from, &base_from_len) || (!check_base(base_to, &base_to_len)))
		return 0;
	start = preproccess (nbr, &sign);
	num = numfy(base_from, base_from_len, nbr, start);
	if (num != 0)
		converted = strfy( num, base_to, base_to_len, sign);
	else
	{
		converted = malloc (2);
		if (!converted)
			return (0);
		converted [0] = base_to [0];
		converted [1] = '\0';
	}
	return (converted);	
}

#include <stdio.h>

int main() {
    // Test 1: Binary to Decimal
    printf("%s\n", ft_convert_base("--++-+10eert56hkl910", "01ert", "0123456789")); // "10"

    // Test 2: Negative Decimal to Hex
    printf("%s\n", ft_convert_base("-42", "0123456789", "0123456789ABCDEF")); // "-2A"

    // Test 3: Zero Case
    printf("%s\n", ft_convert_base("0", "01", "0123456789")); // "0"

    // Test 4: Invalid Base
    printf("%s\n", ft_convert_base("123", "012", "01")); // NULL

    return 0;
}
