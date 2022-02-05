#include <stdio.h>
#include <math.h>
#include "arrayUtils.h"

namespace task6
{
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void trySwap(int *a, int *b)
    {
        if (*a > *b)
            swap(a, b);
    }

    /*
     *  1. Реализовать пузырьковую сортировку двумерного массива
     *  например, массив
     *
     *  1,9,2
     *  5,7,6
     *  4,3,8
     *
     *  должен на выходе стать
     *
     *  1,2,3
     *  4,5,6
     *  7,8,9
     */
    void matrixSort(int** matrix, size_t sizeX, size_t sizeY)
    {
        for (int k = 0; k < sizeX * sizeY; ++k)
        {
            for (int y = 0; y < sizeY; ++y)
            {
                for (int x = 0; x < sizeX; ++x)
                {
                    if (x == sizeX - 1 && y == sizeY - 1)
                        continue;

                    if (x == sizeX - 1)
                    {
                        trySwap(&matrix[x][y], &matrix[0][y + 1]);
                        continue;
                    }

                    trySwap(&matrix[x][y], &matrix[x + 1][y]);
                }
            }
        }
    }

    /* 3. Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
     * 1 - запросить у пользователя 11 чисел и записать их в последовательность П
     * 2 - инвертировать последовательность П
     * 3 - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3)
     * и если результат вычислений превышает 400 - проинформировать пользователя.
     */
    void algorithmTask3()
    {
        const size_t ARR_SIZE = 11;
        const size_t CALC_LIMIT = 400;
        int* arr = new int[ARR_SIZE];

        printf("Please enter sequence:\n");
        int num;
        for (int i = 0; i < ARR_SIZE; ++i)
        {
            scanf("%d", &num);
            arr[i] = num;
        }

        printf("Your sequence:\n");
        arrayUtils::printArray(arr, ARR_SIZE);

        int l = 0;
        int r = ARR_SIZE - 1;

        while (l < r)
        {
            swap(&arr[l], &arr[r]);
            l++;
            r--;
        }

        printf("Inverted sequence:\n");
        arrayUtils::printArray(arr, ARR_SIZE);

        for (int i = 0; i < ARR_SIZE; ++i)
        {
            int result = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
            arr[i] = result;
            if (result > CALC_LIMIT)
                printf("Result %d is greater than calc limit: %d!\n", result, CALC_LIMIT);
        }

        printf("Result sequence:\n");
        arrayUtils::printArray(arr, ARR_SIZE);

        delete[] arr;
    }

    // ================ Тестирование ================

    void sortTest()
    {
        const size_t sizeX = 3;
        const size_t sizeY = 3;

        int inputArray[sizeX][sizeY] =
        {
        { 1,9,2 },
        { 5,7,6 },
        { 4,3,8 }
        };

        int** matrix = new int*[sizeX];

        for (int x = 0; x < sizeX; ++x)
        {
            matrix[x] = new int[sizeY];
            for (int y = 0; y < sizeY; ++y)
                matrix[x][y] = inputArray[x][y];
        }

        printf("Before sort:\n");
        arrayUtils::printArray(matrix, sizeX, sizeY);

        matrixSort(matrix, sizeX, sizeY);

        printf("After sort:\n");
        arrayUtils::printArray(matrix, sizeX, sizeY);

        for (int i = 0; i < sizeY; ++i)
        {
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    void execute()
    {
        printf("=============== LESSON 6 ===============\n");
        printf("-> Task1:\n");
        sortTest();

        printf("-> Task3:\n");
        algorithmTask3();
    }
}