/* 1. Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
Если в последовательности нет чисел с суммой цифр, равной 12,
упорядочить последовательность по неубыванию. */

#include <iostream>
#include <cmath>

int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    const int N_Max = 10000;
    int seq[N_Max];
    bool hasSum12 = false;
    int n;

    std::cout << "enter n: ";
    std::cin >> n;
    std::cout << "enter " << n << " values: ";

    for (int i = 0; i < n; i++)
    {
        std::cin >> seq[i];
    }

    for (int i = 0; i < n; i++) // Цикл для проверки суммы цифр
    {
        if (sumOfDigits(seq[i]) == 12)
        {
            hasSum12 = true;
            break;
        }
    }

    if (hasSum12)
    {
        std::cout << "there is a sum of numbers equal to 12" << std::endl;
    }

    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (seq[j] > seq[j+1])
                {
                    int tmp = seq[j];
                    seq[j]=seq[j+1];
                    seq[j+1]=tmp;
                }
            }
        }
    }
    std::cout << "Sorted sequence: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << seq[i] << " ";
    }
    return 0;
}