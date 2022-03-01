#include <stdio.h>
#include <iostream>
#include <string>

namespace task16
{
    /*
     * 1. Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом
     */
    std::string encodeCaesarCipher(std::string message, int key)
    {
        for (int i = 0; i < message.length(); ++i)
        {
            char check_char = message[i];

            if (check_char >= 97 && check_char <= 122)
            {
                // a - z -> 97 - 122
                check_char += key;
                if (check_char > 122)
                    check_char = 97 + check_char % 122;
            }
            else if (check_char >= 65 && check_char <= 90)
            {
                // A - Z -> 65 - 90
                check_char += key;
                if (check_char > 90)
                    check_char = 65 + check_char % 90;
            }

            message = message.replace(i, 1, std::string(1, check_char));
        }

        return message;
    }

    std::string decodeCaesarCipher(std::string message, int key)
    {
        for (int i = 0; i < message.length(); ++i)
        {
            char check_char = message[i];

            if (check_char >= 97 && check_char <= 122)
            {
                // a - z -> 97 - 122
                check_char -= key;
                if (check_char < 97)
                    check_char = 122 - (97 - check_char);
            }
            else if (check_char >= 65 && check_char <= 90)
            {
                // A - Z -> 65 - 90
                check_char -= key;
                if (check_char < 65)
                    check_char = 90 - (65 - check_char);
            }

            message = message.replace(i, 1, std::string(1, check_char));
        }

        return message;
    }

    /*
     * 2. Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
     */

    // ================ Тестирование ================

    void caesarCipherTest()
    {
        //1
        std::string message = "This is a secret message!";
        int key = 5;

        std::cout << "Encode: \'" << message << "\' -> ";
        message = encodeCaesarCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        std::cout << "Decode: \'" << message << "\' -> ";
        message = decodeCaesarCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        //2
        std::string message2 = "TEST MESSAGE TEST! HELLO WORLD! HELLO!";
        key = 9;

        std::cout << "\'" << message2 << "\' -> ";
        message2 = encodeCaesarCipher(message2, key);
        std::cout << "\'" << message2 << "\' [key:" << key << "]" << std::endl;

        std::cout << "Decode: \'" << message2 << "\' -> ";
        message2 = decodeCaesarCipher(message2, key);
        std::cout << "\'" << message2 << "\' [key:" << key << "]" << std::endl;
    }

    void execute()
    {
        printf("=============== LESSON 16 ===============\n");
        printf("-> Task1:\n");
        caesarCipherTest();
    }
}