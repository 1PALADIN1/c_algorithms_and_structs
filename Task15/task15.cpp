#include <stdio.h>
#include <string.h>

namespace task15
{
    /*
     * 1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
     */
    int stringToHash(char* input_string)
    {
        int hash = 0;
        for (int i = 0; i < strlen(input_string); ++i)
            hash += input_string[i];

        return hash;
    }

    /*
     * 2. Имеются монеты номиналом 50, 10, 5, 2, 1 коп. Напишите функцию которая минимальным количеством
     * монет наберет сумму 98 коп. Для решения задачи используйте “жадный” алгоритм.
     */
    void coinsSum(int* coinArray, size_t array_size, int totalSum)
    {
        printf("For sum %d:\n", totalSum);

        int* result = new int[array_size];
        for (int i = 0; i < array_size; ++i)
            result[i] = 0;

        int sum = 0;
        int index = 0;
        while (index < array_size || sum != totalSum)
        {
            if (sum + coinArray[index] > totalSum)
            {
                index++;
                continue;
            }

            sum += coinArray[index];
            result[index]++;
        }

        for (int i = 0; i < array_size; ++i)
        {
            if (result[i] > 0)
                printf("%d - %d\n", coinArray[i], result[i]);
        }

        delete[] result;
    }

    // ================ Тестирование ================

    void stringToHashTest()
    {
        char* test_string1 = "Hello world";
        int hash = stringToHash(test_string1);
        printf("Hash of string \"%s\" = %d\n", test_string1, hash);

        char* test_string2 = "Simple test string!";
        hash = stringToHash(test_string2);
        printf("Hash of string \"%s\" = %d\n", test_string2, hash);

        char* test_string3 = "TEST test test TEST 123 123";
        hash = stringToHash(test_string3);
        printf("Hash of string \"%s\" = %d\n", test_string3, hash);
    }

    void coinsSumTest()
    {
        const size_t ARRAY_SIZE = 5;
        int* coinArray = new int[ARRAY_SIZE];
        coinArray[0] = 50;
        coinArray[1] = 10;
        coinArray[2] = 5;
        coinArray[3] = 2;
        coinArray[4] = 1;

        coinsSum(coinArray, ARRAY_SIZE, 98);
        coinsSum(coinArray, ARRAY_SIZE, 43);
        coinsSum(coinArray, ARRAY_SIZE, 111);

        delete[] coinArray;
    }

    void execute()
    {
        printf("=============== LESSON 15 ===============\n");
        printf("-> Task1:\n");
        stringToHashTest();

        printf("-> Task2:\n");
        coinsSumTest();
    }
}