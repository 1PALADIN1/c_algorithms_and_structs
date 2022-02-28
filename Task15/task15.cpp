#include <stdio.h>
#include <string.h>

namespace task15
{
    /*
     * 1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
     */
    int stringToHash(char* input_string)
    {
        int hash = 0;
        for (int i = 0; i < strlen(input_string); ++i)
            hash += input_string[i];

        return hash;
    }

    // ================ Тестирование ================

    void stringToHashTest()
    {
        char* test_string1 = "Hello world";
        int hash = stringToHash(test_string1);
        printf("Hash of string \"%s\" = %d\n", test_string1, hash);

        char* test_string2 = "Simple test string!";
        hash = stringToHash(test_string2);
        printf("Hash of string \"%s\" = %d\n", test_string2, hash);

        char* test_string3 = "TEST test test TEST 123 123";
        hash = stringToHash(test_string3);
        printf("Hash of string \"%s\" = %d\n", test_string3, hash);
    }

    void execute()
    {
        printf("=============== LESSON 15 ===============\n");
        printf("-> Task1:\n");
        stringToHashTest();
    }
}