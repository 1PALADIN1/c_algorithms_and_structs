#include <stdio.h>
#include "queue.h"

namespace task9
{
    //2. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
    void decimalToBinary()
    {
    }

    // ================ Тестирование ================

    void priorityQueueTest()
    {
        queue::init();

        queue::printQueue();

        queue::enqueue(1, 22);
        queue::enqueue(2, 88);
        queue::enqueue(8, 12);
        queue::enqueue(2, -90);
        queue::enqueue(4, 909);
        queue::enqueue(3, 0);
        queue::enqueue(6, 16);
        queue::enqueue(7, 2);

        queue::printQueue();

        for (int i = 0; i < 5; ++i)
        {
            queue::Node* element = queue::dequeue();
            printf("Dequeue element [%d, %d]\n", element->priority, element->data);
        }

        queue::printQueue();

        queue::enqueue(3, 99);
        queue::enqueue(10, -9);
        queue::enqueue(2, 999);

        queue::printQueue();

        for (int i = 0; i < 2; ++i)
        {
            queue::Node* element = queue::dequeue();
            printf("Dequeue element [%d, %d]\n", element->priority, element->data);
        }

        queue::printQueue();
    }

    void decimalToBinaryTest()
    {
    }

    void execute()
    {
        printf("=============== LESSON 9 ===============\n");
        printf("-> Task1:\n");
        priorityQueueTest();

//        printf("-> Task2:\n");
//        decimalToBinaryTest();
    }
}