#include "ft_stock_str.h"
#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	char c = (nb % 10) + '0';
	write(1, &c, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
	int i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
