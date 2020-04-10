/******************************************************************************/
/*                                                                            */
/*                         File: dr_math.c                                    */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 9th April 2020 8:28:41 pm                    */
/*                Last Modified: 9th April 2020 8:31:14 pm                    */
/*                                                                            */
/******************************************************************************/

#include "dr_math.h"

int	dr_comp(int a, int b)
{
	return (a - b);
}

int	dr_comp_gr_or_eql(int a, int b)
{
	if (a > b)
		return (1);
	if (a == b)
		return (1);
	else
		return (-1);
}
