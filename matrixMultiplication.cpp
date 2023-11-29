#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

typedef std::vector<std::vector<int>> Matrix;

Matrix multiply(const Matrix &m1, const Matrix &m2) 
{
    assert((m1.empty() == false) && "Matrix 1 is missing.");
    assert((m2.empty() == false) && "Matrix 2 is missing.");

    size_t m1_rows = m1.size();
    size_t m1_columns = m1[0].size();

    size_t m2_rows = m2.size();
    size_t m2_columns = m2[0].size();

    assert((m1_columns == m2_rows) && "The columns of the first matrix and the rows of the second must be equal in order to perform the multiply operation.");

    Matrix m3(m1_rows, std::vector<int>(m2_columns));
    for (int i = 0; i < m1_rows; i++)
    {
        std::vector<int> elements(m1_rows);
        for (int j = 0; j < m2_columns; j++)
        {
            std::vector<int> product_list(m1_columns);
            for (int n = 0; n < m1_columns; n++)
            {
                int product = m1[i][n] * m2[n][j];
                product_list[n] = product;
            }
            int sum_of_products = std::accumulate(product_list.begin(), product_list.end(), 0);
            m3[i][j] = sum_of_products;
        } 
    }
    return m3;
}

int main()
{
    std::cout << "Solution:\n";
    Matrix answer = multiply({{1,2,1}, {0,1,0}, {2,3,4}}, {{2,5}, {6,7}, {1,8}});
    for(int i = 0; i < answer.size(); i++)
    {
		for(int j = 0; j < answer[0].size(); j++)
		std::cout << answer[i][j]<<" ";
		std::cout << std::endl;
    }
/*
    int user_m1_rows;
    int user_m1_columns;

    std::cout << "Please enter the number of rows in the first matrix: \n";
    std::cin >> user_m1_rows;
    std::cout << "Please enter the number of columns in the first matrix: \n";
    std::cin >> user_m1_columns;

    int user_m2_rows;
    int user_m2_columns;

    std::cout << "Please enter the number of rows in the second matrix: \n";
    std::cin >> user_m2_rows;
    std::cout << "Please enter the number of columns in the second matrix: \n";
    std::cin >> user_m2_columns;
    
    if (user_m1_columns != user_m2_rows)
    {
        std::cout << "Undefined" << std::endl;
    }
    
    else
    {
        Matrix user_m1(user_m1_rows, std::vector<int>(user_m1_columns));
        std::vector<int> row1(user_m1_columns);

        std::cout << "Please enter the elements of the first matrix by rows, using enter between each element: \n";
        user_m1.clear();
        for (int i = 0; i < user_m1_rows; i++)
        {
            for (int j = 0; j < user_m1_columns; j++)
            {
                std::cin >> row1[j];
            }
            user_m1.push_back(row1);
        }
    
        Matrix user_m2(user_m2_rows, std::vector<int>(user_m2_columns));
        std::vector<int> row2(user_m2_columns);

        std::cout << "Please enter the elements of the second matrix by rows, using enter between each element: \n";
        user_m2.clear();
        for (int i = 0; i < user_m2_rows; i++)
        {
            for (int j = 0; j < user_m2_columns; j++)std::cin >> row2[j];
                user_m2.push_back(row2);
        }

        std::cout << "Solution:\n";
        Matrix answer = multiply(user_m1, user_m2);
        for(int i = 0; i < answer.size(); i++)
        {
		    for(int j = 0; j < answer[0].size(); j++)
			std::cout << answer[i][j]<<" ";
		    std::cout << std::endl;
        }
    }
    */
}