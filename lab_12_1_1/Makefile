CC := gcc
KEYS := -g -Wall -Werror -Wredundant-decls -std=c99 -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla -fPIC
ODIR := ./out
SRCDIR := ./src
INCDIR := ./inc
U_SRCDIR := ./unit_tests
U_INCDIR := ./unit_tests/inc
CMPDIR := ./compare
ST_OBJS := $(ODIR)/libio.a $(ODIR)/libsort.a
DYN_OBJS := $(ODIR)/libio.so.1 $(ODIR)/libsort.so.1
ST_LIBS := -Lout -lio -lsort
DYN_LIBS := -Lout -lio -lsort
CHECKS := $(ODIR)/check_io.o $(ODIR)/check_sort.o

all : static_app.exe dynamic_c_app.exe 

static_app : static_app.exe

static_app.exe : $(ST_OBJS) $(SRCDIR)/main.c
	$(CC) $(KEYS) -c $(SRCDIR)/main.c -o $(ODIR)/main.o
	$(CC) $(ODIR)/main.o -o $@ $(ST_LIBS)

$(ODIR)/sort.o : $(SRCDIR)/sort.c $(INCDIR)/sort.h
	$(CC) $(KEYS) -c $(SRCDIR)/sort.c  -o $@	

$(ODIR)/io.o : $(SRCDIR)/io.c $(INCDIR)/io.h
	$(CC) $(KEYS) -c $(SRCDIR)/io.c  -o $@

$(ODIR)/libsort.a : $(ODIR)/sort.o 
	ar cr $@ $^
	ranlib $@
	
$(ODIR)/libio.a : $(ODIR)/io.o
	ar cr $@ $^
	ranlib $@

dynamic_c_app.exe : $(DYN_OBJS) $(SRCDIR)/main.c
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:/home/crypto_samurai/iu7-cprog-labs-2021-romanovsimeo/lab_12_1_1/out/
	export LD_LIBRARY_PATH
	$(CC) $(KEYS) -c $(SRCDIR)/main.c -o $(ODIR)/main.o
	$(CC) $(ODIR)/main.o $(DYN_LIBS) -o $@

$(ODIR)/libsort.so.1 : $(ODIR)/sort.o 
	$(CC) -fPIC -shared -Wl,-soname,libsort.so.1 $^ -o $@
	
$(ODIR)/libio.so.1 : $(ODIR)/io.o
	$(CC) -fPIC -shared -Wl,-soname,libio.so.1 $^ -o $@ 

dynamic_l_app.exe : $(SRCDIR)/main.c $(DYN_OBJS)
	$(CC) $(SRCDIR)/main.c -o $@ -ldl

unit_tests.exe : $(DYN_OBJS) $(CHECKS) $(ODIR)/check_main.o
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:/home/crypto_samurai/iu7-cprog-labs-2021-romanovsimeo/lab_12_1_1/out/
	$(CC) $(ODIR)/check_main.o $(CHECKS) $(DYN_LIBS) -o $@ -lcheck

$(ODIR)/check_io.o : $(U_SRCDIR)/check_io.c $(U_INCDIR)/check_io.h
	$(CC) $(KEYS) -c $(U_SRCDIR)/check_io.c -o $@

$(ODIR)/check_sort.o : $(U_SRCDIR)/check_sort.c $(U_INCDIR)/check_sort.h
	$(CC) $(KEYS) -c $(U_SRCDIR)/check_sort.c -o $@

$(ODIR)/check_main.o : $(U_SRCDIR)/check_main.c
	$(CC) $(KEYS) -c $^ -o $@

clean :
	rm -f $(ODIR)/*.o $(ODIR)/*.a $(ODIR)/*.so *.exe
