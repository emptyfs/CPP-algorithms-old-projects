#include <iostream>
#include <vector>

std::vector<int> prefix_function(const std::string& str)
{
    std::vector<int> pi(str.size()); //массив префикс-функции (изначально заполняется нулями)
    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "string = " << str << "\n";

    for (int i = 1; i < str.size(); i++) //первый элемент всегда будет равен 0 в pi
    {
        int temp = pi[i - 1]; //кладется предыдущее значение массива pi, которое равно максимально длины префикс-суффикса для i - 1 строки

        while ((temp > 0) && (str[i] != str[temp])) //"откат до последнего элемента текущего префикс-суффикса, причем, элемент, который стоит после последнего элемента префикса должен быть равен
        {
            temp = pi[temp - 1]; //новому элементу, который добавляется на i-ом (в СИ нумерация с нулевого элемента, поэтому temp уже будет указывать на элемент после последнего элемента префикса
        }

        if (str[i] == str[temp]) //temp-1 - индекс последнего элемента текущего префикс-суффикса, temp - следующего (т.к. в СИ нумерация с нулевого элемента)
        {
            temp++; //если этот предыдущий элемент равен новому элементу (который добавляется на i-ом шаге), то префикс функция для i-ой подстроки равна temp+1
        }
        pi[i] = temp;
        std::cout << i << " step: " << pi[0];
        for (int i = 1; i < pi.size(); i++)
        {
            std::cout << ", " << pi[i];
        }
        std::cout << "\n";
    }
    std::cout << "-------------------------------------------------------------------\n";
    return pi;
}

std::vector<int> kmp(std::string& str_P, std::string& str_T)
{
    std::vector<int> temp = prefix_function(str_P + '$' + str_T);
    std::vector<int> result;

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == str_P.size())
        {
            if (str_P.size() == 0)
            {
                break;
            }
            result.push_back(i - 2 * str_P.size()); // i(индекс последнего элемента P в P+'$'+T) - str_P.size()-1(P+'$') - str_P.size()+1(индекс первого элемента P в P+'$'+T)
        }
    }

    return result;
}

int main()
{
    std::string P, T;
    std::cin >> P >> T;

    std::vector<int> out = kmp(P, T);

    if (out.empty())
    {
        std::cout << -1;
        return 0;
    }

    std::cout << out[0];

    if (out.size() > 1)
    {
        for (int i = 1; i < out.size(); i++)
        {
            std::cout << ',' << out[i];
        }
    }

    return 0;
}
