#include "Tree.h"
#include <iostream>

using namespace std;

void Tree::read_ptr(char ptr[50]) // посимвольный ввод обходов в массивы
{
    char c;
    int i = 0;
    c = getchar();
    while(c != '\n')
    {
        ptr[i] = c;
        i++;
        c = getchar();
    }
    this->ptr_len = i;
    ptr[i] = '\0';
}

void Tree::zero_ptr() //заполнения массив, чтобы в них не было мусоров
{
    for (int i = 0; i < 50; i++)
    {
        this->ptr_ready[i] = ' ';
        this->ptr_ready_ind[i] = 0;
    }
    this->ptr_ready[49] = '\0';
}

void Tree::make_tree(char root, int degree, int start, int finish, int check) // соответсвенно root - текущий корень БД, текущий "уровень" члена БД, текущий старт, текущий финиш, check - переменная, которая отслеживает, когда происходит вызов метода для правой части массива
{
    ptr_ready[place] = root;
    ptr_ready_ind[place] = degree;
    place++;
    int index_root_lkp = -1; //переменная для отслеживания индекса в массиве лкп
    int index_root_lpk = -1; //переменная для отслеживания индекса в массиве лпк
    for (int i = start; i < finish+1; i++)
    {
        if (ptr_lkp[i] == root)
        {
            index_root_lkp = i;
        }
        if (ptr_lpk[i] == root)
        {
            index_root_lpk = i;
        }
    }
    if (start == finish)
    {
        return;
    }
    if (index_root_lkp-1 >= start && check == 0)
    {
        make_tree(ptr_lpk[index_root_lkp-1], degree+1, start, index_root_lkp-1, 0); // для левой части, если до этого не было правой части
    }
    if (index_root_lkp-1 >= start && check == 1)
    {
        make_tree(ptr_lkp[index_root_lkp-1], degree+1, start, index_root_lkp-1, 0); // для левой части, если до этого была правая части
    }
    if (index_root_lkp+1 <= finish)
    {
        check = 1;
        make_tree(ptr_lpk[index_root_lpk-1], degree+1, index_root_lkp+1, finish, 1); //для правой части
    }
}

void Tree::draw()
{
    for (int i = 0; i < ptr_len; i++)
    {
        for (int j = 0; j < ptr_ready_ind[i]; j++)
        {
            cout << "--";
        }
        cout << ptr_ready[i];
        cout << "\n";
    }
    cout << "\n";
}

void Tree::print_klp()
{
    cout << "KLP:";
    for (int i = 0; i < ptr_len; i++)
    {
        cout << ptr_ready[i];
    }
}