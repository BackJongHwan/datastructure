#include<stdio.h>
#include<stdlib.h>


typedef int element;

typedef struct Node_
{
    element data;
    struct Node_ *left, *right;
}Node;

Node* make_node(element data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
}

int get_height(Node *root){
    int height = 0;
    while(root){
        height = 1 + max(get_height(root->left), get_height(root->right));
    }
    return height;
}

int isBalanced(Node *root){
    if(root->left != NULL && root->right != NULL){
        if(get_height(root->left) == get_height(root->right)
        || get_height(root->left) - 1 == get_height(root->right)
        || get_height(root->right - 1 == get_height(root->left)))
            return 1;
    }
    return 0;
}
void free_tree(Node* root){

}