/******************************************************************************/
/*                                                                            */
/*                         File: main.c                                       */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 14th April 2020 1:15:54 am                   */
/*                Last Modified: 14th April 2020 1:16:21 am                   */
/*                                                                            */
/******************************************************************************/

#include <io.h>
#include "../include/sparse_matrix.h"

#define BUF_SIZE 4096

int		dr_getchar(void)
{
	static char	buf[BUF_SIZE];
	static char	*bufp = buf;
	static int	n;

	if (n == 0)
	{
		n = read(0, buf, BUF_SIZE);
		bufp = buf;
	}
	n--;
	if (n >= 0)
		return (*bufp++);
	return (-1);
}

char	*dr_getstr(void)
{
	int			c;
	static char	*str;
	int			i;

	if (str != NULL)
		free(str);
	if (str = (char*)malloc(BUF_SIZE * sizeof(char)))
	{
		i = 0;
		while ((c = dr_getchar()) > 0)
		{
			str[i] = c;
			if (str[i] == '\n')
				break;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

int		dr_pow(int base, int power)
{
	int result;

	result = 1;
	if (power == 0)
		return (1);
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

int		dr_atoi(char *str)
{
	int i;
	int j;
	int minus;
	int number;

	i = 0;
	minus = 0;
	if (str[i] == '-')
	{
		minus = 1;
		str++;
	}
	if (str[i] == 'x')
	{
		return (-2147483648);
	}
	while (str[i] != '\0')
		i++;
	j = 0;
	number = 0;
	while (j < i)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			number = number + (str[j] - 48) * dr_pow(10, i - j - 1);
		}
		j++;
	}
	if (minus == 1)
		return (-number);
	return (number);
}

void	print_sp_as_array(t_sp_matrix *mtr)
{
	int i;
	int j;
	int **array;

	array = dr_spto_array(mtr);
	i = 0;
	while (i < dr_list_size(mtr->jr))
	{
		j = 0;
		dr_putstr("\t");
		while (j < dr_list_size(mtr->jc))
		{
			dr_putnbr(array[i][j]);
			dr_putstr("\t ");
			j++;
		}
		free(array[i]);
		dr_putstr("\n");
		i++;
	}
	free(array);
}

int		spmatrix_input(t_sp_matrix **mtr)
{
	int		i;
	int		size;

	*mtr = init_spmatrix();
	dr_putstr("\tInput quantity of nonzero elements: ");
	size = dr_atoi(dr_getstr());
	i = 0;
	while (i < size)
	{
		dr_putstr("\t Index: ");
		dr_putnbr(i);
		dr_putstr("\tinput AN: ");
		dr_push_tail(&((*mtr)->an), dr_atoi(dr_getstr()));
		dr_putstr("\t\t\tinput NR: ");
		dr_push_tail(&((*mtr)->nr), dr_atoi(dr_getstr()));
		dr_putstr("\t\t\tinput NC: ");
		dr_push_tail(&((*mtr)->nc), dr_atoi(dr_getstr()));
		i++;
	}
	dr_putstr("\tInput quantity of rows: ");
	size = dr_atoi(dr_getstr());
	dr_putstr("\tInput x for empty row: ");
	i = 0;
	while (i < size)
	{
		dr_putstr("\t Row: ");
		dr_putnbr(i);
		dr_putstr("\t\t\tinput JR: ");
		dr_push_tail(&((*mtr)->jr), dr_atoi(dr_getstr()));
		i++;
	}
	dr_putstr("\tInput quantity of columns: ");
	size = dr_atoi(dr_getstr());
	dr_putstr("\tInput x for empty column: ");
	i = 0;
	while (i < size)
	{
		dr_putstr("\t Column: ");
		dr_putnbr(i);
		dr_putstr("\t\t\tinput JC: ");
		dr_push_tail(&((*mtr)->jc), dr_atoi(dr_getstr()));
		i++;
	}
	dr_putstr("\n");
	dr_print_spmatrix(*mtr);
	dr_putstr("\nUnpack:\n");
	print_sp_as_array(*mtr);
}

char	parse_input()
{
	int		i;
	char	*str;

	str = dr_getstr();
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'A')
			return ('A');
		if (str[i] == 'B')
			return ('B');
		if (str[i] == '+')
			return ('+');
		if (str[i] == 'q')
			return ('q');
		i++;
	}
	return (-1);
}

int	main(void)
{
	t_sp_matrix	*sparse_matrix_a;
	t_sp_matrix	*sparse_matrix_b;
	char 		ch;

	ch = 1;
	while(1)
	{
		if (ch > 0)
		{
			dr_putstr("Press 'a' for A matrix input.\n");
			dr_putstr("Press 'b' for B matrix input.\n");
			dr_putstr("Press 'A' for A matrix input (KRM).\n");
			dr_putstr("Press 'B' for B matrix input (KRM).\n");
			dr_putstr("Press '+' for A + B sum (destination matrix A).\n");
			dr_putstr("Press 'q' for quit.\n");
		}
		ch = parse_input();
		switch (ch)
		{
		case 'a':
			break;
		case 'b':
			break;
		case 'A':
			dr_putstr("\n\tInput A (KRM):\n");
			spmatrix_input(&sparse_matrix_a);
			break;
		case 'B':
			dr_putstr("\n\tInput B (KRM):\n");
			spmatrix_input(&sparse_matrix_b);
			break;
		case '+':
		{
			dr_putstr("\n\tSum A + B:\n");
			sparse_matrix_a = dr_spmatrix_sum(sparse_matrix_a, sparse_matrix_b);
			dr_print_spmatrix(sparse_matrix_a);
			dr_putstr("\nUnpack:\n");
			print_sp_as_array(sparse_matrix_a);
			break;
		}
		case 'q':
		{
			dr_putstr("\n");
			return (0);
			break;
		}
		default:
		{
			dr_putstr("\n\tWrong input\n");
			ch = 1;
			continue;
			break;
		}
		}
	}
	return (-1);
}
