// Dmitry Diordichuk
// cort@mail.ru
// Thu Mar 19 15:37:42 MSK 2020

#include "include/dr_list.h"
#include "include/dr_print.h"
#include "include/dr_ring.h"

typedef struct	s_krm 
{
	t_list 	*an;
	t_list	*nr;
	t_list	*nc;
	t_list	*jr;
	t_list	*jc;
}		t_sp_matrix;

t_sp_matrix	*dr_init_spmatrix()
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
	dr_print_list(matrix->an);
	dr_putstr("\tNR: ");
	dr_print_list(matrix->nr);
	dr_putstr("\tNC: ");
	dr_print_list(matrix->nc);
	dr_putstr("\tJR: ");
	dr_print_list(matrix->jr);
	dr_putstr("\tJC: ");
	dr_print_list(matrix->jc);
}

t_sp_matrix	*array_tosp_matrix(int **ar, int n, int m)
{
	t_sp_matrix	*matrix;
	int 		i;
	int 		j;

	matrix = dr_init_spmatrix();
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (ar[i][j] != 0)
			{
				dr_push_tail(matrix->an, ar[i][j]);
			}
			j++;
		}
		i++;
	}
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

	sparse_matrix = dr_init_spmatrix();
	dr_push_array(&(sparse_matrix->an), an, 7);
	dr_push_array(&(sparse_matrix->nr), nr, 7);
	dr_push_array(&(sparse_matrix->nc), nc, 7);
	dr_push_array(&(sparse_matrix->jr), jr, 4);
	dr_push_array(&(sparse_matrix->jc), jc, 4);
	dr_print_spmatrix(sparse_matrix);	
	return (0);
}
