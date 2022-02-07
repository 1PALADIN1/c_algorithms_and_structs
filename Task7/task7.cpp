#include <stdio.h>
#include "../Utils/arrayUtils.h"

namespace task7
{
    // 1. Описать в коде улучшенный алгоритм быстрой сортировки
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

    //получаем индекс следующего чётного числа
    int getNextIndex(int* arr, int current_index, size_t size)
    {
        for (int i = current_index; i < size; ++i)
        {
            if (arr[i] % 2 == 0)
                return i;
        }

        //достигли конца массива
        return -1;
    }

    void bucketPositiveSort(int* arr, size_t size)
    {
        const size_t MAX = size;
        const size_t BUCKET_SIZE = 10;

        int buckets[BUCKET_SIZE][MAX + 1];
        for (int i = 0; i < BUCKET_SIZE; ++i)
            buckets[i][MAX] = 0;

        for (int digit = 1; digit < 1'000'000'000; digit*=BUCKET_SIZE)
        {
            for (int i = 0; i < MAX; ++i)
            {
                //нечётные числа не добавляем в корзину
                if (arr[i] % 2 != 0)
                    continue;

                int d = (arr[i] / digit) % BUCKET_SIZE;
                buckets[d][buckets[d][MAX]++] = arr[i];
            }

            int idx = 0;
            bool skip = false;
            for (int i = 0; i < BUCKET_SIZE; ++i)
            {
                for (int j = 0; j < buckets[i][MAX]; ++j)
                {
                    //раскидываем значения только по индексам, где стоят чётные числа
                    idx = getNextIndex(arr, idx, size);
                    if (idx == -1)
                        break;

                    arr[idx] = buckets[i][j];
                    idx++;
                }

                buckets[i][MAX] = 0;
            }
        }
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
        const size_t ARR_SIZE = 30;
        int* arr = arrayUtils::createRandomIntArray(ARR_SIZE, 20);

        printf("Array before sort:\n");
        arrayUtils::printArray(arr, ARR_SIZE);

        bucketPositiveSort(arr, ARR_SIZE);

        printf("Array after sort:\n");
        arrayUtils::printArray(arr, ARR_SIZE);
    }

    void execute()
    {
        printf("=============== LESSON 7 ===============\n");
        printf("-> Task1:\n");
        improvedQuickSortTest();

        printf("-> Task2:\n");
        positiveNumberSortTest();
    }
}