/*****************************************************************************/
/*	Dmitry Diordichuk                                                    */
/*	cort@mail.ru                                                         */
/* 	Sun Mar 22 21:43:37 MSK 2020                                         */
/*****************************************************************************/

#ifndef __SPARSE_MATRIX_H__
# define __SPARSE_MATRIX_H__

# include "dr_list.h"
# include "dr_print.h"
# include "dr_ring.h"

# define zro -2147483648

typedef struct	s_krm
{
	t_list 	*an;
	t_list	*nr;
	t_list	*nc;
	t_list	*jr;
	t_list	*jc;
}		t_sp_matrix;

t_sp_matrix	*init_spmatrix();
t_sp_matrix	*dr_create_spmatrix(int n, int m, int ar[n][m]);
void		dr_print_spmatrix(t_sp_matrix *matrix);
void		dr_free_spmatrix(t_sp_matrix *mtr);

void		fill_an(t_sp_matrix **mtr, int n, int m, int ar[n][m]);
void		fill_jr_jc(t_sp_matrix **t, int n , int m, int ar[n][m]);
void		indxarr_initnrnc(t_sp_matrix **t, int n, int m, int ar[n][m]);
void		fill_nr(t_sp_matrix **mtr, int n, int m, int ar[n][m]);
void		fill_nc(t_sp_matrix **mtr, int n, int m, int ar[n][m]);

int			dr_get_ij(t_sp_matrix *mtr, int i, int j);
int			*dr_get_sprow(t_sp_matrix *mtr, int i);
int			**dr_spto_array(t_sp_matrix *mtr);
t_list		*get_line_indexes(t_list *jr_or_jc, t_list *nr_or_nc, int line_index);


#endif

