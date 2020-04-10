/******************************************************************************/
/*                                                                            */
/*                         File: sparse_matrix_sum.c                          */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 10th April 2020 8:18:00 pm                   */
/*                Last Modified: 10th April 2020 8:18:30 pm                   */
/*                                                                            */
/******************************************************************************/

#include "sparse_matrix.h"

int			*merge_ab(t_list **a_in, t_list *b_in, t_list **a_col, t_list *b_col)
{
	int i;
	int j;
	int in_pos;

	i = 1;
	while (i < dr_list_size(b_col) + 1)
	{
		in_pos = dr_list_find_predicate(*a_col, dr_list_at(b_col, i)->number,
															dr_comp_gr_or_eql);
		if (in_pos < 0)
		{
			dr_push_head(a_col, dr_list_at(b_col, i)->number);
			dr_push_head(a_in, -(dr_list_at(b_in, i)->number + 1));
		}
		dr_list_insert(a_col, in_pos, dr_list_at(b_col, i)->number);
		dr_list_insert(a_in, in_pos, -(dr_list_at(b_in, i)->number + 1));
		i++;
	}
	return (0);
}

t_list		*an_sum(t_list *in, t_list *col, t_sp_matrix *a, t_sp_matrix *b)
{
	int				i;
	int				index;
	int				value;
	t_list	*c_an;

	i = 0;
	c_an = NULL;
	while (i < dr_list_size(col))
	{
		if (dr_list_at(col, i + 2) == NULL
			|| dr_list_at(col, i + 1)->number != dr_list_at(col, i + 2)->number)
		{
			index = dr_list_at(in, i + 1)->number;
			if (index < 0)
				value = dr_list_at(b->an, -index)->number;
			else
				value = dr_list_at(a->an, index + 1)->number;
			dr_push_tail(&c_an, value);
		}
		else
		{
			value = dr_list_at(a->an, dr_list_at(in, i + 1)->number + 1)->number
				+ dr_list_at(b->an, -dr_list_at(in, i + 2)->number)->number;
			if (value != 0)
				dr_push_tail(&c_an, value);
			i++;
		}
		i++;
	}
	return (c_an);
}

t_sp_matrix	*dr_spmatrix_sum(t_sp_matrix *a, t_sp_matrix *b)
{
	int			i;
	t_sp_matrix	*c;
	t_list		*a_in;
	t_list		*a_col;
	t_list		*b_in;
	t_list		*b_col;
	t_list		*an;

	i = 0;
	c = init_spmatrix();
	while (i < dr_list_size(a->jr))
	{
		a_in = get_line_indexes(a->jr, a->nr, i);
		a_col = get_col_coor(a_in, a);
		b_in = get_line_indexes(b->jr, b->nr, i);
		b_col = get_col_coor(b_in, b);
		merge_ab(&a_in, b_in, &a_col, b_col);
		an = an_sum(a_in, a_col, a, b);
		dr_list_addlist(&c->an, an);
		free(an);
		i++;
	}
	return (c);
}

