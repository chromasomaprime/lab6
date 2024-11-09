/* 4. Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
Удалить из последовательности числа, произведение цифр которых кратно 70,
а среди оставшихся продублировать простые числа. */

#include <iostream>
#include <cmath>

const int N_Max = 20000;

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= std::sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int productOfDigits(int number)
{
    int product = 1;
    while (number > 0)
    {
        product *= number % 10;
        number /= 10;
    }
    return product;
}

int main()
{
    int seq[N_Max];
    int n;

    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << "enter " << n << " values: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> seq[i];
    }

    int j1 = 0; // Удаление
    for (int i = 0; i < n; i++)
    {
        if (productOfDigits(seq[i]) % 70 != 0)
        {
            seq[j1] = seq[i];
            j1++;
        }
    }
    n = j1;

    std::cout << "Sequence with deleted numbers: ";
    for (int i = 0; i < n; i++) // Дублирование простого числа
    {
        std::cout << seq[i] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        if (isPrime(seq[i]))
        {
            for (int j = n; j > i; j--)
            {
                seq[j] = seq[j - 1];
            }
            seq[i + 1] = seq[i]; 
            n++; 
            i++;
        }
    }

    std::cout << std::endl << "seq with double prime num: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << seq[i] << " ";
    }
    
    std::cout << std::endl;
    return 0;
}