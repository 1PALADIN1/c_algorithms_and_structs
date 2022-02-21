#include <stdio.h>
#include "../Task9/stack.h"
#include "../Task9/queue.h"

namespace task13
{
    /*
     * 1. Реализовать обход в глубину с использованием стека
     */
    const size_t GRAPH_SIZE = 6;
    int ref_matrix[GRAPH_SIZE][GRAPH_SIZE] = {
            {0, 1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0}
    };

    void graphTraversal(int** matrix, int start)
    {
        int* visited = new int[GRAPH_SIZE];
        for (int i = 0; i < GRAPH_SIZE; ++i)
            visited[i] = 0;

        stack::init();
        stack::push(start);
        visited[start] = 1;
        printf("%3d", start);

        while (stack::getSize() > 0)
        {
            int i = stack::pop();
            for (int r = 0; r < GRAPH_SIZE; ++r)
            {
                if (matrix[i][r] == 1 && visited[r] == 0)
                {
                    //если не дошли до конца, то складываем в стек, чтобы снова вернуться к обходу вершины
                    if (r < GRAPH_SIZE)
                        stack::push(i);

                    stack::push(r);
                    visited[r] = 1;
                    printf("%3d", r);

                    break;
                }
            }
        }

        printf("\n");
        delete[] visited;
    }

    /*
     * 2. Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями.
     * Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
     * - обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
     * - обход графа по матрице смежности (с подсчётом всех вершин графа)
     * В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.
     */
    const size_t NET_GRAPH_SIZE = 6;
    int ref_net[NET_GRAPH_SIZE][NET_GRAPH_SIZE] = {
            {0, 0, 1, 0, 1, 1},
            {0, 0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 1},
            {1, 1, 0, 0, 1, 0}
    };

    void searchEngineRecursive(int** matrix, int* counters, int* visited, int start)
    {
        int visitedCount = 0;
        for (int i = 0; i < NET_GRAPH_SIZE; ++i)
        {
            if (visited[i] == 1)
                visitedCount++;
        }

        if (visitedCount == NET_GRAPH_SIZE)
            return;

        if (start >= NET_GRAPH_SIZE)
            start = 0;

        visited[start] = 1;

        for (int j = 0; j < NET_GRAPH_SIZE; ++j)
        {
            if (matrix[start][j] != 0)
                counters[j]++;
        }

        searchEngineRecursive(matrix, counters, visited, ++start);
    }

    void searchEngine(int** matrix, int* counters)
    {
        for (int i = 0; i < NET_GRAPH_SIZE; ++i)
        {
            for (int j = 0; j < NET_GRAPH_SIZE; ++j)
            {
                if (matrix[i][j] != 0)
                    counters[j]++;
            }
        }
    }

    // ================ Тестирование ================

    void graphTraversalTest()
    {
        int** matrix = new int * [GRAPH_SIZE];

        for (int i = 0; i < GRAPH_SIZE; ++i)
        {
            matrix[i] = new int[GRAPH_SIZE];
            for (int j = 0; j < GRAPH_SIZE; ++j)
                matrix[i][j] = ref_matrix[i][j];
        }

        graphTraversal(matrix, 0);
        graphTraversal(matrix, 2);
        graphTraversal(matrix, 1);

        for (int i = 0; i < GRAPH_SIZE; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }

    void clearCounters(int* counters)
    {
        for (int i = 0; i < NET_GRAPH_SIZE; ++i)
            counters[i] = 0;
    }

    void printSortedCounters(int* counters)
    {
        for (int j = 0; j < NET_GRAPH_SIZE; ++j)
        {
            int max_index = 0;
            int max = counters[max_index];
            for (int i = 0; i < NET_GRAPH_SIZE; ++i)
            {
                if (counters[i] > max)
                {
                    max_index = i;
                    max = counters[max_index];
                }
            }

            printf("%d: %d\n", max_index, counters[max_index]);
            counters[max_index] = -1;
        }
    }

    void searchEngineTest()
    {
        int** matrix = new int * [NET_GRAPH_SIZE];
        int* counters = new int [NET_GRAPH_SIZE];
        int* visited = new int [NET_GRAPH_SIZE];

        for (int i = 0; i < NET_GRAPH_SIZE; ++i)
        {
            matrix[i] = new int[NET_GRAPH_SIZE];
            for (int j = 0; j < NET_GRAPH_SIZE; ++j)
                matrix[i][j] = ref_net[i][j];
        }

        clearCounters(counters);
        clearCounters(visited);
        printf("Recursive 1:\n");
        searchEngineRecursive(matrix, counters, visited, 0);
        printSortedCounters(counters);

        clearCounters(counters);
        clearCounters(visited);
        printf("Recursive 2:\n");
        searchEngineRecursive(matrix, counters, visited, 3);
        printSortedCounters(counters);

        clearCounters(counters);
        printf("Usual:\n");
        searchEngine(matrix, counters);
        printSortedCounters(counters);

        for (int i = 0; i < NET_GRAPH_SIZE; ++i)
            delete[] matrix[i];
        delete[] matrix;

        delete[] counters;
        delete[] visited;
    }

    void execute()
    {
        printf("=============== LESSON 13 ===============\n");
        printf("-> Task1:\n");
        graphTraversalTest();

        printf("-> Task2:\n");
        searchEngineTest();
    }
}