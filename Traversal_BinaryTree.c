#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void PreOrder(struct Node* root){
    if(root != NULL){
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct Node* root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}

void InOrder(struct Node* root){
    if(root != NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

int main(){
    //     10
    //    /  \
    //    5   2
    //   / \
    //   7  4
    struct Node *p1=createNode(10);
    struct Node *p2=createNode(5);
    struct Node *p3=createNode(2);
    struct Node *p4=createNode(7);
    struct Node *p5=createNode(4);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    
    printf("Binary Tree representation in Pre order : ");
    PreOrder(p1);
    printf("\nBinary Tree representation in Post order : ");
    PostOrder(p1);
    printf("\nBinary Tree representation in In order : ");
    InOrder(p1);
    
    return 0;
}