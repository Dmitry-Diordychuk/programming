/******************************************************************************/
/*                                                                            */
/*                         File: sparse_matrix_test.c                         */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 24th March 2020 10:27:26 pm                  */
/*                Last Modified: 25th March 2020 2:22:28 pm                   */
/*                                                                            */
/******************************************************************************/

#include "../include/sparse_matrix.h"
#include <stdio.h>

int		main(void)
{
	int matrix[4][4] = {	{0, 6, 0, 0},
				{9, 4, 0, 7},
				{5, 0, 0, 0},
				{0, 2, 0, 8}	};
	t_sp_matrix *sparse_matrix;
	int **array;
	int i;
	int j;

	sparse_matrix = dr_create_spmatrix(4, 4, matrix);
	dr_print_spmatrix(sparse_matrix);
	array = dr_spto_array(sparse_matrix);
	i = 0;
	while (i < dr_list_size(sparse_matrix->jr))
	{
		j = 0;
		while (j < dr_list_size(sparse_matrix->jc))
		{
			printf("%d ", array[i][j]);
			j++;
		}
		free(array[i]);
		printf("\n");
		i++;
	}
	free(array);
	dr_free_spmatrix(sparse_matrix);
	return (0);
}
