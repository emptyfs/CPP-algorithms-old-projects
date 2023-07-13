#include <iostream>
#include <locale.h>
#include "List.h"

using namespace std;

int main()
{
    setlocale(0,"");

    lisp *m = new lisp();
    cout<<"Введите список:";
    read_lisp(&m);
    cout<<"Введите атом, который нужно найти:";
    base x;
    cin>>x;
    bool check = false; // переменная, которая проверяет вхождение
    find_func(&m, x, &check);
    if (check)
    {
        cout << "Элемент найден";
    }
    else
    {
        cout << "Элемент не найден";
    }
    //write_lisp(&m);
    destroy(&m);
    return 0;
}
