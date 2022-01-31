#include <stdio.h>

namespace task4
{
    // 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
    void decimalToBinary(int number)
    {
        if (number <= 0)
            return;

        int output_value = number % 2;
        number /= 2;
        decimalToBinary(number);
        printf("%d", output_value);

    }

    // 2. Реализовать функцию возведения числа [a] в степень [b]:
    //- Рекурсивно.
    //- Рекурсивно, используя свойство чётности степени (то есть, если степень, в которую нужно возвести число,
    // чётная, основание возводится в квадрат, а показатель делится на два, а если степень нечётная -
    // результат умножается на основание, а показатель уменьшается на единицу)
    int pow(int number, int power)
    {
        if (power == 1)
            return number;

        return number * pow(number, power - 1);
    }

    int powWithParity(int number, int power)
    {
        if (power == 1)
            return number;

        if (power % 2 != 0)
            return number * powWithParity(number, power - 1);

        number *= number;
        power /= 2;
        return powWithParity(number, power);
    }

    // 3. Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица -
    // это наличие препятствия, а ноль - свободная для хода клетка)(король начинает путь с клетки 0,0)
    const size_t SIZE_X = 5;
    const size_t SIZE_Y = 5;

//    int arr[SIZE_X][SIZE_Y] = {
//            { 0, 0, 0, 0, 0},
//            { 0, 0, 1, 0, 0},
//            { 0, 0, 0, 0, 0},
//            { 0, 0, 0, 0, 0},
//            { 0, 0, 0, 0, 0}
//    };

    int arr[SIZE_X][SIZE_Y] = {
        { 0, 0, 0, 0, 0},
        { 0, 1, 0, 1, 0},
        { 0, 1, 0, 0, 0},
        { 0, 0, 0, 1, 1},
        { 0, 0, 0, 0, 0},
    };

    int kingRoutes(int x, int y)
    {
        if (x == 0 && y == 0)
            return 0;

        if (x == 0 || y == 0)
            return 1;

        if (arr[y][x] == 1)
            return 0;

        return kingRoutes(x, y - 1) + kingRoutes(x - 1, y);
    }
}
