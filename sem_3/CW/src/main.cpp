#include <iostream>
#include <windows.h>
#include <vector>
#include "Weak_Heap.h"
#include "Quick_Sort.h"
#include <random>
#include <ctime>
#include <chrono>
#include <time.h>
#include <algorithm>

using namespace std;

void panel(Weak_Heap* arr1, Quick_Sort* arr2)
{
    int key = 0;
    while (key != -1)
    {
        cout << "\nВыберите то, что хотите сделать:\n";
        cout << "1 - Запустить сортировку слабой кучей для 5-ти генерируемых массовов с указанием длины и\n";
        cout << "промежуточных представлений в виде уступчатых списков\n\n";
        cout << "2 - Запустить быструю сортировку для 5-ти генерируемых массивов с указанием длины и\n";
        cout << "промежуточных результатов массивов\n\n";
        cout << "3 - Запустить сортировку слабой кучей и быструю сортировку для 100-ста массивов\n";
        cout << "с указанием длины массивов и фиксацией времени работы,\n";
        cout << "и вывести среднее время для каждой сортировки и сравнить их\n\n";
        cout << "4 - Запустить обе сортировки для худшего и лучшего случаев и вывести их время работы\n";
        cout << "(Нужно указать длину для массивов, тогда в консоль будет выведены 4 массива соответсвующих\n";
        cout << "длин и время работы для каждого из вариантов)\n";
        cout << "(Худший случай - расстановка элементов в массиве, при котором сложность алгоритма по времени\n";
        cout << "стремится к максимально возможной)\n";
        cout << "(Лучший случай - расстановка элементов в массиве, при котором сложность алгоритма по времени\n";
        cout << "стремится к минимально возможной)\n\n";
        cout << "-1 - Завершить программу\n\n";
        cin >> key;
        if (key == -1)
        {
            return;
        }
        if (key == 1)
        {
            int len;
            cout << "Введите длину для массивов\n\n";
            cin >> len;
            for (int i = 0; i < 5; i++)
            {
                vector<int> arr;
                for (int j = 0; j < len; j++)
                {
                    arr.push_back(rand()%101);
                }
                arr1->set_len(len);
                arr1->read(arr);
                arr1->make_weak_heap();
                cout << "----------------------------------------------------------\n";
                cout << "Сгенерированный массив - ";
                for (int i = 0; i < len; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << "\n\n";
                cout << "Этот же массив, преобразованный в слабую кучу:\n";
                arr1->weak_sow(arr1->len-1, 1);
                cout << "\nОтсортированный массив:";
                arr1->print_wheap();
                cout << "----------------------------------------------------------\n";
            }
        }
        if (key == 2)
        {
            int len;
            cout << "Введите длину для массивов\n\n";
            cin >> len;
            for (int i = 0; i < 5; i++)
            {
                vector<int> arr;
                for (int j = 0; j < len; j++)
                {
                    arr.push_back(rand()%101);
                }
                arr2->set_len(len);
                arr2->read(arr);
                cout << "----------------------------------------------------------\n";
                cout << "Сгенерированный массив - ";
                for (int i = 0; i < len; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << "\n\n";
                cout << "Массив во время сортировки:\n";
                arr2->qsort(0, arr2->get_len()-1, 1);
                cout << "Отсортированный массив:\n";
                arr2->print_sorted();
                cout << "----------------------------------------------------------\n";
            }
        }
        if (key == 3)
        {
            double temp;
            double Avg_Weak_Sort = 0;
            double Avg_Quick_Sort = 0;
            int len;
            cout << "Введите длину для массивов\n\n";
            cin >> len;
            cout << "----------------------------------------------------------\n";
            cout << "\n\tN\t\tСортировка слабой кучей\t\tБыстая сортировка";
            for (int i = 0; i < 100; i++)
            {
                vector<int> arr;
                for (int j = 0; j < len; j++)
                {
                    arr.push_back(rand()%10001);
                }
                arr1->set_len(len);
                arr1->read(arr);
                arr2->set_len(len);
                arr2->read(arr);
                auto start = std::chrono::steady_clock::now();
                arr1->sort_weak();
                auto end = std::chrono::steady_clock::now();
                temp = chrono::duration<double>(end-start).count();
                Avg_Weak_Sort += temp;
                start = std::chrono::steady_clock::now();
                arr2->qsort(0, arr2->get_len()-1, 0);
                end = std::chrono::steady_clock::now();
                Avg_Quick_Sort += chrono::duration<double>(end-start).count();
                cout << "\n\t" << i << "\t\t" << temp << "\t\t\t";
                cout << chrono::duration<double>(end-start).count();
            }
            cout << "\n\nСреднее время сортировки слабой кучей: " << Avg_Weak_Sort/100 << "\n";
            cout << "Среднее время быстрой сортировки: " << Avg_Quick_Sort/100 << "\n";
            if (Avg_Weak_Sort < Avg_Quick_Sort)
            {
                cout << "\nСортировка слабой кучей в среднем быстрее\n";
            }
            else if (Avg_Quick_Sort > Avg_Weak_Sort)
            {
                cout << "\nБыстрая сортировка в среднем быстрее\n";
            }
            else
            {
                cout << "\nСортировки равны\n";
            }
            cout << "\n----------------------------------------------------------\n";
            cout << "\n";
        }
        if (key == 4)
        {
            int len;
            cout << "Введите длину для массивов\n\n";
            cin >> len;
            vector<int> arr;
            int i = len;
            while (i > 0)
            {
                arr.push_back(i);
                i -= 2;
            }
            if (len % 2 == 1)
            {
                i++;
                i++;
            }
            i++;
            while (i < len)
            {
                arr.push_back(i);
                i += 2;
            }
            arr2->set_len(len);
            arr2->read(arr);
            cout << "\nПример массива при худшем случае (быстрая сортировка): ";
            for (int j = 0; j < len; j++)
            {
                cout << arr[j] << " ";
            }
            auto start = std::chrono::steady_clock::now();
            arr2->qsort(0, arr2->get_len()-1, 0);
            auto end = std::chrono::steady_clock::now();
            cout << "\nВремя быстрой сортировки в худшем случае: " << chrono::duration<double>(end-start).count() << "\n";
            arr.clear();
            for (int j = 1; j < len+1; j++)
            {
                arr.push_back(j);
            }
            arr2->read(arr);
            cout << "\nПример массива при лучшем случае (быстрая сортировка): ";
            for(int j = 0; j < len; j++)
            {
                cout << arr[j] << " ";
            }
            start = std::chrono::steady_clock::now();
            arr2->qsort(0, arr2->get_len()-1, 0);
            end = std::chrono::steady_clock::now();
            cout << "\nВремя быстрой сортировки в лучшем случае: " << chrono::duration<double>(end-start).count() << "\n";
            arr.clear();
            for (int j = 1; j < len+1; j++)
            {
                arr.push_back(j);
            }
            arr1->set_len(len);
            arr1->read(arr);
            cout << "\nПример массива при худшем случае (сортировка слабой кучей): ";
            for(int j = 0; j < len; j++)
            {
                cout << arr[j] << " ";
            }
            start = std::chrono::steady_clock::now();
            arr1->sort_weak();
            end = std::chrono::steady_clock::now();
            cout << "\nВремя сортировки слабой кучей в худшем случае: " << chrono::duration<double>(end-start).count() << "\n";
            arr.clear();
            for (int j = 0; j < len; j++)
            {
                arr.push_back(1);
            }
            arr1->read(arr);
            cout << "\nПример массива при лучшем случае (сортировка слабой кучей): ";
            for(int j = 0; j < len; j++)
            {
                cout << arr[j] << " ";
            }
            start = std::chrono::steady_clock::now();
            arr1->sort_weak();
            end = std::chrono::steady_clock::now();
            cout << "\nВремя сортировки слабой кучей в лучшем случае: " << chrono::duration<double>(end-start).count() << "\n";
        }
    }
}

int main()
{
    SetConsoleCP(1251); // функции для работы с кириллицей (IDE CODE::BLOCKS плохо работает с кириллицей, поэтому приходится подключать соотвествущие функции
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    Weak_Heap arr1;
    Quick_Sort arr2;
    panel(&arr1, &arr2);
    return 0;
}