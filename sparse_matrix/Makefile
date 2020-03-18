# Dmitry Diordichuk
# cort@mail.ru
# Wed Mar 18 20:23:56 STD 2020

CC=gcc
CFLAGS=-Wall -Wextra -Werror
IDIR=include/
SDIR=source/

all:

print:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_print.c 
list:
	@$(CC) -c $(CFLAGS) -I$(IDIR) $(SDIR)dr_list.c 
test: print list
	@$(CC) -c $(CFLAGS) $(SDIR)test.c
	@$(CC) dr_print.o dr_list.o test.o -o test

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf test
