/******************************************************************************/
/*                                                                            */
/*                         File: sparse_matrix_test.c                         */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 24th March 2020 10:27:26 pm                  */
/*                Last Modified: 26th March 2020 6:09:15 pm                   */
/*                                                                            */
/******************************************************************************/

#include "../include/sparse_matrix.h"
#include "../include/test.h"

// t_sp_matrix	*dr_spmatrix_sum(t_sp_matrix *a, t_sp_matrix *b)
// {
// 	int			i;
// 	int			j;
// 	int			k;
// 	int			sum;
// 	t_sp_matrix	*c;
// 	t_list		*a_in;
// 	t_list		*a_col;
// 	t_list		*b_in;
// 	t_list		*b_col;

// 	i = 0;
// 	c = init_spmatrix();
// 	while (i < dr_list_size(a->jr))
// 	{
// 		a_in = get_line_indexes(a->jr, a->nr, i);
// 		a_col = get_col_coor(a_in, a);
// 		b_in = get_line_indexes(b->jr, b->nr, i);
// 		b_col = get_col_coor(b_in, b);

// 		j = 1;
// 		k = 1;
// 		while ((j < dr_list_size(a_in) + 1) || (k < dr_list_size(b_in) + 1))
// 		{
// 			if ((j < dr_list_size(a_in) + 1)
// 				&& dr_list_at(a_col, j)->number < dr_list_at(b_col, k)->number)
// 			{
// 				dr_push_tail(&(c->an), dr_list_at(a->an, dr_list_at(a_in, j)->number + 1)->number);
// 				j++;
// 			}
// 			else if ((k < dr_list_size(b_in) + 1)
// 				&& dr_list_at(b_col, k)->number < dr_list_at(a_col, j)->number)
// 			{
// 				dr_push_tail(&(c->an), dr_list_at(b->an, dr_list_at(b_in, k)->number + 1)->number);
// 				k++;
// 			}
// 			else if (((j < dr_list_size(a_in) + 1) && (k < dr_list_size(b_in) + 1))
// 				&& dr_list_at(b_col, k)->number == dr_list_at(a_col, j)->number)
// 			{
// 				if (sum = dr_list_at(a->an, dr_list_at(a_in, j)->number + 1)->number
// 										+ dr_list_at(b->an, dr_list_at(b_in, k)->number + 1)->number)
// 				{
// 					dr_push_tail(&(c->an), sum);
// 				}
// 				j++;
// 				k++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (c);
// }

// int		*merge_ab(t_list **a_in, t_list *b_in, t_list **a_col, t_list *b_col)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	while (i < dr_list_size(*a_in) + 1)
// 	{
// 		j = 1;
// 		while (j < dr_list_size(b_in) + 1)
// 		{

// 		}
// 		i++;
// 	}
// }

int				main(void)
{
	int matrix_a[4][6] = {
		{ 0, 0, 2, 0,-1, 0},
		{ 4, 0, 3, 3, 7, 0},
		{-2, 0, 0, 0, 0,-1},
		{ 0, 1, 0, 1, 0, 0}
	};
	int matrix_b[4][6] = {
		{1, 0,-1, 0, 0, 5},
		{0, 0, 0, 0,-2, 0},
		{4, 6, 0, 2, 0, 0},
		{0,-1, 1, 0, 0, 0}
	};
	t_sp_matrix	*sparse_matrix_a;
	t_sp_matrix	*sparse_matrix_b;
	t_sp_matrix *sum;
	int			**array_a;
	int			**array_b;
	int			i;
	int			j;
	t_list		*line_indexies;
	t_list		*col_cor;

	dr_putstr("Array to sparse matrix:\n");
	sparse_matrix_a = dr_create_spmatrix(4, 6, matrix_a);
	sparse_matrix_b = dr_create_spmatrix(4, 6, matrix_b);
	dr_print_spmatrix(sparse_matrix_a);
	dr_putstr("-------------------------------------------------------------\n");
	dr_print_spmatrix(sparse_matrix_b);
	dr_putstr("-------------------------------------------------------------\n");
	dr_putstr("List find elements coordinates:\n");
	line_indexies = get_line_indexes(sparse_matrix_a->jr, sparse_matrix_a->nr, 3);
	dr_print_list(line_indexies);
	col_cor = get_col_coor(line_indexies, sparse_matrix_a);
	dr_print_list(col_cor);
	dr_putstr("-------------------------------------------------------------\n");
	// dr_putstr("Sum spare matrixies:\n");
	// sum = dr_spmatrix_sum(sparse_matrix_a, sparse_matrix_b);
	// dr_print_spmatrix(sum);
	// dr_putstr("\n-------------------------------------------------------------\n");
	dr_putstr("Sparse matrix to array:\n");
	array_a = dr_spto_array(sparse_matrix_a);
	i = 0;
	while (i < dr_list_size(sparse_matrix_a->jr))
	{
		j = 0;
		dr_putstr("\t");
		while (j < dr_list_size(sparse_matrix_a->jc))
		{
			dr_putnbr(array_a[i][j]);
			dr_putstr("\t ");
			j++;
		}
		free(array_a[i]);
		dr_putstr("\n");
		i++;
	}
	free(array_a);
	dr_putstr("-------------------------------------------------------------\n");
	array_b = dr_spto_array(sparse_matrix_b);
	i = 0;
	while (i < dr_list_size(sparse_matrix_b->jr))
	{
		j = 0;
		dr_putstr("\t");
		while (j < dr_list_size(sparse_matrix_b->jc))
		{
			dr_putnbr(array_b[i][j]);
			dr_putstr("\t ");
			j++;
		}
		free(array_b[i]);
		dr_putstr("\n");
		i++;
	}
	free(array_b);
	dr_putstr("List tests:\n");
	list_main();
	dr_free_spmatrix(sparse_matrix_a);
	return (0);
}
