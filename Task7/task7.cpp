#include <stdio.h>
#include "../Utils/arrayUtils.h"

namespace task7
{
    void insertSort(int* arr, size_t first, size_t last)
    {
        int temp, pos;

        for (int i = first + 1; i <= last; ++i) {
            temp = arr[i];
            pos = i - 1;

            while (pos >= 0 && arr[pos] > temp)
            {
                arr[pos + 1] = arr[pos];
                pos--;
            }

            arr[pos + 1] = temp;
        }
    }

    int getMedianIndex(int* arr, int first, int last)
    {
        int mid = (first + last) / 2;

        //первый элемент посередине
        if ( (arr[first] > arr[mid] && arr[first] < arr[last])
            || (arr[first] > arr[last] && arr[first] < arr[mid]) )
        {
            return first;
        }

        //последний элемент посередине
        if ( (arr[last] > arr[first] && arr[last] < arr[mid])
            || (arr[last] > arr[mid] && arr[last] < arr[first]) )
        {
            return last;
        }

        //центральный элемент посередине
        return mid;
    }

    // 1. Описать в коде улучшенный алгоритм быстрой сортировки
    void improvedQuickSort(int* arr, size_t first, size_t last, size_t chunk_size)
    {
        if (last - first <= chunk_size)
        {
            insertSort(arr, first, last);
            return;
        }

        int median = getMedianIndex(arr, first, last);
        arrayUtils::swapInt(&arr[median], &arr[(first + last) / 2]);

        int i = first;
        int j = last;
        int x = arr[(first + last) / 2];

        do
        {
            while(arr[i] < x) i++;
            while(arr[j] > x) j--;

            if (i <= j)
            {
                arrayUtils::swapInt(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last)
            improvedQuickSort(arr, i, last, chunk_size);

        if (first < j)
            improvedQuickSort(arr, first, j, chunk_size);
    }

    // 2. Сортировать в массиве целых положительных чисел только чётные числа,
    // нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
    // то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 6 5 9 8 8 7 3]
    void positiveNumberSort()
    {
    }

    // ================ Тестирование ================

    void improvedQuickSortTest()
    {
        const size_t ARR_SIZE = 50;
        const size_t CHUNK_SIZE = 10;
        int* arr = arrayUtils::createRandomIntArray(ARR_SIZE, 200);

        printf("Array before sort:\n");
        arrayUtils::printArray(arr, ARR_SIZE);

        improvedQuickSort(arr, 0, ARR_SIZE - 1, CHUNK_SIZE);

        printf("Array after sort:\n");
        arrayUtils::printArray(arr, ARR_SIZE);
    }

    void positiveNumberSortTest()
    {
    }

    void execute()
    {
        printf("=============== LESSON 7 ===============\n");
        printf("-> Task1:\n");
        improvedQuickSortTest();

//        printf("-> Task2:\n");
//        positiveNumberSortTest();
    }
}