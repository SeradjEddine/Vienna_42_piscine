#include <unistd.h>

int ft_atoi_base(char *str, char *base)
{
    int base_len;
    int i;
    int j;
    int k;
    int sign;
    long result;

    base_len = 0;
    if (base == 0 || base[0] == '\0')
        return (0);
    while (base[base_len])
    {
        if (base[base_len] == '+' || base[base_len] == '-' || 
            base[base_len] == ' ' || (base[base_len] >= 9 && base[base_len] <= 13))
            return (0);
        base_len++;
    }
    if (base_len < 2)
        return (0);
    i = 0;
    while (i < base_len)
    {
        j = i + 1;
        while (j < base_len)
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    sign = 1;
    result = 0;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    while (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str)
    {
        k = 0;
        while (k < base_len)
        {
            if (*str == base[k])
                break ;
            k++;
        }
        if (k == base_len)
            break ;
        result = result * base_len + k;
        str++;
    }
    return (result * sign);
}

#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main()
{
    // Test cases
    printf("Test 1: \"1010\" (binary) -> %d\n", ft_atoi_base("1010", "01")); // Expected: 10
    printf("Test 2: \"-1010\" (binary) -> %d\n", ft_atoi_base("-1010", "01")); // Expected: -10
    printf("Test 3: \"7F\" (hex) -> %d\n", ft_atoi_base("7F", "0123456789ABCDEF")); // Expected: 127
    printf("Test 4: \"  +--42\" (decimal) -> %d\n", ft_atoi_base("  +--42", "0123456789")); // Expected: -42
    printf("Test 5: \"  -+42\" (invalid base) -> %d\n", ft_atoi_base("  -+42", "0123456789+-")); // Expected: 0 (invalid base)
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

