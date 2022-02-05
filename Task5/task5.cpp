#include <stdio.h>
#include "arrayUtils.h"

namespace task5
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

        for (int i = 0; i < sizeY; ++i) {
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    void execute()
    {
        printf("=============== LESSON 5 ===============\n");
        printf("-> Task1:\n");
        sortTest();
    }
}