/*****************************************************************************/
/*	Dmitry Diordichuk                                                    */
/*	cort@mail.ru                                                         */
/* 	Thu Mar 19 15:37:42 MSK 2020                                         */
/*****************************************************************************/

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
	int	i;
	t_list	*index;

	i = 0;
	while (i < dr_list_size(matrix->an))
		dr_push_tail(&index ,i++);
	dr_putstr("\tIN: ");
	if (index)
		dr_print_list(index);
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
	dr_list_clear(&index);
}

void		fill_an(t_sp_matrix **mtr, int n, int m, int ar[n][m])
{
	int i;
	int j;
	int counter;

	i = 0;
	counter = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (ar[i][j] != 0)
			{
				dr_push_tail(&((*mtr)->an), ar[i][j]);
				counter++;
			}
			j++;
		}
		i++;
	}
}

void		fill_jr_jc(t_sp_matrix **t, int n , int m, int ar[n][m])
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (i < m && j == 0)
				dr_push_tail(&((*t)->jr), zro);
			if (j < n && i == 0)
				dr_push_tail(&((*t)->jc), zro);
			if (ar[i][j] != 0)
			{
				if (dr_list_at((*t)->jr, i + 1)->number == zro)
					dr_list_change((*t)->jr, k, i + 1);
				if (dr_list_at((*t)->jc, j + 1)->number == zro)
					dr_list_change((*t)->jc, k, j + 1); 
				k++;
			}
			j++;
		}
		i++;
	}
}

void		indxarr_initnrnc(t_sp_matrix **mtr, int n, int m, int ar[n][m])
{
	int 	i;
	int 	j;
	int 	index;

	i = 0;
	index = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (ar[i][j] != 0)
			{
				dr_push_tail(&((*mtr)->nr), zro);
				dr_push_tail(&((*mtr)->nc), zro);
				ar[i][j] = index++;
			}
			else
				ar[i][j] = zro;
			j++;
		}
		i++;
	}
}

void		fill_nr(t_sp_matrix **mtr, int n, int m, int ar[n][m])
{
	int 	i;
	int 	j;
	t_list	*row;

	i = 0;
	while (i < n)
	{
		j = -1;
		row = NULL;
		while (++j < m)
			if (ar[i][j] != zro)
				dr_push_tail(&row, ar[i][j]);
		j = dr_list_size(row);
		dr_loop_list(&row);
		while (j-- > 0)
		{
			dr_list_change((*mtr)->nr,
					row->next->number, row->number + 1);
			row = row->next;
		}
		dr_unloop_list(&row);
		dr_list_clear(&row);
		i++;
	}
}

void		fill_nc(t_sp_matrix **mtr, int n, int m, int ar[n][m])
{
	int 	i;
	int 	j;
	t_list	*col;

	j = 0;
	while (j < m)
	{
		i = -1;
		col = NULL;
		while (++i < n)
			if (ar[i][j] != zro)
				dr_push_tail(&col, ar[i][j]);
		i = dr_list_size(col);
		dr_loop_list(&col);
		while (i-- > 0)
		{
			dr_list_change((*mtr)->nc,
					col->next->number, col->number + 1);
			col = col->next;
		}
		dr_unloop_list(&col);
		dr_list_clear(&col);
		j++;
	}
}

t_sp_matrix	*dr_create_spmatrix(int n, int m, int ar[n][m])
{
	t_sp_matrix	*matrix;

	matrix = init_spmatrix();
	fill_an(&matrix, n, m, ar);
	fill_jr_jc(&matrix, n, m, ar);
	indxarr_initnrnc(&matrix, n, m, ar);
	fill_nr(&matrix, n, m, ar);
	fill_nc(&matrix, n, m, ar);
	return (matrix);
}

int		main(void)
{
	int matrix[4][4] = {	{0, 6, 0, 0},
				{9, 4, 0, 7},
				{5, 0, 0, 0},
				{0, 2, 0, 8}	};
	t_sp_matrix *sparse_matrix;

	sparse_matrix = dr_create_spmatrix(4, 4, matrix);
	dr_print_spmatrix(sparse_matrix);
	return (0);
}
