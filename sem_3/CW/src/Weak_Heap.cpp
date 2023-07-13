#include "Weak_Heap.h"

void Weak_Heap::print_leadge_list(int index, string deg, int len)
{
    cout << deg << wheap[index] << "\n";
    deg = deg + "--";
    if (index == 0)
    {
        cout << "--#\n";
    }
    if (2*index+bit[index] < len && index != 0) //для левого
    {
        print_leadge_list(2*index+bit[index], deg, len);
    }
    if (2*index+1-bit[index] < len)
    {
        print_leadge_list(2*index+1-bit[index], deg, len); // для правого
    }
    if (2*index+bit[index] >= len && index != 0)
    {
        cout << deg << "#\n";
    }
    if (2*index+1-bit[index] >= len)
    {
        cout << deg << "#\n";
    }
}

void Weak_Heap::sort_weak()
{
    make_weak_heap();
    weak_sow(len-1, 0);
}

void Weak_Heap::weak_sow(int last_index, int flag)
{
    int i = 0;
    if (flag == 1)
    {
        print_leadge_list(0, "", last_index+1);
        cout << "\n";
    }
    swap(wheap[0], wheap[last_index]);
    while (2*i+bit[i] < last_index)
    {
        if (i == 0)
        {
            i = 2*i+1;
        }
        else
        {
            i = 2*i+bit[i];
        }
    }
    while (i > 0)
    {
        merge_weak_heap(i, 0);
        i = i/2;
    }
    if (last_index-1 != 1)
    {
        if (flag == 1)
        {
            weak_sow(last_index-1, 1);
        }
        else
        {
            weak_sow(last_index-1, 0);
        }
    }
    else
    {
        if (flag == 1)
        {
            print_leadge_list(0, "", last_index);
        }
        merge_weak_heap(0, 1);
    }
}

void Weak_Heap::merge_weak_heap(int index1, int index2)
{
    if (wheap[index1] > wheap[index2])
    {
        if (2*index1 < len && index1 != 0)
        {
            if (bit[index1] == 0)
            {
                bit[index1] = 1;
            }
            else
            {
                bit[index1] = 0;
            }
        }
        swap(wheap[index1], wheap[index2]);
    }
}

void Weak_Heap::make_weak_heap()
{
    int temp;
    for (int i = len-1; i > 0; i--)
    {
        if (i % 2 == 1)
        {
            merge_weak_heap(i, (i-1)/2);
        }
        else
        {
            temp = i/2;
            while (temp % 2 == 0)
            {
                temp = temp/2;
            }
            merge_weak_heap(i, (temp-1)/2);
        }
    }
}

void Weak_Heap::read(vector<int> arr)
{
    wheap.clear();
    bit.clear();
    for (int i = 0; i < len; i++)
    {
        wheap.push_back(arr[i]);
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
    for (int i = 0; i < len; i++)
    {
        cout << bit[i] << " ";
    }
    cout << "\n";
}

void Weak_Heap::set_len(int len)
{
    this->len = len;
}