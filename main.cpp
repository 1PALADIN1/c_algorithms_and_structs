#include <stdio.h>

#include "Task2/task2.h"
#include "Task3/task3.h"
#include "Task4/task4.h"

//урок 2
void execute_lesson2();

//урок 3
void execute_lesson3();
void checkNumberTest(int number);

//урок 4
void execute_lesson4();
void decimalToBinaryTest(int number);
void powerTest(int number, int power);
void powerWithParityTest(int number, int power);
void kingPathTest();

int main(int argc, char *argv[])
{
    execute_lesson2();
    execute_lesson3();
    execute_lesson4();

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
    checkNumberTest(7);
    checkNumberTest(10);
    checkNumberTest(23);
    checkNumberTest(2'100'127);
    checkNumberTest(0);
    checkNumberTest(1);
    checkNumberTest(2);
}

void checkNumberTest(int number)
{
    bool result = task3::checkSimpleNumber(number);
    if (result)
    {
        printf("Number %d is simple\n", number);
        return;
    }

    printf("Number %d is NOT simple\n", number);
}

void execute_lesson4()
{
    printf("=============== LESSON 4 ===============\n");
    printf("-> Task1:\n");
    decimalToBinaryTest(3);
    decimalToBinaryTest(7);
    decimalToBinaryTest(16);
    decimalToBinaryTest(236'645);

    printf("-> Task2:\n");
    printf("1) Recursive:\n");
    powerTest(2, 3);
    powerTest(6, 7);
    powerTest(10, 6);
    powerTest(3, 10);
    powerTest(2, 10);

    printf("2) Recursive with degree parity:\n");
    powerWithParityTest(2, 3);
    powerWithParityTest(6, 7);
    powerWithParityTest(10, 6);
    powerWithParityTest(3, 10);
    powerWithParityTest(2, 10);

    printf("-> Task3:\n");
    kingPathTest();
}

void decimalToBinaryTest(int number)
{
    printf("%d >>> ", number);
    task4::decimalToBinary(number);
    printf("\n");
}

void powerTest(int number, int power)
{
    int result = task4::pow(number, power);
    printf("%d ^ %d >>> %d\n", number, power, result);
}

void powerWithParityTest(int number, int power)
{
    int result = task4::powWithParity(number, power);
    printf("%d ^ %d >>> %d\n", number, power, result);
}

void kingPathTest()
{
    const size_t sizeX = 5;
    const size_t sizeY = 5;

    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            printf("%5d", task4::kingRoutes(x, y));
        }

        printf("\n");
    }
}