#include <iostream>
#include <windows.h>
#include <vector>
#include "Weak_Heap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251); // функции для работы с кириллицей (IDE CODE::BLOCKS плохо работает с кириллицей, поэтому приходится подключать соотвествущие функции
    SetConsoleOutputCP(1251);
    bool flag = true; //флаг для определения слабой кучи
    int len; //длина массива
    cout << "Введите длину массива\n";
    cin >> len;
    Weak_Heap arr;
    arr.set_len(len); //передать длину в свойство len класса
    arr.read(); //ввести массив в свойство wheap класса
    arr.read_bit(); //ввести массив в свойство bit класса
    if (arr.check_root()) //проверка значения в битовом массиве для корневого узла
    {
        arr.check(0, &flag); //рекурсивная функция определения слабой кучи
    }
    else
    {
        flag = false;
        cout << "\nКорневой узел в слабой кучи не может иметь левого потомка\n";
    }
    if (flag)
    {
        cout << "\nМассив является слабой кучей\n";
    }
    else
    {
        cout << "\nМассив не является слабой кучей\n";
    }
    return 0;
}