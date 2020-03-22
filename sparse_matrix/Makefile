###############################################################################
#                                                                             #
#	Dmitry Diordichuk                                                     #
#	cort@mail.ru                                                          #
#	Wed Mar 18 20:23:56 STD 2020                                          #
#                                                                             #
###############################################################################

CC=gcc
CFLAGS=-Wall -Wextra -Werror
IDIR=include/
SDIR=source/

all: print list ring
	@$(CC) -c $(CFLAGS) sparse_matrix.c
	@$(CC) dr_print.o dr_list.o dr_ring.o sparse_matrix.o -o sp_test
print:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_print.c 
list:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_list.c 
ring:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_ring.c
sparse: print list ring
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)sparse_matrix.c \
	$(SDIR)sparse_matrix_packaging.c
test: print list ring
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)test.c
	@$(CC) dr_print.o dr_list.o dr_ring.o test.o -o test 
sptest: sparse
	@$(CC) -c $(CFLAGS) $(SDIR)sparse_matrix_test.c
	@$(CC) dr_print.o dr_list.o dr_ring.o sparse_matrix.o \
	sparse_matrix_packaging.o sparse_matrix_test.o -o sp_test
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf test sp_test
