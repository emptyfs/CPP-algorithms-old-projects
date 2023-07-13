#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Weak_Heap
{
private:
    vector<int> bit; //свойство под массив битов

    void merge_weak_heap(int, int);

public:
    vector<int> wheap; //свойство под массив
    int len; //свойство под длину массива

    void print_leadge_list(int, string, int);
    void read(vector<int>);    //считывание массива слабой кучи с консоли
    void set_len(int);  //установка длины массива слабой кучи
    void print_wheap(); //вывод содержимого вектора wheap в консоль
    void print_bit();   //вывод сожержимого вектора bit в консоль
    void sort_weak();
    void make_weak_heap();
    void weak_sow(int, int);
};