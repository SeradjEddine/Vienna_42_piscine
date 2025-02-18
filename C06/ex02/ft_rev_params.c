#include <unistd.h>

int main (int ac, char **av)
{
	int len;

	while (ac > 1)
	{
		len = 0;
		while (av[ac - 1][len] != '\0')
		{
			len ++;
		}
		write (1, av[ac - 1], len);
		write (1,"\n",1);
		ac--;
	}
	return (0);
}
