namespace binaryTree
{
    typedef struct Node {
        int key;
        struct Node *left;
        struct Node *right;
    } TreeNode;

    TreeNode* insert(TreeNode *treeNode, int data);
    void remove(TreeNode *root, int data);
    void dispose(TreeNode *tree);
    void printTree(TreeNode *root);
}