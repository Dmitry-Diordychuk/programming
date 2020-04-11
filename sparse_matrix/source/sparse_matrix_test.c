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

int	main(void)
{
	int matrix_a[4][6] = {
		{ 0, 0, 2, 0,-1, 0},
		{ 4, 0, 3, 3, 7, 0},
		{-2, 0, 0, 0, 0,-1},
		{ 0, 1, 0, 1, 0, 0}
		// { 0, 0, 0, 0, 0, 0},
		// { 0, 0, 0, 0, 0, 0},
		// { 0, 0, 0, 0, 0, 0},
		// { 0, 0, 0, 0, 0, 0},
	};
	int matrix_b[4][6] = {
		{1, 0,-1, 0, 0, 5},
		{0, 0, 0, 0,-2, 0},
		{4, 6, 0, 2, 0, 0},
		{0,-1, 1, 0, 0, 0}
		// {0, 0, 0, 0, 0, 0},
		// {0, 0, 0, 0, 0, 0},
		// {0, 0, 0, 0, 0, 0},
		// {0, 0, 0, 0, 0, 0}
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
	dr_putstr("Sum spare matrixies:\n");
	sum = dr_spmatrix_sum(sparse_matrix_a, sparse_matrix_b);
	dr_print_spmatrix(sum);
	dr_putstr("\n-------------------------------------------------------------\n");
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
