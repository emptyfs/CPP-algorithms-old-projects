#include <iostream>
#include <locale.h>

using namespace std;

void fix(int ivector[], int start, int finish)
{
    if (finish-start < 1)
    {
        return;
    }

    if (finish-start < 2)
    {
        if( ivector[start] > ivector[finish])
        {
            int c = ivector[start];
            ivector[start] = ivector[finish];
            ivector[finish] = c;
        }

        return;
    }

    fix(ivector, start, start+(finish-start)/2);
    fix(ivector, start+(finish-start)/2+1, finish);
}

int main()
{
  setlocale(0,"");
  int ivector[100];
  int key;
  int icount = 0;

  cout << "Введите значения вектора\n";
  cin >> key;
  
  while(cin)
  {
    ivector[icount] = key;
    cin >> key;
    icount++;
  }

  fix(ivector, 0, icount-1);
  cout << "{";

  for (int i = 0; i < icount-1; i++)
  {
    cout << ivector[i] << ", ";
  }
  
  cout << ivector[icount-1] <<"}";
  return 0;
}
