// Dmitry Diordichuk
// cort@mail.ru
// Wed Mar 18 20:20:00 STD 2020

#include "dr_print.h"

void	dr_putchar(char c)
{
	write(1, &c, 1);
}

void	dr_putstr(char *str)
{
	while (*str != '\0')
		dr_putchar(*str++);
}

void	dr_putnbr(int n)
{
	char	str[10];
	int	i;
	int	digit;
	int	minus;

	minus = 1;
	if (n == -2147483648)
		dr_putstr("-2147483648");
	if (n == -2147483648)
		return ;
	if (n < 0 || (i = 0))
		minus = -1;
	n *= minus;
	while (n)
	{
		digit = n % 10;
		str[i++] = digit + '0';
		n = n / 10;
	}
	if (i == 0)
		dr_putchar('0');
	while (i + 1)
		dr_putchar(str[i--]);
	if (minus == -1)
		dr_putchar('-');
}

