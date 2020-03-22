/*****************************************************************************/
/*                                                                           */
/*	Dmitry Diordichuk                                                    */
/*	cort@mail.ru                                                         */
/* 	Thu Mar 19 15:37:42 MSK 2020                                         */
/*                                                                           */
/*****************************************************************************/

#include "sparse_matrix.h"

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

