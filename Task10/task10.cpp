#include <stdio.h>
#include <string.h>
#include "stack_task10.h"
#include "linkedlist.h"

#define true 1 == 1
#define false 1 != 1

namespace task10
{
    typedef int boolean;

    /*
     * 1. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
     * Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
     * Например: (2+(2*2)) или [2/{5*(4+7)}]
     */
    boolean isBracket(char symbol)
    {
        return symbol == '(' || symbol == '{' || symbol == '[' || symbol == ')' || symbol == '}' || symbol == ']';
    }

    boolean isOpening(char symbol)
    {
        return symbol == '(' || symbol == '{' || symbol == '[';
    }

    boolean isCorrectClosing(char open_symbol, char close_symbol)
    {
        if (open_symbol == '(' && close_symbol == ')')
            return true;

        if (open_symbol == '{' && close_symbol == '}')
            return true;

        if (open_symbol == '[' && close_symbol == ']')
            return true;

        return false;
    }

    void checkExpression(char* expr)
    {
        printf("%s, %d\n", expr, strlen(expr));
        stack_task10::init();

        for (int i = 0; i < strlen(expr); ++i)
        {
            if (!isBracket(expr[i]))
                continue;

            if (stack_task10::getSize() == 0 || isOpening(expr[i]))
            {
                stack_task10::push(expr[i]);
                continue;
            }

            char open_symbol = stack_task10::peek();
            if (!isCorrectClosing(open_symbol, expr[i]))
                break;

            stack_task10::pop();
        }

        if (stack_task10::getSize() == 0)
        {
            printf("Expression %s is VALID\n", expr);
        }
        else
        {
            printf("Expression %s is NOT VALID\n", expr);
        }

        stack_task10::dispose();
    }

    /* 2. Создать функцию, копирующую односвязный список (без удаления первого списка). */
    void copyLinkedList(linkedlist::List *start_list, linkedlist::List *result_list)
    {
        printf("Copy start list: ");
        linkedlist::printList(start_list);

        linkedlist::Node *current = start_list->head;
        while (current != nullptr)
        {
            linkedlist::insert(result_list, current->data);
            current = current->next;
        }

        printf("List successfully copied! Result:\n");
        linkedlist::printList(result_list);
    }

    /* 3. Реализуйте алгоритм, который определяет, отсортирован ли связный список. */

    // ================ Тестирование ================

    void checkExpressionTest()
    {
        //true
        char test_expr1[] = "()";
        checkExpression(test_expr1);
        char test_expr2[] = "([])()";
        checkExpression(test_expr2);
        char test_expr3[] = "{}()";
        checkExpression(test_expr3);
        char test_expr4[] = "([{}])";
        checkExpression(test_expr4);

        //false
        char test_expr5[] = ")(";
        checkExpression(test_expr5);
        char test_expr6[] = "())({)";
        checkExpression(test_expr6);
        char test_expr7[] = "(";
        checkExpression(test_expr7);
        char test_expr8[] = "])}))";
        checkExpression(test_expr8);
        char test_expr9[] = "([(])";
        checkExpression(test_expr9);

        //true with numbers
        char test_expr10[] = "(2+(2*2))";
        checkExpression(test_expr10);
        char test_expr11[] = "[2/{5*(4+7)}]";
        checkExpression(test_expr11);
    }

    void copyLinkedListTest()
    {
        linkedlist::List *start_list = new linkedlist::List();
        linkedlist::init(start_list);
        linkedlist::insert(start_list, 12);
        linkedlist::insert(start_list, 1);
        linkedlist::insert(start_list, 15);
        linkedlist::insert(start_list, 332);
        linkedlist::insert(start_list, -34);
        linkedlist::insert(start_list, 184);
        linkedlist::insert(start_list, 2);

        linkedlist::List *result_list = new linkedlist::List();
        linkedlist::init(result_list);

        copyLinkedList(start_list, result_list);
    }

    void execute()
    {
        printf("=============== LESSON 10 ===============\n");
        printf("-> Task1:\n");
        checkExpressionTest();

        printf("-> Task2:\n");
        copyLinkedListTest();
    }
}