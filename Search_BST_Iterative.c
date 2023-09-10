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
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

struct Node *SearchInterative(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    //     10
    //    /  \
    //   8    15
    //  / \
    // 3   9
    struct Node *p1 = createNode(10);
    struct Node *p2 = createNode(8);
    struct Node *p3 = createNode(15);
    struct Node *p4 = createNode(3);
    struct Node *p5 = createNode(9);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;

    inOrder(p1);
    printf("\n");

    struct Node* result=SearchInterative(p1,10);
    if(result != NULL){
        printf("Found : %d ",result->data);
    }
    else{
        printf("Element not Found \n");
    }
    return 0;
}