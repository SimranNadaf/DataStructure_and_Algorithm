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

struct Node * search(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key <= root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
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

    inOrder(p); 
    printf("\n");

    struct Node *searchKey=search(p,12);
    if (searchKey != NULL)
    {
        printf("Found : %d \n", searchKey->data);
    }
    else
    {
        printf("Not Found\n");
    }  
    return 0;
}