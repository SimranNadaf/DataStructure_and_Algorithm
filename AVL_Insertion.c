#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node *createNode(int key)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getHeight(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int getBalancedFactor(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

// Right rotation
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

// Left rotation
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    // after insertion
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int bf = getBalancedFactor(node);

    // Left Left Rotate
    if (bf > 1 && key < node->left->data)
    {
        return rightRotate(node);
    }
    // Right Rigth Rotate
    if (bf < -1 && key > node->right->data)
    {
        return leftRotate(node);
    }
    // Left Right rotate
    if (bf > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Rotate
    if (bf < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    preOrder(root);

    return 0;
}