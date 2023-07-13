#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Weak_Heap
{
private:
    vector<int> wheap; //свойство под массив
    vector<int> bit; //свойство под массив битов
    int len; //свойство под длину массива
    int len_bit;    //длина массива битов
public:
    void read();    //считывание массива слабой кучи с консолт
    void set_len(int);  //установка длины массива слабой кучи
    void check(int, bool*); //проверка массива (является ли он слабой кучей)
    void print_wheap(); //вывод содержимого вектора wheap в консоль
    void print_bit();   //вывод сожержимого вектора bit в консоль
    void read_bit();    //считывание значений для битоговго массива из консоли
    bool check_root();  //проверка значения в битовом массиве для корневого узла
};