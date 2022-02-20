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
     * обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
     * обход графа по матрице смежности (с подсчётом всех вершин графа)
     * В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.
     */

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

    void execute()
    {
        printf("=============== LESSON 13 ===============\n");
        printf("-> Task1:\n");
        graphTraversalTest();
    }
}