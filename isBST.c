#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct Node *root)
{
    if (!(root == NULL))
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (!(root == NULL))
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        printf("%d ", prev->data);
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    /*
            25
           /  \
          20  30
         /  \
        12  21     */

    struct Node *p = createNode(25);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(30);
    struct Node *p3 = createNode(12);
    struct Node *p4 = createNode(21);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // inOrder(p);

    if (isBST(p))
    {
        printf("\nTree is BST\n");
    }
    else
    {
        printf("\nTree is not BST\n");
    }

    return 0;
}