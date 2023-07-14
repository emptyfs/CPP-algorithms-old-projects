#include <iostream>
#include "..\Square.h"
#include "..\Field.h"

int main()
{
    while (true)
    {

        Field matrix;
        int N;
        std::cin >> N;

        if (N < 2 || N > 20)
        {
            break;
        }

        if (N % 2 == 0)
        {
            std::cout << "4\n"; 
            std::cout << "1 1 " << N / 2 << "\n"; 
            std::cout << 1 + N / 2 << " " << "1 " << N / 2 << "\n"; 
            std::cout << "1 " << 1 + N / 2 << " " << N / 2 << "\n"; 
            std::cout << 1 + N / 2 << " " << 1 + N / 2 << " " << N / 2 << "\n"; 
        }

        else if (N % 3 == 0)
        {
            std::cout << "6\n"; 
            std::cout << "1 1 " << 2 * N / 3 << "\n"; 
            std::cout << 1 + 2 * N / 3 << " " << "1 " << N / 3 << "\n"; 
            std::cout << 1 + 2 * N / 3 << " " << 1 + N / 3 << " " << N / 3 << "\n"; 
            std::cout << "1 " << 1 + 2 * N / 3 << " " << N / 3 << "\n"; 
            std::cout << 1 + N / 3 << " " << 1 + 2 * N / 3 << " " << N / 3 << "\n"; 
            std::cout << 1 + 2 * N / 3 << " " << 1 + 2 * N / 3 << " " << N / 3 << "\n"; 
        }

        else
        {
            matrix.backtracking(N);
        }
        std::cout << " \n";
    }
    return 0;
}