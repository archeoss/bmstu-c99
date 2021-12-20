CC := gcc
KEYS := -g -Wall -Werror -Wredundant-decls -std=c99 -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wvla -fPIC

all : lib_py.so

run : lib_py.so main.py
	python3 ./main.py

lib_py.so : py_lib.o 
	$(CC) -fPIC -shared $^ -o $@

py_lib.o : py_lib.c
	$(CC) $(KEYS) -c $^ -o $@

clean :
	rm -f $(ODIR)/*.o $(ODIR)/*.a $(ODIR)/*.so *.exe
