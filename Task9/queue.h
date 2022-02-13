namespace queue
{
    typedef struct {
        int priority;
        int data;
    } Node;

    void init();
    void enqueue(int priority, int data);
    Node* dequeue();
    void printQueue();
}