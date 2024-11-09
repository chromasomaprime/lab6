/* 3. Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
Найти столбец, в котором меньше всего чисел, заканчивающихся цифрой 3,
и заменить все элементы матрицы кроме элементов этого столбца числом -17 */

#include <iostream>

int main()
{
    const int N_Max = 100;
    const int M_Max = 100;
    int matrix[N_Max][M_Max];
    int n, m;

    std::cout << "enter n: ";
    std::cin >> n;
    if (n > 100 || n < 1)
    {
        std::cout << "error" << std::endl;
        return 1;
    }
    std::cout << "enter m: ";
    std::cin >> m;
    if (m > 100 || m < 1)
    {
        std::cout << "error" << std::endl;
        return 1;
    }

    std::cout << "Enter the elements of matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int minCount = n + 1;
    int minCol = -1;

    for (int j = 0; j < m; j++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] % 10 == 3)
            {
                count++;
            }
        }
        if (count < minCount)
        {
            minCount = count;
            minCol = j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != minCol)
            {
                matrix[i][j] = -17;
            }
        }
    }

    std::cout << "matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}