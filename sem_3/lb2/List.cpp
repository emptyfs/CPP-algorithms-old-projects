#include "List.h"

using namespace std;

lisp **head(lisp** x)
{// PreCondition: not null (s)
    if ((*x) != nullptr) if (!isAtom(*x))	return &((*x)->node.pair.hd);
			else { cerr << "Error: Head(atom) \n"; exit(1); }
		else { cerr << "Error: Head(nil) \n";
			exit(1);
    }
}

bool isAtom(lisp* x)
{
    if(x == nullptr) return false;
	return x->tag;
}

bool isNull(lisp* x)
{
    return x==nullptr;
}

lisp** tail(lisp** x)
{// PreCondition: not null (s)
		if ((*x) != nullptr) if (!isAtom(*x))	return &((*x)->node.pair.tl);
			else { cerr << "Error: Tail(atom) \n"; exit(1); }
		else { cerr << "Error: Tail(nil) \n";
			exit(1);
    }
}

lisp* cons(lisp* h, lisp* t)
	// PreCondition: not isAtom (t)
	{lisp* p;
	if (isAtom(t)) { cerr << "Error: Cons(*, atom)\n"; exit(1);}
    p = new lisp;
    if (p == nullptr)	{cerr << "Memory not enough\n"; exit(1); }
        p->tag = false;
        p->node.pair.hd = h;
        p->node.pair.tl = t;
        return p;
    }

lisp* make_atom(base x)
{
    lisp *s;
    s = new lisp;
    s->tag = true;
    s->node.atom = x;
    return s;
}

void destroy(lisp** s)
{
    if ((*s) != nullptr) {
		if (!isAtom(*s)) {
			destroy (head(s));
			destroy (tail(s));
		}
		delete *s;
		// s = nullptr;
	}
}

// ввод списка с консоли
	void read_lisp(lisp** y)
	{	base x;
		do cin >> x; while (x==' ');
		read_s_expr(x,y);
	} //end read_lisp

	void read_s_expr(base prev, lisp** y)
	{ //prev - ранее прочитанный символ}
		if ( prev == ')' ) {cerr << " ! List.Error 1 " << endl; exit(1); }
		else if ( prev != '(' ) *y = make_atom(prev);
			 else read_seq(y);
	} //end read_s_expr

	void read_seq(lisp** y)
	{	base x;
		lisp *p1, *p2;
		if (!(cin >> x)) {cerr << " ! List.Error 2 " << endl; exit(1);}
		else {
			while  ( x==' ' ) cin >> x;
			if ( x == ')' ) *y = nullptr;
			else {
				read_s_expr(x,&p1);
				read_seq(&p2);
				*y = cons(p1, p2);
			}
		}
	} //end read_seq

// Процедура вывода списка с обрамляющими его скобками - write_lisp,
//  а без обрамляющих скобок - write_seq
	void write_lisp(lisp** x)
	{//пустой список выводится как ()
	if(isNull(*x)) cout << " ()";
	else if (isAtom(*x)) cout << ' ' << (*x)->node.atom;
		else  { //непустой список}
			cout << " (" ;
			write_seq(x);
			cout << " )";
		}
	} // end write_lisp
//...........................
void write_seq(lisp** x)
{//выводит последовательность элементов списка без обрамляющих его скобок
	if (!isNull(*x)) {
		write_lisp(head (x));
		write_seq(tail (x));
	}
}

void find_func(lisp** x, base y, bool* check)
{
    if (isNull(*x)) return;
    if (isAtom(*(head(x))))
    {
        if((*head(x))->node.atom==y)
        {
                *check = true;
                return;
        }
        else
        {
            if (isNull(*tail(x))) return;
            find_func(tail(x), y, check);
        }
    }
    else
    {
        if (isNull(*head(x))) return;
        find_func(head(x), y, check);
        if (isNull(*tail(x))) return;
        find_func(tail(x), y, check);
    }
}