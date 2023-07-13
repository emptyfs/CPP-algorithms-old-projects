#include "Quick_Sort.h"

int Quick_Sort::get_len()
{
    return len;
}

void Quick_Sort::read(vector<int> arr)
{
    qheap.clear();
    for (int i = 0; i < len; i++)
    {
        qheap.push_back(arr[i]);
    }
}

void Quick_Sort::set_len(int len)
{
    this->len = len;
}

void Quick_Sort::print_sorted()
{
    cout << "\n";
    for (int i = 0; i < len; i++) //вывод отсортированного вектора
    {
        cout << qheap[i] << " ";
    }
    cout << "\n";
}

void Quick_Sort::qsort(int start, int finish, int flag)
{
    int mid = qheap[start]; //опорный элемент (элемент, относительно которого производится текущая быстрая сортировка
    int index_mid = start; //индекс опорного элемента
    int icount = finish; //переменная, с помощью которой производится обход по текущей стороне вектора
    int check = finish; //переменная, с помощью которой производится корректный вывод отсортированных эелементов
    if (flag == 1)
    {
        cout << mid <<" - текущий центральный элемент быстрой сортировки\n";
    }
    do
    {
        if (mid > qheap[check]) //если опорный элемент больше расматриваемого в цикле while, то он перемещается слева от опорного элемента
        {
            qheap.insert(qheap.begin()+index_mid, qheap[check]);
            index_mid++;
            qheap.erase(qheap.begin()+check+1);
            check++;
        }
        if (flag == 1)
        {
            print(start, finish, check, index_mid);
        }
        icount--;
        check--;
    } while (icount >= start+1);
    if (flag == 1)
    {
        cout << "текущее состояние массива:\t";
        print(0, qheap.size()-1, 0, 0); //вывод вектора в конце текущей функции
        cout << "\n\n";
    }

    if (start < index_mid-1) //вызов сортировки для левой стороны
    {
        qsort(start, index_mid-1, flag);
    }
    if (index_mid+1 < finish) //вызов сортировеи для правой стороны
    {
        qsort(index_mid+1, finish, flag);
    }
}

void Quick_Sort::print(int start, int finish, int icount, int index_mid) //вспомогательная функция для вывода вектора на консоль
{
    if (icount == 0) //вывод вектора в конце функции qsort
    {
        for (int i = 0; i <= finish; i++)
        {
            if (i == finish)
            {
                cout << qheap[i];
            }
            else
            {
                cout << qheap[i] << "-";
            }
        }
        cout << "\n";
        return;
    }
    for (int i = start; i <= finish; i++) //вывод вектора в ходе сортировки
    {
        if (i == index_mid && i != start)
        {
            cout<< "----";
        }
        else if (i == icount)
        {
            cout<< "----";
        }
        if (i == finish)
        {
            cout << qheap[finish];
        }
        else
        {
            cout << qheap[i] << "-";
        }
    }
    cout << "\n";
}