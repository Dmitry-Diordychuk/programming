/******************************************************************************/
/*                                                                            */
/*                         File: sparse_matrix_unpackaging.c                  */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 26th March 2020 4:21:20 pm                   */
/*                Last Modified: 26th March 2020 4:26:36 pm                   */
/*                                                                            */
/******************************************************************************/

#include <sparse_matrix.h>

t_list	*get_line_indexes(t_list *jr_or_jc, t_list *nr_or_nc, int line_index)
{
	t_list	*elist;
	int		start;
	int		next;

	elist = NULL;
	if ((start = dr_list_at(jr_or_jc, line_index + 1)->number) == zro)
		return (elist = NULL);
	next = dr_list_at(nr_or_nc, start + 1)->number;
	dr_push_tail(&elist, next);
	while (next != start)
	{
		next = dr_list_at(nr_or_nc, next + 1)->number;
		dr_push_tail(&elist, next);
	}
	return (elist);
}

int		dr_get_ij(t_sp_matrix *mtr, int i, int j)
{
	t_list	*list_i;
	t_list	*list_j;
	t_list	*list_ij;

	list_i = get_line_indexes(mtr->jr, mtr->nr, i);
	list_j = get_line_indexes(mtr->jc, mtr->nc, j);
	list_ij = dr_list_intersection(list_i, list_j);
	if (list_ij == NULL)
		return (0);
	return (dr_list_at(mtr->an, list_ij->number + 1)->number);
}

int		*dr_get_sprow(t_sp_matrix *mtr, int i)
{
	int *row;
	int j;

	row = (int*)malloc(sizeof(int) * dr_list_size(mtr->jc));
	j = 0;
	while (j < dr_list_size(mtr->jc))
	{
		row[j] = dr_get_ij(mtr, i, j);
		j++;
	}
	return (row);
}

int		**dr_spto_array(t_sp_matrix *mtr)
{
	int **array;
	int i;

	array = (int**)malloc(sizeof(int*) * dr_list_size(mtr->jr));
	i = 0;
	while (i < dr_list_size(mtr->jr))
	{
		array[i] = dr_get_sprow(mtr, i);
		i++;
	}
	return (array);
}
