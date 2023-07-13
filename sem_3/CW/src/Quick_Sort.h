#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Quick_Sort
{
private:
    int len;
public:
    vector<int> qheap;

    int get_len();
    void set_len(int);
    void read(vector<int>);
    void qsort(int, int, int);
    void print(int, int, int, int);
    void print_sorted();
};
