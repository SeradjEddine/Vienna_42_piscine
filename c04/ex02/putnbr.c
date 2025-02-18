#include <unistd.h>

void swap (char *buffer,int start,int end)
{
	char tmp;

	while (start < end)
	{
		tmp = buffer [start];
		buffer [start] = buffer[end];
		buffer [end] = tmp;
		start ++;
		end --;
	}
}

void strfy(int num, char *buffer, int i)
{
	int	digit;
	int	start;
	int	end;

	start = i;
	while (num != 0)
	{
		digit = num % 10;
		buffer[i] = '0' + digit;
		i ++;
		num /= 10;
        }
        end = i - 1;
	swap (buffer, start, end);	
	buffer[i] = '\0';
}

void ft_putnbr(int nb)
{
	char buffer [12];
	int len;
	int i;
	
	i = 0;
	if (nb == 0)
	{
        	buffer[i] = '0';
		i++;
	}
	else if (nb < 0) 
	{
		buffer[i] = '-';
		nb = -nb;
		i ++;
        }

	strfy(nb, buffer, i);
	len = 0;
	while (buffer[len] != '\0')
		len ++;
	write (1, buffer, len);
}

//int main() {ft_putnbr(-4200013);}
