namespace stack_task10
{
    typedef struct Node {
        char data;
        struct Node *next;
    } Node;

    void init();

    int getSize();
    void push(char data);
    char peek();
    char pop();

    void dispose();
}