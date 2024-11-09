/* 2. Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
Упорядочить последовательность по неубыванию произведения цифр числа,
числа с одинаковыми произведениями цифр дополнительно упорядочить по неубыванию суммы цифр числа,
числа с одинаковыми произведениями цифр и одинаковыми суммами цифр дополнительно упорядочить по неубыванию самого числа. */

#include <iostream>

int multiDigits(int num)
{
    int multiply = 1;
    while (num > 0)
    {
        multiply *= num % 10;
        num /= 10;
    }
    return multiply;
}

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

void sortSequence(int seq[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int mult1 = multiDigits(seq[j]);
            int mult2 = multiDigits(seq[j + 1]);
            int sum1 = sumOfDigits(seq[j]);
            int sum2 = sumOfDigits(seq[j + 1]);

            // Условие для сортировки
            if (mult1 > mult2 || (mult1 == mult2 && (sum1 > sum2 || (sum1 == sum2 && seq[j] > seq[j + 1]))))
            {
                seq[j] = seq[j] + seq[j + 1];
                seq[j + 1] = seq[j] - seq[j + 1];
                seq[j] = seq[j] - seq[j + 1];
            }
        }
    }
}

int main()
{
    const int N_Max = 1000;
    int seq[N_Max];
    int n;

    std::cout << "enter n: ";
    std::cin >> n;

    std::cout << "enter " << n << " natural num: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> seq[i];
    }

    sortSequence(seq, n);

    std::cout << "Sorted sequence: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << seq[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}