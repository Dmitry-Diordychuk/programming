/*****************************************************************************/
/*	Dmitry Diordichuk                                                    */
/*	cort@mail.ru                                                         */
/* 	Thu Mar 19 15:37:42 MSK 2020                                         */
/*****************************************************************************/

#include "sparse_matrix.h"

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
	(*t)->jr = NULL;
	(*t)->jc = NULL;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (i < n && j == 0)
				dr_push_tail(&((*t)->jr), zro);
			if (j < m && i == 0)
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

