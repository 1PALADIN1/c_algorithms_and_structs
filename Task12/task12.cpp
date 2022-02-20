#include <stdio.h>
#include <math.h>
#include <ctime>
#include "binaryTree.h"
#define true 1 == 1
#define false 1 != 1

namespace task12
{
    typedef int boolean;

    /*
     * 1. Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным
     * и написать программу, которая: создаст [50] деревьев по [10000] узлов и заполнит узлы
     * случайными целочисленными значениями;
     * рассчитает, какой процент из созданных деревьев является сбалансированными.
     */

    boolean treeIsBalanced;

    size_t calculateDepth(binaryTree::TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        size_t depth_l = calculateDepth(root->left);
        size_t depth_r = calculateDepth(root->right);

        treeIsBalanced = fabs(depth_l - depth_r) <= 1;
        size_t max_d = (depth_l > depth_r ? depth_l : depth_r) + 1;
        return max_d;
    }

    boolean checkTreeBalanced(binaryTree::TreeNode *tree, boolean printResults)
    {
        if (printResults)
        {
            printf("Check balance for tree: ");
            binaryTree::printTree(tree);
            printf("\n");
        }

        calculateDepth(tree);

        if (printResults)
            printf("Tree is %s\n", treeIsBalanced ? "BALANCED" : "NOT BALANCED");

        return treeIsBalanced;
    }

    /*
     * 2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
     */
    void binarySearch(binaryTree::TreeNode *tree)
    {
    }

    // ================ Тестирование ================

    void checkTreeBalancedTest()
    {
        //несбалансированное дерево
        binaryTree::TreeNode *tree = binaryTree::insert(nullptr, 10);
        binaryTree::insert(tree, 10);
        binaryTree::insert(tree, 8);
        binaryTree::insert(tree, 25);
        binaryTree::insert(tree, 1'223);
        binaryTree::insert(tree, 49);
        binaryTree::insert(tree, 12'34);
        binaryTree::insert(tree, 999);
        binaryTree::insert(tree, 544);

        checkTreeBalanced(tree, true);

        binaryTree::dispose(tree);

        //сбалансированное дерево
        tree = binaryTree::insert(nullptr, 8);
        binaryTree::insert(tree, 10);
        binaryTree::insert(tree, 3);
        binaryTree::insert(tree, 1);
        binaryTree::insert(tree, 6);
        binaryTree::insert(tree, 7);
        binaryTree::insert(tree, 4);
        binaryTree::insert(tree, 14);
        binaryTree::insert(tree, 13);

        checkTreeBalanced(tree, true);

        binaryTree::dispose(tree);
    }

    int getRandomNumber(int maxElement)
    {
        return rand() % maxElement;
    }

    void checkRandomTreeBalancedTest()
    {
        const size_t TREES_AMOUNT = 50;
        const size_t NODES_AMOUNT = 10'000;
        const size_t MAX_ELEMENT = 10'000;
        srand( time(0) );

        size_t balancedAmount = 0;

        for (int tree_index = 0; tree_index < TREES_AMOUNT; ++tree_index)
        {
            binaryTree::TreeNode *tree = binaryTree::insert(nullptr, getRandomNumber(MAX_ELEMENT));

            for (int node_index = 0; node_index < NODES_AMOUNT - 1; ++node_index)
                binaryTree::insert(tree, getRandomNumber(MAX_ELEMENT));

            if (checkTreeBalanced(tree, false))
                balancedAmount++;

            binaryTree::dispose(tree);
        }

        printf("Balanced percent = %.2f%\n", (float)balancedAmount / TREES_AMOUNT * 100);
    }

    void binarySearchTest()
    {
    }

    void execute()
    {
        printf("=============== LESSON 12 ===============\n");
        printf("-> Task1.1:\n");
        checkTreeBalancedTest();

        printf("-> Task1.2:\n");
        checkRandomTreeBalancedTest();

//        printf("-> Task2:\n");
//        binarySearchTest();
    }
}