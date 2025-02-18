#include <unistd.h>

int main (int ac, char **av)
{
	int len;
	int i;

	i = 1;
	while (i < ac)
	{
		len = 0;
		while (av[i][len] != '\0')
		{
			len ++;
		}
		write (1, av[i], len);
		write (1,"\n",1);
		i++ ;
	}
	return (0);
}
