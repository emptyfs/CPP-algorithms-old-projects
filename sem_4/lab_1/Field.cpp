#include "Field.h"

void Field::fill_empty_square(int** matrix, int x, int y, int square_side, int flag)
{
    for (int i = x; i < x + square_side; i++)
    {
        for (int j = y; j < y + square_side; j++)
        {
            matrix[i][j] = flag;
            operation_amount++;
        }
    }
}

void Field::backtracking(int size)
{
    set_main_size(size);

    int** matrix = new int* [main_size];
    for (int i = 0; i < main_size; i++)
    {
        matrix[i] = new int[main_size];
    }

    for (int i = 0; i < main_size; i++)
    {
        for (int j = 0; j < main_size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    int local_x = 0;
    int local_y = 0;
    int local_max_side = 3;
    int local_next_side = 0;
    int flag = 0;

    set_deafult_local_squares(main_size, matrix);

    while (flag != 1)
    {
        if (check_matrix(matrix, main_size, local_x, local_y))
        {
            int next_side = find_side(matrix, main_size, local_x, local_y); 
            fill_empty_square(matrix, local_x, local_y, next_side, 1); 
            local_squares.push_back(Square(next_side, local_x, local_y)); 
            local_max_side++; 
        }
        else 
        {
            squares = local_squares;
            square_number = local_max_side;
            back_vector(matrix, local_max_side, flag);
        }
        if (local_max_side >= square_number) 
        {
            back_vector(matrix, local_max_side, flag);
        }


    }
    for (int i = 0; i < main_size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    std::cout << "square number: " << square_number << "\n";
    print_squares();
}

void Field::back_vector(int** matrix, int& local_max_side, int& flag)
{
    while (true)
    {
        if (local_max_side > 3)
        {
            Square square = local_squares[local_max_side - 1]; 
            if (local_squares[local_max_side - 1].get_side() >= 2) 
            {
                local_squares.pop_back(); 
                fill_empty_square(matrix, square.get_x(), square.get_y(), square.get_side(), 0); 
                fill_empty_square(matrix, square.get_x(), square.get_y(), square.get_side() - 1, 1); 
                local_squares.push_back(Square(square.get_side() - 1, square.get_x(), square.get_y())); 
                break;
            }
            else 
            {
                local_squares.pop_back(); 
                local_max_side--; 
                fill_empty_square(matrix, square.get_x(), square.get_y(), square.get_side(), 0); 
                continue;
            }
        }
        else 
        {
            flag = 1;
            break;
        }
    }
}

int Field::find_side(int** matrix, int matrix_size, int x, int y)
{
    int right_side = 1;
    int down_side = 1;

    while (y + right_side < matrix_size && matrix[x][y + right_side] != 1)
    {
        right_side++;
    }

    while (x + down_side < matrix_size && matrix[x + down_side][y] != 1)
    {
        down_side++;
    }
    return std::min(right_side, down_side);
}

bool Field::check_matrix(int** array, int array_size, int& x, int& y)
{
    for (int i = 0; i < array_size; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            if (array[i][j] == 0)
            {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

void Field::set_deafult_local_squares(int size, int** matrix)
{
    set_main_size(size);
    add_vector_local_squares(main_size / 2 + 1, 0, 0);
    add_vector_local_squares(main_size / 2, 0, main_size / 2 + 1);
    add_vector_local_squares(main_size / 2, main_size / 2 + 1, 0);
    fill_empty_square(matrix, 0, 0, main_size / 2 + 1, 1);
    fill_empty_square(matrix, 0, main_size / 2 + 1, main_size / 2, 1);
    fill_empty_square(matrix, main_size / 2 + 1, 0, main_size / 2, 1);
}

void Field::add_vector_local_squares(int side, int x, int y)
{
    local_squares.push_back(Square(side, x, y));
}

void Field::set_main_size(int size)
{
    main_size = size;
    square_number = size * size;
}

void Field::print_squares()
{
    for (int i = 0; i < squares.size(); i++)
    {
        squares[i].set_x(squares[i].get_x() + 1);
        squares[i].set_y(squares[i].get_y() + 1);
        std::cout << squares[i].get_x() << ' ' << squares[i].get_y() << ' ' << squares[i].get_side() << "\n";
    }
}