#pragma once

class Tree
{
public:
    char ptr_lkp[50]; //массив для лкп
    char ptr_lpk[50]; //массив для лпк
    char ptr_ready[50]; //массив для клп
    int ptr_ready_ind[50]; //вспомогательный массив для клп
    int ptr_len = 0; //длина массивов
    int place = 0; //поле помощи заполнения массива

    void read_ptr(char ptr[50]);
    void draw();
    void zero_ptr();
    void make_tree(char root, int degree, int start, int finish, int check);
    void print_klp();
};