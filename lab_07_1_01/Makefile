CC := gcc
KEYS := -g -Wall -Werror -Wredundant-decls -std=c99 -Wsign-conversion -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla
ODIR := ./out
SRCDIR := ./src
INCDIR := ./inc
U_SRCDIR := ./unit_tests
U_INCDIR := ./unit_tests/inc
CMPDIR := ./compare
OBJS := $(ODIR)/io.o $(ODIR)/sort.o

all : app.exe

app.exe : $(OBJS) $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/sort.o : $(SRCDIR)/sort.c $(INCDIR)/sort.h
	$(CC) $(KEYS) -c $(SRCDIR)/sort.c  -o $@

$(ODIR)/io.o : $(SRCDIR)/io.c $(INCDIR)/io.h
	$(CC) $(KEYS) -c $(SRCDIR)/io.c  -o $@

$(ODIR)/main.o : $(SRCDIR)/main.c
	$(CC) $(KEYS) -c $^ -o $@

unit_tests.exe : $(ODIR)/io.o $(ODIR)/check_io.o $(ODIR)/sort.o $(ODIR)/check_sort.o $(ODIR)/check_main.o
	$(CC) $^ -o $@ -lcheck -lrt -lm 

$(ODIR)/check_io.o : $(U_SRCDIR)/check_io.c $(U_INCDIR)/check_io.h
	$(CC) $(KEYS) -c $(U_SRCDIR)/check_io.c -o $@

$(ODIR)/check_sort.o : $(U_SRCDIR)/check_sort.c $(U_INCDIR)/check_sort.h
	$(CC) $(KEYS) -c $(U_SRCDIR)/check_sort.c -o $@

$(ODIR)/check_main.o : $(U_SRCDIR)/check_main.c
	$(CC) $(KEYS) -c $^ -o $@

compare.exe : $(ODIR)/io.o $(ODIR)/sort.o $(ODIR)/cmp_main.o
	$(CC) $(KEYS) $^ -o $@ 

$(ODIR)/cmp_main.o : $(CMPDIR)/cmp_main.c
	$(CC) $(KEYS) -c $^ -o $@

clean :
	rm -f $(ODIR)/*.o *.exe
