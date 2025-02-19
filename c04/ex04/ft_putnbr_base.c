#include <unistd.h>

void rev_str(char *buf, int len)
{
	int	i;
	char	tmp;
	i = 0;
	while (i < len / 2)
	{

		tmp = buf[i];
		buf[i] = buf[len - i - 1];
		buf[len - i - 1] = tmp;
		i++;
	}
}

int check_base(char *b, int *len)
{
	int	j;

	*len = 0;
	while (b[*len])
	{
		if (b[*len] == '+' || b[*len] == '-')
			return 0;

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

void convert(int n, char *b, int blen, char *buf, int *i)
{
	if (n == 0)
		buf[(*i)++] = b[0];
	else
	{
		while (n > 0)
		{
			buf[(*i)++] = b[n % blen];
			n /= blen;
		}
	}
}

void handle_negative(int *nbr, char *buf, int *i, char *base, int blen)
{
	if (*nbr == -2147483648)
	{
		buf[(*i)++] = base[-(*nbr % blen)];
		*nbr = -(*nbr / blen);
	}
	else
		*nbr = -(*nbr);
}

void ft_putnbr_base(int nbr, char *base)
{
	char	buf[33];
	int	i;
	int	blen;
	int	neg;

	i = 0;
	blen = 0;
	neg = 0;
	if (!check_base(base, &blen))
		return;
	if (nbr < 0)
	{
		neg = 1;
	handle_negative(&nbr, buf, &i, base, blen);
	}
	convert(nbr, base, blen, buf, &i);
	if (neg)
		buf[i++] = '-';
	buf[i] = '\0';
	rev_str(buf, i);
	write(1, buf, i);
}

int main()
{
    ft_putnbr_base(-123, "0123456789");
    write(1, "\n", 1);

    ft_putnbr_base(-2147483648, "01");
    write(1, "\n", 1);

    ft_putnbr_base(255, "0123456789ABCDEF");
    write(1, "\n", 1);

    ft_putnbr_base(0, "0123456789");
    write(1, "\n", 1);

    return 0;
}
