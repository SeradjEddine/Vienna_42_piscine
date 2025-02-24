#include <stdlib.h>

int	ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
char	*allocate(int size);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strcat (char *dest, char *src)
{
	int	dest_len; 
	int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src [i])
	{
		dest[dest_len + i] = src[i];
		i ++;
	}
	dest [dest_len + i] = '\0';
	return (dest);
}

char	*allocate(int size)
{
	char *str;

	if (size ==0)
	{
		str = malloc (1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	str = malloc (size);
	if (!str)
		return (0);	
	return (str);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int 	tot_len;
	char 	*mystring;

	i = 0; 
	tot_len = 0;
	while ( i < size)
		tot_len += ft_strlen(strs[i++]);
	tot_len += (ft_strlen(sep) * (size -1)) +1;
	mystring = allocate (tot_len);
	if (!mystring)
		return (0);
	mystring[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat (mystring, strs[i]);
		if (i < (size - 1))
			ft_strcat (mystring, sep);
		i ++;
	}
	return (mystring);	
}

#include <stdio.h>
int main()
{
    // Test Case 1: Basic concatenation
    char *strs1[] = {"Hello", "world", "!"};
    char *result1 = ft_strjoin(3, strs1, ", ");
    printf("Test 1: \"%s\"\n", result1); // Expected: "Hello, world, !"
    free(result1);

    // Test Case 2: Empty input (size = 0)
    char *result2 = ft_strjoin(0, NULL, "ignored");
    printf("Test 2: \"%s\"\n", result2); // Expected: "" (empty string)
    free(result2);

    // Test Case 3: Single string
    char *strs3[] = {"Alone"};
    char *result3 = ft_strjoin(1, strs3, "--");
    printf("Test 3: \"%s\"\n", result3); // Expected: "Alone"
    free(result3);

    // Test Case 4: Mixed empty strings
    char *strs4[] = {"", "", ""};
    char *result4 = ft_strjoin(3, strs4, "X");
    printf("Test 4: \"%s\"\n", result4); // Expected: "XX" (two separators between three empty strings)
    free(result4);

    // Test Case 5: No separator
    char *strs5[] = {"One", "Two", "Three"};
    char *result5 = ft_strjoin(3, strs5, "");
    printf("Test 5: \"%s\"\n", result5); // Expected: "OneTwoThree"
    free(result5);

    // Test Case 6: Large number of strings
    char *strs6[] = {"A", "B", "C", "D", "E", "F"};
    char *result6 = ft_strjoin(6, strs6, "-");
    printf("Test 6: \"%s\"\n", result6); // Expected: "A-B-C-D-E-F"
    free(result6);

    // Test Case 7: NULL strings in the array
    char *strs7[] = {"Hello", NULL, "world"};
    char *result7 = ft_strjoin(3, strs7, " ");
    printf("Test 7: \"%s\"\n", result7); // Expected: Undefined behavior (should handle NULL gracefully)
    free(result7);

    // Test Case 8: NULL separator
    char *strs8[] = {"Hello", "world"};
    char *result8 = ft_strjoin(2, strs8, NULL);
    printf("Test 8: \"%s\"\n", result8); // Expected: Undefined behavior (should handle NULL gracefully)
    free(result8);

    return 0;
}
/*
	i = 0;
	while (i < tot_len)
	{
		j =0;
		while (strs[i][j])
		{
			mystring[i] = strs[i][j]
			j  ++;
			i ++;
		}
		j =0;
		while (sep[j] && (size-1))

			mystring[i] = sep[j];
			j ++;
			i ++;
		}
		size --;
	}
	mywstring [i] = '\0';
	return (mystring);
*/	

