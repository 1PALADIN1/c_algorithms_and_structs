#include <stdio.h>
#define true 1 == 1
#define false 1 != 1

namespace binaryTree
{
    typedef int boolean;

    typedef struct Node {
        int key;
        struct Node *left;
        struct Node *right;
    } TreeNode;

    TreeNode* insert(TreeNode *treeNode, int data)
    {
        TreeNode* newNode = new TreeNode();
        newNode->key = data;
        newNode->left = nullptr;
        newNode->right = nullptr;

        TreeNode *current = treeNode;
        TreeNode *parent = treeNode;

        if (treeNode == nullptr)
        {
            treeNode = newNode;
            return newNode;
        }

        while (current->key != data)
        {
            parent = current;
            if (current->key > data)
            {
                current = current->left;
                if (current == nullptr)
                {
                    parent->left = newNode;
                    return newNode;
                }
            }
            else
            {
                current = current->right;
                if (current == nullptr)
                {
                    parent->right = newNode;
                    return newNode;
                }
            }
        }

        return newNode;
    }

    TreeNode* getSuccessor(TreeNode *node)
    {
        TreeNode *current = node->right;
        TreeNode *parent = node;
        TreeNode *s = node;

        while (current != nullptr)
        {
            parent = s;
            s = current;
            current = current->left;
        }

        if (s != node->right)
        {
            parent->left = s->right;
            s->right = node->right;
        }

        return s;
    }

    void remove(TreeNode *root, int key)
    {
        TreeNode *current = root;
        TreeNode *parent = root;
        boolean isLeftChild = true;

        while (current->key != key)
        {
            parent = current;
            if (key < current->key)
            {
                current = current->left;
                isLeftChild = true;
            }
            else
            {
                current = current->right;
                isLeftChild = false;
            }

            if (current == nullptr)
                return;
        }

        if (current->left == nullptr && current->right == nullptr)
        {
            if (current == root)
            {
                TreeNode *tmp = root;
                root = nullptr;
                delete tmp;
            }
            else if (isLeftChild)
            {
                TreeNode *tmp = parent->left;
                parent->left == nullptr;
                delete tmp;
            }
            else
            {
                TreeNode *tmp = parent->right;
                parent->right = nullptr;
                delete tmp;
            }
        }
        else if (current->right == nullptr)
        {
            if (isLeftChild)
                parent->left = current->left;
            else
                parent->right = current->left;
        }
        else if (current->left == nullptr)
        {
            if (isLeftChild)
                parent->left = current->right;
            else
                parent->right = current->right;
        }
        else
        {
            TreeNode *successor = getSuccessor(current);
            if (current == root)
                root = successor;
            else if (isLeftChild)
                parent->left = successor;
            else
                parent->right = successor;

            successor->left = current->left;
        }
    }

    void dispose(TreeNode *tree)
    {
        if (tree == nullptr)
            return;

        TreeNode *tmp = tree;
        dispose(tree->left);
        dispose(tree->right);

        tree = nullptr;
        delete tmp;
    }

    void printTree(TreeNode *root)
    {
        if (root)
        {
            printf("%d", root->key);
            if (root->left || root->right)
            {
                printf("(");
                if (root->left)
                    printTree(root->left);
                else
                    printf("NULL");

                printf(",");

                if (root->right)
                    printTree(root->right);
                else
                    printf("NULL");

                printf(")");
            }
        }
    }
}