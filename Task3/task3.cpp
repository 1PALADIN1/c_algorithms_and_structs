#include <stdio.h>

namespace task3
{
    bool checkSimpleNumber(int number)
    {
        // 0 НЕ является натуральным числом, следовательно, и простым тоже
        if (number == 0)
            return false;

        if (number == 1)
            return true;

        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
                return false;
        }

        return true;
    }

    void checkNumberTest(int number)
    {
        bool result = task3::checkSimpleNumber(number);
        if (result)
        {
            printf("Number %d is simple\n", number);
            return;
        }

        printf("Number %d is NOT simple\n", number);
    }

    void execute()
    {
        printf("=============== LESSON 3 ===============\n");
        checkNumberTest(7);
        checkNumberTest(10);
        checkNumberTest(23);
        checkNumberTest(2'100'127);
        checkNumberTest(0);
        checkNumberTest(1);
        checkNumberTest(2);
    }
}
