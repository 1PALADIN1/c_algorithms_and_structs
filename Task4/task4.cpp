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

    int pow_with_parity(int number, int power)
    {
        if (power == 1)
            return number;

        if (power % 2 != 0)
        {
            return number * pow_with_parity(number, power - 1);

        }

        number *= number;
        power /= 2;
        return pow_with_parity(number, power);
    }

    // 3. Реализовать нахождение количества маршрутов шахматного короля с препятствиями (где единица -
    // это наличие препятствия, а ноль - свободная для хода клетка)(король начинает путь с клетки 0,0)

    //TODO
}
