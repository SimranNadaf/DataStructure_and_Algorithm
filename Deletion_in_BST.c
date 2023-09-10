#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inOrder(struct Node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

struct Node* inOrderpredecessor(struct Node* root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}

struct Node* Delete(struct Node* root, int value){
    struct Node* ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(value < root->data){
        root->left=Delete(root->left,value);
    }
    else if(value > root->data){
        root->right=Delete(root->right,value);
    }
    else{
        ipre=inOrderpredecessor(root);
        root->data=ipre->data;
        root->left=Delete(root->left,ipre->data);
    }
    return root;
}

int main(){
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
    Delete(p1,8);
    inOrder(p1);
    printf("\n%d ",p2->data);
    return 0;
}