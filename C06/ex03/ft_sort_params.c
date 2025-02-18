
#include <unistd.h>

void print (char *str)
{
	while (*str != '\0')
	{
		write (1, str, 1);
		str++;
	}
	write (1, "\n", 1);
}

int strcmp (char *s1, char *s2)
{

	 while (*s1 == *s2 && *s1 && *s2)
	{
		 s1++;
		 s2++;
    	}
	return (*s1 - *s2);
}
void sort_str (char **str_arr, int len)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	while (i < len-1)
	{
		j = 0;
		while (j < len - 1)
		{
			if ((strcmp (str_arr[j], str_arr [j+1])) > 0)
			{
				tmp = str_arr[j];
				str_arr [j] = str_arr[j+1];
				str_arr [j+1] = tmp;	
			}
			j ++;
		}
		i ++;
	}
}

int main (int ac, char **av)
{
	int i;

	if (ac < 2)
		return (0);
	sort_str (av + 1, ac -1);
	i = 1;
	while (i < ac)
	{
		print(av[i]);		
		i ++;
	}
}
