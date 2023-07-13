#include <iostream>
#include <vector>

using namespace std;

template <typename T> void print(vector<T>* arr, int start, int finish, int icount, int index_mid) //вспомогательная функция для вывода вектора на консоль
{
    if (icount == 0) //вывод вектора в конце функции qsort
    {
        for (int i = 0; i <= finish; i++)
        {
            cout << arr->at(i);
        }
        cout << "\n";
        return;
    }
    for (int i = start; i <= finish; i++) //вывод вектора в ходе сортировки
    {
        if (i == index_mid && i != start)
        {
            cout<<"----";
        }
        else if (i == icount)
        {
            cout<<"----";
        }
        cout << arr->at(i);
    }
    cout << "\n";
}

template <typename T> void qsort(vector<T>* arr, int start, int finish)
{
    T mid = arr->at(start); //опорный элемент (элемент, относительно которого производится текущая быстрая сортировка
    int index_mid = start; //индекс опорного элемента
    int icount = finish; //переменная, с помощью которой производится обход по текущей стороне вектора
    int check = finish; //переменная, с помощью которой производится корректный вывод отсортированных эелементов
    cout << mid <<" - the mid element\n";
    do
    {
        if (mid > arr->at(check)) //если опорный элемент больше расматриваемого в цикле while, то он перемещается слева от опорного элемента
        {
            arr->insert(arr->begin()+index_mid, arr->at(check));
            index_mid++;
            arr->erase(arr->begin()+check+1);
            check++;
        }
        print(arr, start, finish, check, index_mid);
        icount--;
        check--;
    } while (icount >= start+1);
    cout << "the output array:\t";
    print(arr, 0, arr->size()-1, 0, 0); //вывод вектора в конце текущей функции
    cout << "\n\n";

    if (start < index_mid-1) //вызов сортировки для левой стороны
    {
        qsort(arr, start, index_mid-1);
    }
    if (index_mid+1 < finish) //вызов сортировеи для правой стороны
    {
        qsort(arr, index_mid+1, finish);
    }
}

int main()
{
    int key; // переменная для ввода значений

    cout << "Enter the size of the array\n";
    cin >> key;
    vector<int> arr(key);

    cout << "Enter an array\n";

    for (int i = 0; i < key; i++)
    {
        cin >> arr.at(i);
    }

    cout << "\n";

    qsort(&arr, 0, arr.size()-1); //функция быстрой сортировки, выполненная согласно заданию (на вход поступают указатель на вектор, индекс начального элемента и индекс конечного элемента
    int len = arr.size(); //len необходима для цикла (потому как i в цикле - значение типа int, а метод size() возвращает значение типа long long int

    cout << "the finished array:\t";
    for (int i = 0; i < len; i++) //вывод отсортированного вектора
    {
        cout << arr.at(i);
    }
    return 0;
}