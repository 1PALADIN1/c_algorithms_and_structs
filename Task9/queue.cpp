#include <stdio.h>
#define QUEUE_SIZE 10

/*
 * 1. Описать очередь с приоритетным исключением
 */
namespace queue
{
    typedef struct {
        int priority;
        int data;
    } Node;

    Node* Queue[QUEUE_SIZE];
    int head;
    int tail;
    int items;

    void init()
    {
        for (int i = 0; i < QUEUE_SIZE; ++i)
            Queue[i] = nullptr;

        head = 0;
        tail = 0;
        items = 0;
    }

    void enqueue(int priority, int data)
    {
        if (items == QUEUE_SIZE)
        {
            printf("Queue is full!\n");
            return;
        }

        Node *node = new Node();
        node->priority = priority;
        node->data = data;

        //добавляем элемент в конец очереди
        int idx = tail++ % QUEUE_SIZE;
        Queue[idx] = node;
        items++;
    }

    Node* dequeue()
    {
        if (items == 0)
        {
            printf("Queue is empty!\n");
            return nullptr;
        }

        //ищем самый приоритетный элемент
        int idx = 0;
        int max_priority = -999'999;
        int max_priority_idx = 0;

        for (int i = head; i < tail; ++i)
        {
            idx = i % QUEUE_SIZE;
            if (Queue[idx]->priority > max_priority)
            {
                max_priority = Queue[idx]->priority;
                max_priority_idx = i; //запоминаем его индекс
            }

            idx++;
        }

        Node *result = Queue[max_priority_idx % QUEUE_SIZE];

        //сдвигаем элементы
        while (max_priority_idx > head)
        {
            int current_index = max_priority_idx % QUEUE_SIZE;
            max_priority_idx--;
            int prev_index = max_priority_idx % QUEUE_SIZE;

            Queue[current_index] = Queue[prev_index];
        }

        Queue[head++ % QUEUE_SIZE] = nullptr;
        items--;
        return result;
    }

    void printQueue()
    {
        printf("[ ");
        for (int i = 0; i < QUEUE_SIZE; ++i)
        {
            if (Queue[i] == nullptr)
                printf("[*, *] ");
            else
                printf("[%d, %d] ", Queue[i]->priority, Queue[i]->data);
        }

        printf("]\n");
    }
}