#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef int element;

typedef struct Node_{
    element data;
    struct Node_ *left;
    struct Node_ *right;
}Node;

int top = -1;
Node *stack[SIZE];

void push(Node *p){
    if(top < SIZE -1)
        stack[++top] = p;
}

Node* pop(){
    Node *p = NULL;
    if(top > -1)
        p = stack[top--];
    return p;
}

void inoder_stack(Node *root){
    while(1){
        while(1){
            if(root == NULL)
                break;
            push(root);
            root = root->left;
        }
        root = pop();
        if(!root) break;
        printf("%d-> ", root->data);
        root = root->right;
    }
}

void preoder_stack(Node *root){
    while(1){
        while(1){
            if(!root) break;
            printf("%d->", root->data);
            push(root);
            root = root->left;
        }
        root = pop();
        if(!root) break;
        root = root->right;
    }
}

void postorder_stack(Node *root){
    Node *temp = NULL;
    while(1){
        while(1){
            if(!root)break;
            push(root);
            root = root->left;
        }
        root = pop();
        if(!root)break;
        if(!(root->right)){
            printf("%d->", root->data);
            root = NULL;
        }else{
            if(temp == root){
                printf("%d->", root->data);
                root = pop();
                temp = root;
                push(root);
                root = NULL;
            }else{
                push(root);
                temp = root;
                root = root->right;
            }
        }
    }
}

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root != NULL){
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void postorder(Node *root){
    if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
    }  
}

int main()
{
    Node **n = (Node**)malloc(sizeof(Node*));
    for(int i = 0; i < 7; i++){
        *(n + i) = (Node*)malloc(sizeof(Node));
    }
    (*n)[0].data = 17;
    (*n)[0].left = &(*n)[1];
    (*n)[0].right = &(*n)[2];
    (*n)[1].data = 15;
    (*n)[1].left = &(*n)[3];
    (*n)[1].right = NULL;
    (*n)[3].data = 5;
    (*n)[3].left = NULL;
    (*n)[3].right = NULL;
    (*n)[2].data = 93;
    (*n)[2].left = &(*n)[4];
    (*n)[4].data = 35;
    (*n)[2].right = &(*n)[5];
    (*n)[5].data = 95;
    (*n)[5].left = NULL;
    (*n)[5].right = NULL;
    (*n)[4].left = &(*n)[6];
    (*n)[4].right = NULL;
    (*n)[6].data = 22;
    (*n)[6].left = NULL;
    (*n)[6].right = NULL;

    printf("preorder: ");
    preorder(n[0]);
    printf("\n");
    printf("inorder: ");
    inorder(n[0]);
    printf("\n");
    printf("postorder: ");
    postorder(n[0]);
    printf("\n");
    printf("inorder: ");
    inoder_stack(n[0]);
    printf("\n");
    printf("preorder: ");
    preoder_stack(n[0]);
    printf("\n");
    printf("postorder: ");
    postorder_stack(n[0]);
}