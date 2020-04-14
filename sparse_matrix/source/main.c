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

#include <unistd.h>
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
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

int		spmatrix_input(t_sp_matrix **mtr)
{
	*mtr = init_spmatrix();
	dr_putstr("Введите кол-во элементов: \n");
	//dr_putstr(dr_getstr());
	//dr_putchar('\n');
}

char	parse_input()
{
	int		i;
	char	*str;

	str = dr_getstr();
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
			dr_putstr("Введите 'A' чтобы задать матрицу A (КРМ).\n");
			dr_putstr("Введите 'B' чтобы задать матрицу B (КРМ).\n");
			dr_putstr("Введите '+' чтобы получить результат сложения матриц A и B (результат будет записан в матрицу A).\n");
			dr_putstr("Введите 'q' чтобы выйти.\n");
			dr_putstr("По окончанию ввода нажмите CTRL+D\n");
		}
		ch = parse_input();
		switch (ch)
		{
		case 'A':
			dr_putstr("\nВвод матрицы A (КРМ):\n");
			spmatrix_input(&sparse_matrix_a);
			break;
		case 'B':
			dr_putstr("\nВвод матрицы B (КРМ)\n");
			spmatrix_input(&sparse_matrix_b);
			break;
		case '+':
			dr_putstr("\nСложение матрицы A и B\n");
			break;
		case 'q':
		{
			dr_putstr("\n");
			return (0);
		}
		default:
		{
			dr_putstr("\nНеверный ввод\n");
			continue;
			break;
		}
		}
	}
}
