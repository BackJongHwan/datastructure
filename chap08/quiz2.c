#include<stdio.h>
#include<stdlib.h>
#define max(a, b) ((a > b ? a : b))
typedef int element;

typedef struct Node_
{
    element data;
    struct Node_ *left, *right;
}Node;

Node* creat_node(element data);
int get_node_count(Node *root);
int get_height(Node *root);
int get_leaf_count(Node* root);
void make_tree(Node *root);
int get_nonleaf_count(Node *root);
int equal(Node* root1, Node* root2);

int main()
{
    Node *root = creat_node(1);
    Node *root2 = creat_node(1);
    make_tree(root);
    make_tree(root2);
    root2->left->left->data = 199;
    int num_node = get_node_count(root);
    int height = get_height(root);
    int num_leaf = get_leaf_count(root);
    int num_nonleaf = get_nonleaf_count(root);
    printf("num_node: %d, height: %d"
    ",num_leaf: %d, num_nonleaf: %d\n", num_node, height, num_leaf, num_nonleaf);
    if(equal(root, root2)){
        printf("equal!!\n");
    }else{
        printf("not eqaul!!\n");
    }
    return 0;
}

Node *creat_node(element data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    return new_node;
}

void make_tree(Node *root){
    root->left = creat_node(2);
    root->right = creat_node(3);
    root->left->left = creat_node(4);
    root->left->right = creat_node(5);
    root->right->left = creat_node(6);
    root->right->right = creat_node(7);
    root->right->left->left = creat_node(8);
    root->right->left->right = creat_node(9);
    root->right->left->left->left = creat_node(10);
    root->right->left->right->right = creat_node(11);
}

void free_tree(Node *root){
    if(root->left != NULL)
    {
        free_tree(root->left);
    }
    if(root->right != NULL){
        free_tree(root->right);
    }
    if(root->left == NULL && root->right == NULL)
        free(root);
}

int get_node_count(Node *root){
    int count = 0;
    if(root != NULL)
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    
    return count;
}

int get_height(Node *root){
    int height = 0;
    if(root != NULL)
        height = 1 + max(get_height(root->left), get_height(root->right));
    return height;
}

int get_leaf_count(Node* root){
    int count = 0;
    if(root != NULL){
        if(root->left == NULL && root->right == NULL)
            count = 1;
        else
            count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int get_nonleaf_count(Node *root){
    int count = 0;
    if(root != NULL){
        if(root->left != NULL || root->right != NULL){
            count = 1 + get_nonleaf_count(root->left) + get_nonleaf_count(root->right);
        }
    }
    return count;
}

int equal(Node* root1, Node* root2){

    if(root1->data != root2->data){
        return 0;
    }
    else{
        if(root1->left == NULL){
            if(root2->left != NULL)
                return 0;
        }else{
            if(!equal(root1->left, root2->left))
                return 0;
        }
        if(root1->right == NULL){
            if(root2->right != NULL)
                return 0;
        }else{
            if(!equal(root1->right, root2->right))
                return 0;
        }
    }
    return 1;
}