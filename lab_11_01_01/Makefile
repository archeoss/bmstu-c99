CC := gcc
KEYS := -g -Wall -Wredundant-decls -std=c99 -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla
ODIR := ./out
SRCDIR := ./src
INCDIR := ./inc
U_SRCDIR := ./unit_tests/src
U_INCDIR := ./unit_tests/inc
OBJS := $(ODIR)/my_string.o 
CHECKS := $(ODIR)/check_main.o $(ODIR)/check_my_string.o
LIBS := -Iinc 
U_LIBS := -Iunit_tests/inc 

all : app.exe

app.exe : $(OBJS) $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/my_string.o : $(SRCDIR)/my_string.c $(INCDIR)/my_string.h
	$(CC) $(KEYS) -c $(SRCDIR)/my_string.c -o $@ $(LIBS)

$(ODIR)/main.o : $(SRCDIR)/main.c
	$(CC) $(KEYS) -c $^ -o $@ $(LIBS)

unit_tests.exe : $(CHECKS) $(OBJS)
	$(CC) $^ -o $@ -lcheck $(LIBS) $(U_LIBS)

$(ODIR)/check_my_string.o : $(U_SRCDIR)/check_my_string.c $(U_INCDIR)/check_my_string.h
	$(CC) $(KEYS) $(LIBS) $(U_LIBS) -c $(U_SRCDIR)/check_my_string.c -o $@

$(ODIR)/check_main.o : $(U_SRCDIR)/check_main.c
	$(CC) $(KEYS) -c $^ -o $@ $(LIBS) $(U_LIBS)

clean :
	rm -f $(ODIR)/*.o *.exe vgcore.*
