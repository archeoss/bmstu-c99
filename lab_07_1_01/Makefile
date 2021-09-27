CC := gcc
KEYS := -g -Wall -Werror -Wredundant-decls -std=c99 -Wsign-conversion -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla
ODIR := ./out
SRCDIR := ./src
INCDIR := ./inc
U_SRCDIR := ./unit_tests
U_INCDIR := ./unit_tests/inc
OBJS := $(ODIR)/readme.o $(ODIR)/sort.o

all : app.exe

app.exe : $(OBJS) $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/sort.o : $(SRCDIR)/sort.c $(INCDIR)/sort.h
	$(CC) $(KEYS) -c $(SRCDIR)/sort.c  -o $@

$(ODIR)/readme.o : $(SRCDIR)/readme.c $(INCDIR)/readme.h
	$(CC) $(KEYS) -c $(SRCDIR)/readme.c  -o $@

$(ODIR)/main.o : $(SRCDIR)/main.c
	$(CC) $(KEYS) -c $^ -o $@

unit_tests.exe : $(ODIR)/readme.o $(ODIR)/check_readme.o $(ODIR)/sort.o $(ODIR)/check_sort.o $(ODIR)/check_main.o
	$(CC) $^ -o $@ -pthread -lcheck -pthread -lrt -lm 

$(ODIR)/check_readme.o : $(U_SRCDIR)/check_readme.c $(U_INCDIR)/check_readme.h
	$(CC) $(KEYS) -c $(U_SRCDIR)/check_readme.c -o $@

$(ODIR)/check_sort.o : $(U_SRCDIR)/check_sort.c $(U_INCDIR)/check_sort.h
	$(CC) $(KEYS) -c $(U_SRCDIR)/check_sort.c -o $@

$(ODIR)/check_main.o : $(U_SRCDIR)/check_main.c
	$(CC) $(KEYS) -c $^ -o $@

clean :
	rm -f $(ODIR)/*.o *.exe
