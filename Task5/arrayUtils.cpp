#include <stdio.h>

namespace arrayUtils
{
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