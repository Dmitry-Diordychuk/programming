#include "../include/dr_list.h"
#include "../include/dr_print.h"
#include "../include/dr_ring.h"

int	list_main(void)
{
	t_list *list;
	t_list *last;
	int nbr = 0;
	int nbr2 = 3;
	t_list *el_at;

	list = dr_create_node(1);
	dr_push_tail(&list, 2);
	dr_push_tail(&list, 3);
	dr_push_head(&list, 4);
	last = dr_list_last(list);
	dr_loop_list(&list);
	dr_putstr("\tLoop test\t\t");
	if ((el_at = dr_list_at(list, nbr2)))
		dr_putnbr(el_at->number);
	dr_putchar('\n');
	dr_unloop_list(&list);
	dr_putstr("\tList elements:\t\t");
	dr_print_list(list);
	dr_putstr("\tList size:\t\t");
	dr_putnbr(dr_list_size(list));
	dr_putchar('\n');
	dr_putstr("\tList last element:\t");
	dr_putnbr(last->number);
	dr_putchar('\n');
	while (nbr < dr_list_size(list) + 2)
	{
		dr_putstr("\tElement number ");
		dr_putnbr(nbr);
		dr_putstr(":\t");
		if ((el_at = dr_list_at(list, nbr)))
			dr_putnbr(el_at->number);
		dr_putchar('\n');
		nbr++;
	}
	dr_list_clear(&list);
	dr_print_list(list);
	return (0);
}

