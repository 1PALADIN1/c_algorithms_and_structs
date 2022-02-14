#include <stdio.h>

namespace stack_task10
{
    typedef struct Node {
        char data;
        struct Node *next;
    } Node;

    typedef struct {
        Node *head;
        int size;
    } Stack;

    Stack* stackInstance;

    void init()
    {
        stackInstance = new Stack();
        stackInstance->head = nullptr;
        stackInstance->size = 0;
    }

    int getSize()
    {
        return stackInstance->size;
    }

    void push(char data)
    {
        Node* node = new Node();
        node->data = data;
        node->next = stackInstance->head;
        stackInstance->head = node;
        stackInstance->size++;
    }

    char peek()
    {
        if (stackInstance->size == 0)
        {
            printf("Stack is empty!\n");
            return -1;
        }

        return stackInstance->head->data;;
    }

    char pop()
    {
        if (stackInstance->size == 0)
        {
            printf("Stack is empty!\n");
            return -1;
        }

        Node *tmp = stackInstance->head;
        char data = stackInstance->head->data;
        stackInstance->head = stackInstance->head->next;
        stackInstance->size--;

        delete tmp;
        return data;
    }

    void dispose()
    {
        while (getSize() > 0)
            pop();

        delete stackInstance;
    }
}