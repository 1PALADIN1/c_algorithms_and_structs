
namespace task3
{
    bool checkSimpleNumber(int number)
    {
        // 0 НЕ является натуральным числом, следовательно, и простым тоже
        if (number == 0)
            return false;

        if (number == 1)
            return true;

        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
                return false;
        }

        return true;
    }
}
