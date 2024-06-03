/*
 * This program demonstrates the data structure of a binary tree
 * Your task is specified in the exam
 */
#include <stdio.h>
#include <stdlib.h>
// This is one node of the tree
typedef struct
{
    int data;    // data which is stored in the node
    void *left;  // pointer to the left sub-tree
    void *right; // pointer to the right sub-tree
} Node;
/*
 * This function creates an empty nde
 */
Node *CreateNode(int val)
{
    Node *p; // pointer to the new node
    // create the node
    p = (Node *)malloc(sizeof(Node));
    // store the value
    p->data = val;
    // Left and right child for node
    // will be initialized to null
    p->left = NULL;
    p->right = NULL;
    // return the new node
    return p;
}

void FreeTree(Node *node)
{
    if (node != NULL)
    {
        FreeTree((Node *)node->left);
        FreeTree((Node *)node->right);
        free(node);
    }
}

/*
 * Main - create a simple tree
 */
int main()
{
    /*create root*/
    Node *root = CreateNode((int)'A');

    // create two sub-trees
    root->left = CreateNode('2');
    root->right = CreateNode(0x41);
    // and one more sub-tree
    ((Node *)root->left)->left = CreateNode(67);

    // Free the memory of the tree
    FreeTree(root);

    return 0;
}