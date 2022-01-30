#include <stdio.h>

#include "Task2/task2.h"
#include "Task3/task3.h"

//урок 2
void execute_lesson2();

//урок 3
void execute_lesson3();
void checkNumber(int number);

int main(int argc, char *argv[])
{
    execute_lesson2();
    execute_lesson3();

    return 0;
}

void execute_lesson2()
{
    printf("=============== LESSON 2 ===============\n");
    task2::printHelloWorld();
}

void execute_lesson3()
{
    printf("=============== LESSON 3 ===============\n");
    checkNumber(7);
    checkNumber(10);
    checkNumber(23);
    checkNumber(2'100'127);
    checkNumber(0);
    checkNumber(1);
    checkNumber(2);
}

void checkNumber(int number)
{
    bool result = task3::checkSimpleNumber(number);
    if (result)
    {
        printf("Number %d is simple\n", number);
        return;
    }

    printf("Number %d is NOT simple\n", number);
}
