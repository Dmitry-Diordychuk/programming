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

int		main(void)
{
	int matrix[4][4] = {	{1, 0, 0, 1},
							{0, 0, 0, 0},
							{0, 0, 0, 0},
							{1, 0, 0, 1}	};
	t_sp_matrix *sparse_matrix;
	int **array;
	int i;
	int j;

	dr_putstr("Array to sparse matrix:\n");
	sparse_matrix = dr_create_spmatrix(4, 4, matrix);
	dr_print_spmatrix(sparse_matrix);
	array = dr_spto_array(sparse_matrix);
	dr_putstr("Sparse matrix to array:\n");
	i = 0;
	while (i < dr_list_size(sparse_matrix->jr))
	{
		j = 0;
		dr_putstr("\t");
		while (j < dr_list_size(sparse_matrix->jc))
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
	dr_putstr("List tests:\n");
	list_main();
	dr_free_spmatrix(sparse_matrix);
	return (0);
}
