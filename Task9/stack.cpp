#include <stdio.h>

namespace stack
{
    const int SIZE = 1000;
    const int EMPTY_NUM = -999'999;

    int cursor;
    int Stack[SIZE];

    void init()
    {
        cursor = -1;
    }

    int getSize()
    {
        return cursor + 1;
    }

    void push(int data)
    {
        if (cursor >= SIZE)
        {
            printf("Stack is full!\n");
            return;
        }

        Stack[++cursor] = data;
    }

    int pop()
    {
        if (cursor == -1)
        {
            printf("Stack is empty!\n");
            return EMPTY_NUM;
        }

        return Stack[cursor--];
    }

    void printStack()
    {
        printf("[ ");
        for (int i = 0; i < getSize(); ++i)
            printf("[%d] ", Stack[i]);

        printf("]\n");
    }
}