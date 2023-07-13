#include "Weak_Heap.h"

bool Weak_Heap::check_root()
{
    if (bit[0] == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Weak_Heap::read_bit()
{
    cout << "\n";
    int key;
    cout << "Введите значение родителя для битового массива\n";
    cout << "'1' - если потомки поменяны местами или '0' - если нет\n";
    cout <<"Родитель " << wheap[0] << " имеет потомков: " << wheap[1] << "\n\n";
    cout << "Для родителя " << wheap[0] <<" с индексом " << 0 << " введите значение для битового массива:\t";
    cin >> key;
    if (key == 0 || key == 1)
    {
        bit[0] = key;
    }
    for (int i = 1; i < len; i++)
    {
        if (2*i < len)
        {
            cout <<"Родитель " << wheap[i] << " имеет потомков: " << wheap[2*i];
            if (2*i+1 < len)
            {
                cout << " и " << wheap[2*i+1] << "\n";
            }
            else
            {
                cout << "\n";
            }
            cout << "Для родителя " << wheap[i] <<" с индексом " << i << " введите значение для битового массива:\t";
            cin >> key;
            if (key == 0 || key == 1)
            {
                bit[i] = key;
            }
            cout << "\n\n";
            len_bit = i+1;
        }
    }
    cout << "Получился следующий массив битов:";
    print_bit();
    cout << "\n";
}

void Weak_Heap::read()
{
    int key;
    cout << "Введите массив для проверки\n";
    for (int i = 0; i < len; i++)
    {
        cin >> key;
        wheap.push_back(key);
        bit.push_back(0);
    }
}

void Weak_Heap::print_wheap()   //метод, выводящий содержимое вектора на экран
{
    cout << "\n";
    for (int i = 0; i < len; i++)
    {
        cout << wheap[i] << " ";
    }
    cout << "\n";
}

void Weak_Heap::print_bit()
{
    cout << "\n";
    for (int i = 0; i < len_bit; i++)
    {
        cout << bit[i] << " ";
    }
    cout << "\n";
}

void Weak_Heap::set_len(int len)
{
    this->len = len;
}

void Weak_Heap::check(int index, bool* flag)
{
    if (wheap[index] < wheap[2*index+1-bit[index]] && 2*index+1-bit[index] < len) //если правый потомок больше родителя
    {
        *flag = false;
        cout << "Родитель " << wheap[index] << " меньше своего правого потомка " << wheap[2*index+1-bit[index]]<< "\n";
    }
    if (2*index+bit[index] < len && index != 0) //для левого потомка
    {
        check(2*index+bit[index], flag);
    }
    if (2*index+1-bit[index] < len)    //для правого потомка
    {
        check(2*index+1-bit[index], flag);
    }
}