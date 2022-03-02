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
    std::string encodePermutationCipher(std::string message, int key)
    {
        int block_size = message.length() % key == 0 ? message.length() / key : message.length() / key + 1;
        int total_len = block_size * key;
        char* result = new char[total_len];

        int index = 0;
        for (int i = 0; i < key; ++i)
        {
            for (int j = i; j < total_len; j += key)
            {
                result[index] = j < message.length() ? message[j] : '_';
                index++;
            }
        }

        std::string out = std::string(result, total_len);
        delete[] result;
        return out;
    }

    std::string decodePermutationCipher(std::string message, int key)
    {
        int block_size = message.length() / key;
        char* result = new char[message.length()];

        int index = 0;

        for (int i = 0; i < block_size; ++i)
        {
            for (int j = i; j < message.length(); j += block_size)
            {
                result[index] = message[j];
                index++;
            }
        }

        std::string out = std::string(result, message.length());
        delete[] result;
        return out;
    }

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

    void permutationCipherTest()
    {
        std::string message = "thisisasecretmessagetest";

        int key = 5;

        //1
        std::cout << "Encode: \'" << message << "\' -> ";
        message = encodePermutationCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        std::cout << "Decode: \'" << message << "\' -> ";
        message = decodePermutationCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        //2
        key = 4;

        std::cout << "Encode: \'" << message << "\' -> ";
        message = encodePermutationCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        std::cout << "Decode: \'" << message << "\' -> ";
        message = decodePermutationCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        //3
        key = 7;

        std::cout << "Encode: \'" << message << "\' -> ";
        message = encodePermutationCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

        std::cout << "Decode: \'" << message << "\' -> ";
        message = decodePermutationCipher(message, key);
        std::cout << "\'" << message << "\' [key:" << key << "]" << std::endl;

    }

    void execute()
    {
        printf("=============== LESSON 16 ===============\n");
        printf("-> Task1:\n");
        caesarCipherTest();

        printf("-> Task2:\n");
        permutationCipherTest();
    }
}