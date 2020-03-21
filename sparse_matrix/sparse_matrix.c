// Dmitry Diordichuk
// cort@mail.ru
// Thu Mar 19 15:37:42 MSK 2020

#include "include/dr_list.h"
#include "include/dr_print.h"
#include "include/dr_ring.h"

#define zro -2147483648

typedef struct	s_krm 
{
	t_list 	*an;
	t_list	*nr;
	t_list	*nc;
	t_list	*jr;
	t_list	*jc;
}		t_sp_matrix;

t_sp_matrix	*init_spmatrix()
{
	t_sp_matrix *new_matrix;

	new_matrix = (t_sp_matrix*)malloc(sizeof(t_sp_matrix));
	if (new_matrix)
	{
		new_matrix->an = NULL;
		new_matrix->nr = NULL;
		new_matrix->nc = NULL;
		new_matrix->jr = NULL;
		new_matrix->jr = NULL;
	}
	return (new_matrix);
}

void		dr_print_spmatrix(t_sp_matrix *matrix)
{
	dr_putstr("\tAN: ");
	if (matrix->an)
		dr_print_list(matrix->an);
	dr_putstr("\tNR: ");
	if (matrix->nr)
		dr_print_list(matrix->nr);
	dr_putstr("\tNC: ");
	if (matrix->nc)
		dr_print_list(matrix->nc);
	dr_putstr("\tJR: ");
	if (matrix->jr)
		dr_print_list(matrix->jr);
	dr_putstr("\tJC: ");
	if (matrix->jc)
		dr_print_list(matrix->jc);
}

void		fill_an_jr(t_sp_matrix **mtr, int n, int m, int ar[n][m])
{
	int i;
	int j;
	int flag_jr;
	int counter;

	i = 0;
	counter = 0;
	while (i < n)
	{
		j = 0;
		flag_jr = 0;
		while (j < m)
		{
			if (ar[i][j] != 0)
			{
				if (flag_jr == 0)
					dr_push_tail(&((*mtr)->jr), counter);
				flag_jr = 1;
				dr_push_tail(&((*mtr)->an), ar[i][j]);
				counter++;
			}
			j++;
		}
		i++;
	}
}

void		fill_jc(t_sp_matrix **t, int n , int m, int ar[n][m])
{
	int i;
	int j;
	int flag_jc;
	int k;

	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (j < n && i == 0)
				dr_push_tail(&((*t)->jc), zro);
			if (ar[i][j] != 0)
			{
				if (dr_list_at((*t)->jc, j + 1)->number == zro)
					dr_list_change((*t)->jc, k, j + 1); 
				k++;
			}
			j++;
		}
		i++;
	}
}

void		fill_nr(t_sp_matrix **mtr, int n, int m, int ar[n][m])
{
	int i;
	int j;
	int i_start;
	int k;

	k = 0;
	while (j <= dr_list_last((*mtr)->jr)->number)
	{
		i_start = dr_list_at((*mtr)->jr, 1 + k)->number;
		i = dr_list_at((*mtr)->jr, 1 + k)->number;
		if (i == dr_list_last((*mtr)->jr)->number)
			j = dr_list_size((*mtr)->an);
		else
			j = dr_list_at((*mtr)->jr, 2 + k)->number;
		while (i < j)
		{
			if (i == j - 1)
				dr_push_tail(&((*mtr)->nr), i_start);
			else
				dr_push_tail(&((*mtr)->nr), i + 1);
			i++;
		}
		k++;
	}
}

int		getnext(int m, int ar[m] ,int x)
{
	int i;

	i = x;
	while (1)
	{
		i = (i + 1) % m;
		if (ar[i] != 0)
		{
			return (i);
		}
		i++;
	}
}

t_sp_matrix	*dr_create_spmatrix(int n, int m, int ar[n][m])
{
	t_sp_matrix	*matrix;

	matrix = init_spmatrix();
	fill_an_jr(&matrix, n, m, ar);
	fill_jc(&matrix, n, m, ar);
	fill_nr(&matrix, n, m, ar);
	return (matrix);
}

int		main(void)
{
	int matrix[4][4] = {	{0, 6, 0, 0},
				{9, 4, 0, 7},
				{5, 0, 0, 0},
				{0, 2, 0, 8}	};

	int an[7] = {6, 9, 4, 7, 5, 2, 8};
	int nr[7] = {1, 3, 4, 2, 5, 7, 6};
	int nc[7] = {3, 5, 6, 7, 2, 1, 4};
	int jr[4] = {1, 2, 5, 6};
	int jc[4] = {2, 1, 0, 4};
	t_sp_matrix *sparse_matrix;

	sparse_matrix = dr_create_spmatrix(4, 4, matrix);
	dr_print_spmatrix(sparse_matrix);
	return (0);
}
