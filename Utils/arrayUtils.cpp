#include <stdio.h>
#include <stdlib.h>
#include <ctime>

namespace arrayUtils
{
    void swapInt(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int* createRandomIntArray(size_t size, size_t maxElement)
    {
        srand( time(0) );
        int* arr = new int[size];
        for (int i = 0; i < size; ++i)
            arr[i] = rand() % maxElement;

        return arr;
    }

    void printArray(int* arr, size_t arrSize)
    {
        printf("[ ");
        for (int i = 0; i < arrSize; ++i)
        {
            if (i < arrSize - 1)
            {
                printf("%d, ", arr[i]);
            }
            else
            {
                printf("%d ]\n", arr[i]);
            }
        }
    }

    void printArray(int** matrix, size_t sizeX, size_t sizeY)
    {
        for (int y = 0; y < sizeY; ++y) {
            for (int x = 0; x < sizeX; ++x) {
                printf("| %d |", matrix[x][y]);
            }

            printf("\n");
        }
    }
}