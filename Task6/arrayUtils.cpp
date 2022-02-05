#include <stdio.h>

namespace arrayUtils
{
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