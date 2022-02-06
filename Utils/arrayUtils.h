#include <stdio.h>

namespace arrayUtils
{
    void swapInt(int *a, int *b);
    int* createRandomIntArray(size_t size, size_t maxElement);

    void printArray(int* arr, size_t arrSize);
    void printArray(int** matrix, size_t sizeX, size_t sizeY);
}
