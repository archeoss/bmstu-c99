from array import array
import ctypes as ct
import os

lib = ct.cdll.LoadLibrary(os.path.abspath("lib_py.so"))
def fill_fibonacci(n):
    _fill_fib = lib.fill_fibonacci
    _fill_fib.argtypes = (ct.POINTER(ct.c_int), ct.c_int)
    _fill_fib.restype = ct.POINTER(ct.c_int)
    array = []
    src = (n * ct.c_int)(*array)
    
    return _fill_fib(src, n)[0:n]

def fill_unique(src, n):
    _fill_uniq = lib.fill_unique
    _fill_uniq.argtypes = (ct.POINTER(ct.c_int), ct.POINTER(ct.c_int), ct.c_int, ct.POINTER(ct.c_int))
    _fill_uniq.restype = ct.POINTER(ct.c_int)
    c_src = (n * ct.c_int)(*src)
    to_copy = []
    c_tocopy = (n * ct.c_int)(*to_copy)
    c_n = ct.c_int(0)
    return _fill_uniq(c_src, c_tocopy, n, c_n)[0:c_n.value]

def main():
    array_a = []
    array_b = []
    while True:
        print("Команды:")
        print(
            "1. Заполнить массив числами Фибоначчи\n",
            "2. Заполнить массив вручную\n"
            "3. Вывести уникальные элементы из первого массива\n",
            "0. Выход\n", sep=''

        )
        command = int(input("Введите команду: "))
        if (command == 0):
            break
        elif (command == 1):
            array_a = fill_fibonacci(int(input("Введите количество чисел: ")))
            print("array_a =", array_a)
        elif (command == 2):
            array_a = []
            n = int(input("Введите количество чисел: "))
            for i in range(n):
                array_a.append(int(input("Введите число {:}: ".format(i + 1))))
            print("array_a =", array_a)
        elif (command == 3):
            array_b = fill_unique(array_a, len(array_a))
            print("array_a =", array_a)
            print("array_b =", array_b)

if __name__ == "__main__":
    main()