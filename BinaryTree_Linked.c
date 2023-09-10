#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main(){
    // struct Node *p; // Root node of binary tree
    // p=(struct Node*)malloc(sizeof(struct Node));
    // p->data=10;
    // //initialize left and right node of root node with null
    // p->left=NULL;
    // p->right=NULL;
    // //creating Left node(p1) of Root Node(p)
    // struct Node *p1;
    // p1=(struct Node *)malloc(sizeof(struct Node));
    // p1->data=1;
    // p1->left=NULL;
    // p1->right=NULL;
    // //Creating Right node(p2) of Root Node(p)
    // struct Node *p2;
    // p2=(struct Node *)malloc(sizeof(struct Node));
    // p2->data=4;
    // p2->left=NULL;
    // p2->right=NULL;
    // //Link left and right node with root node
    // p->left=p1;
    // p->right=p2;


    // creating a root node using function
    struct Node *p=createNode(10);
    // creating a left node using function
    struct Node *p1=createNode(1);
    // creating a right node using function
    struct Node *p2=createNode(4);
    //liking left andd right node with root node
    p->left=p1;
    p->right=p2;

    return 0;
}