#pragma once
#include <iostream>

typedef char base;	// базовый тип элементов (атомов)

class lisp;
class two_ptr
{
public:
    lisp *hd;
    lisp *tl;
};	//end two_ptr;

class lisp
{
public:
    bool tag; // true: atom, false: pair
    union
    {
        base atom;
        two_ptr pair;
    } node;		//end union node
};			//end s_expr

// функции
// базовые функции:
lisp** head(lisp** x);
lisp** tail(lisp** x);
lisp* cons(lisp* h, lisp* t);
lisp* make_atom(base x);
bool isAtom(lisp* x);
bool isNull(lisp* x);
void destroy(lisp** s);

// функции ввода:
void read_lisp(lisp** y);			// основная
void read_s_expr(base prev, lisp** y);
void read_seq(lisp** y);

// функции вывода:
void write_lisp(lisp** x);		// основная
void write_seq(lisp** x);

// функция поиска
void find_func(lisp** x, base y, bool* check);