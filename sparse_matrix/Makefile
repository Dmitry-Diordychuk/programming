################################################################################
#                                                                              #
#                         File: Makefile                                       #
#                   Created By: Dmitry Diordichuk                              #
#                        Email: cort@mail.ru                                   #
#                                                                              #
#                 File Created: 24th March 2020 10:27:26 pm                    #
#                Last Modified: 26th March 2020 6:09:08 pm                     #
#                                                                              #
################################################################################

CC=gcc
CFLAGS=-g #-Wall -Wextra -Werror
IDIR=include/
SDIR=source/

all: sparse math
	@$(CC) -c $(CFLAGS) $(SDIR)main.c
	@$(CC) dr_print.o dr_list.o dr_ring.o sparse_matrix.o \
	sparse_matrix_packaging.o \
	sparse_matrix_unpackaging.o \
	sparse_matrix_sum.o \
	dr_math.o \
	main.o -o spmatrix;
print:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_print.c
list:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_list.c
ring:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_ring.c
sparse: print list ring
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)sparse_matrix.c \
	$(SDIR)sparse_matrix_packaging.c \
	$(SDIR)sparse_matrix_unpackaging.c \
	$(SDIR)sparse_matrix_sum.c
math:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_math.c
test: sparse math
	@$(CC) -c $(CFLAGS) $(SDIR)test.c
	@$(CC) -c $(CFLAGS) $(SDIR)sparse_matrix_test.c
	@$(CC) dr_print.o dr_list.o dr_ring.o sparse_matrix.o \
	sparse_matrix_packaging.o \
	sparse_matrix_unpackaging.o \
	sparse_matrix_sum.o \
	sparse_matrix_test.o \
	dr_math.o \
	test.o -o test
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf test sp_test
