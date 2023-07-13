#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree obj;
    cout << "Enter LKP:\n";
    obj.read_ptr(obj.ptr_lkp); //ввод лкп обхода
    cout << "Enter LPK:\n";
    obj.read_ptr(obj.ptr_lpk); //ввод лпк обхода
    obj.zero_ptr(); //установка массивов для клп в нулевые значения, чтобы в них не было мусора
    obj.make_tree(obj.ptr_lpk[obj.ptr_len-1], 1, 0, obj.ptr_len-1, 0); //заполнение одного массива обходом клп, а второго "уровнем" соответственно бинарному дереву под каждое место первого массива
    obj.draw(); //рисовка дерева
    obj.print_klp(); //вывод клп
}
