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

    void init(List *lst);

    void insert(List *lst, int data);
    Node* remove(List *lst, int data);
    void printList(List *lst);

    void dispose(List *lst);
}
