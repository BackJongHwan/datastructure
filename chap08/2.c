#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char element [100];

typedef struct Node_
{
    element data;
    struct Node_ *left, *right;
}Node;

void preorder(Node *root){

    if(root != NULL){
        printf("%s->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void preorder2(Node *root){

    if(root != NULL){
        printf("%s", root->data);
        preorder2(root->left);
        preorder2(root->right);
    }
}

void inorder(Node *root){
    if(root){
        inorder(root->left);
        printf("%s->", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%s-> ", root->data);
    }
}

void postorder2(Node *root){
    if(root){
        postorder2(root->left);
        postorder2(root->right);
        printf("%s", root->data);
    }
}

Node* newnode(element data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->left = new_node->right = NULL;
    return new_node;
}

int main()
{
    Node *root = newnode("A");
    root->left = newnode("B");
    root->left->left = newnode("D");
    root->right = newnode("C");
    root->right->left = newnode("E");
    root->right->right = newnode("F");
    preorder(root);
    printf("\n");
    root->right->left->left = newnode("G");
    root->right->left->right = newnode("H");
    preorder(root);
    Node *root2 = newnode("+");
    root2->left = newnode("*");
    root2->right = newnode("E");
    root2->left->right = newnode("D");
    root2->left->left = newnode("*");
    root2->left->left->right = newnode("C");
    root2->left->left->left = newnode("/");
    root2->left->left->left->left = newnode("A");
    root2->left->left->left->right = newnode("B");
    postorder2(root2);
}