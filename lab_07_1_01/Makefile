CC := gcc
KEYS := -Wall -Werror -Wredundant-decls -std=c99 -Wsign-conversion -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla
ODIR := ./out
SRCDIR := ./src
INCDIR := ./inc
UNDIR := ./unit_tests
OBJS := $(ODIR)/readme.o $(ODIR)/sort.o

app.exe : $(OBJS) $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/sort.o : $(SRCDIR)/sort.c $(INCDIR)/sort.h
	$(CC) $(KEYS) -c $(SRCDIR)/sort.c  -o $@

$(ODIR)/readme.o : $(SRCDIR)/readme.c $(INCDIR)/readme.h
	$(CC) $(KEYS) -c $(SRCDIR)/readme.c  -o $@

$(ODIR)/main.o : $(SRCDIR)/main.c
	$(CC) $(KEYS) -c $^ -o $@

clean :
	rm -f $(ODIR)/*.o *.exe

func : 
	