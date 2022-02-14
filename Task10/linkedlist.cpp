#include <stdio.h>

namespace linkedlist
{
    typedef struct Node {
        int data;
        struct Node *next;
    } Node;

    typedef struct {
        Node *head;
        int size;
    } List;

    void init(List *lst)
    {
        lst->head = nullptr;
        lst->size = 0;
    }

    void insert(List *lst, int data)
    {
        Node *node = new Node();
        node->data = data;
        node->next = nullptr;

        Node *current = lst->head;
        if (current == nullptr)
        {
            lst->head = node;
            lst->size++;
            return;
        }

        while (current->next != nullptr)
            current = current->next;

        current->next = node;
        lst->size++;
    }

    Node* remove(List *lst, int data)
    {
        Node *current = lst->head;
        Node *parent = nullptr;

        if (current == nullptr)
            return nullptr;

        while (current->next != nullptr && current->data != data)
        {
            parent = current;
            current = current->next;
        }

        if (current->data != data)
            return nullptr;

        if (current == lst->head)
        {
            lst->head = current->next;
            lst->size--;
            return current;
        }

        parent->next = current->next;
        lst->size--;
        return current;
    }

    void printNode(Node *node)
    {
        if (node == nullptr)
        {
            printf("[]");
            return;
        }

        printf("[%d] ", node->data);
    }

    void printList(List *lst)
    {
        Node* current = lst->head;

        if (current == nullptr)
        {
            printNode(current);
        }
        else
        {
            do {
                printNode(current);
                current = current->next;
            } while (current != nullptr);
        }

        printf(" Size: %d\n", lst->size);
    }

    void dispose(List *lst)
    {
        linkedlist::Node *current = lst->head;
        while (current != nullptr)
        {
            Node *tmp = current;
            current = current->next;
            delete tmp;
        }

        init(lst);
    }
}