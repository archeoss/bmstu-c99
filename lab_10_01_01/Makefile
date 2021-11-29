CC := gcc
KEYS := -g -Wall -Werror -Wredundant-decls -std=c99 -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla
ODIR := ./out
SRCDIR := ./src
INCDIR := ./inc
U_SRCDIR := ./unit_tests/src
U_INCDIR := ./unit_tests/inc
OBJS := $(ODIR)/io.o $(ODIR)/operations.o $(ODIR)/list_operations.o $(ODIR)/sort.o
CHECKS := $(ODIR)/check_main.o $(ODIR)/check_operations.o $(ODIR)/check_list_operations.o $(ODIR)/check_io.o
LIBS := -Iinc 
U_LIBS := -Iunit_tests/inc 

all : app.exe

app.exe : $(OBJS) $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/operations.o : $(SRCDIR)/operations.c $(INCDIR)/operations.h
	$(CC) $(KEYS) -c $(SRCDIR)/operations.c -o $@ $(LIBS)

$(ODIR)/list_operations.o : $(SRCDIR)/list_operations.c $(INCDIR)/list_operations.h
	$(CC) $(KEYS) -c $(SRCDIR)/list_operations.c -o $@ $(LIBS)

$(ODIR)/io.o : $(SRCDIR)/io.c $(INCDIR)/io.h
	$(CC) $(KEYS) $(LIBS) -c $(SRCDIR)/io.c -o $@ $(LIBS)

$(ODIR)/sort.o : $(SRCDIR)/sort.c $(INCDIR)/sort.h
	$(CC) $(KEYS) $(LIBS) -c $(SRCDIR)/sort.c -o $@ $(LIBS)

$(ODIR)/main.o : $(SRCDIR)/main.c
	$(CC) $(KEYS) -c $^ -o $@ $(LIBS)

unit_tests.exe : $(CHECKS) $(OBJS)
	$(CC) $^ -o $@ -lcheck $(LIBS) $(U_LIBS)

$(ODIR)/check_io.o : $(U_SRCDIR)/check_io.c $(U_INCDIR)/check_io.h
	$(CC) $(KEYS) -c $(LIBS) $(U_LIBS) $(U_SRCDIR)/check_io.c -o $@

$(ODIR)/check_operations.o : $(U_SRCDIR)/check_operations.c $(U_INCDIR)/check_operations.h
	$(CC) $(KEYS) $(LIBS) $(U_LIBS) -c $(U_SRCDIR)/check_operations.c -o $@

$(ODIR)/check_list_operations.o : $(U_SRCDIR)/check_list_operations.c $(U_INCDIR)/check_list_operations.h
	$(CC) $(KEYS) $(LIBS) $(U_LIBS) -c $(U_SRCDIR)/check_list_operations.c -o $@

$(ODIR)/check_main.o : $(U_SRCDIR)/check_main.c
	$(CC) $(KEYS) -c $^ -o $@ $(LIBS) $(U_LIBS)

clean :
	rm -f $(ODIR)/*.o *.exe vgcore.*
