
#include <unistd.h>

int main (int ac, char **av)
{
	int len; 
	len = 0;
	while (av [0][len] !=0)
		len ++;
	write (1,av[0],len);
	write (1,"\n",1);	
}

