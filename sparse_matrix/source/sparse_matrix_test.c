/*****************************************************************************/
/*	Dmitry Diordichuk                                                    */
/*	cort@mail.ru                                                         */
/* 	Thu Mar 19 15:37:42 MSK 2020                                         */
/*****************************************************************************/

#include "../include/sparse_matrix.h"

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

