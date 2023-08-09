#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node_
{
    element key;
    struct Node_ *left, *right;
}Node;

Node* serch(Node*node, element key){
    while(node != NULL){
        if(node->key == key) return node;
        else if(key < node->key)
            node = node->left;
        else if(key > node->key)
            node = node->right;
    }
    return node;
}

Node* newnode(element key){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insert_node(Node *node, element key){
    if(node == NULL) return newnode(key);
    if(node->key < key)
        node->right = insert_node(node->right, key);
    else if(node->key > key)
        node->left = insert_node(node->left, key);
    return node;
}

Node* min_value_node(Node* node){
    Node *current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

Node *delete_node(Node* root, element key)
{
    if(root == NULL) return root;
    if(key < root->key){
        root->left = delete_node(root->left, key);
    }else if(key > root->key)
        root->right = delete_node(root->right, key);
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }else{
            Node *temp = min_value_node(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, key);
        }
    }
    return root;
}

void inorder(Node * root) {
	if (root) {
		inorder(root->left);// 왼쪽서브트리 순회
		printf("[%d] ", root->key);  // 노드 방문
		inorder(root->right);// 오른쪽서브트리 순회
	}
}

int sum_tree(Node *root){
    int sum = 0;
    if(root != NULL){
        sum = root->key + sum_tree(root->left) + sum_tree(root->right);
    }
    return sum;
}

void show_node_value(Node *root, element value){
    if(root == NULL)return;
    if(value > root->key)
        printf("%d보다 작은 노드: %d\n", value, root->key);
    show_node_value(root->left, value);
    show_node_value(root->right, value);
    // show_node_value(root->left, value);
    // show_node_value(root->right, value);
}

int num_one_chile(Node *root){
    int count = 0;
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right != NULL){
        count = 1 + num_one_chile(root->right);
    }else if(root->right == NULL && root->left != NULL){
        count = 1 + num_one_chile(root->left);
    }
    return count;
}

int main()
{
    Node *root = NULL;
    //int value;
    int num;
    root = insert_node(root,6);
    root = insert_node(root, 4);
    root = insert_node(root, 9);
    root = insert_node(root, 5);
    root = insert_node(root, 2);
    root = insert_node(root, 3);
    root = insert_node(root, 1);
    root = insert_node(root, 7);
    root = insert_node(root, 10);
    root = insert_node(root, 8);
    root = insert_node(root, 11);
    root = insert_node(root, 12);
    // root = insert_node(root, 11);
    // root = insert_node(root, 6);
    // root = insert_node(root, 8);
    // root = insert_node(root, 19);
    // root = insert_node(root, 4);
    // root = insert_node(root, 10);
    // root = insert_node(root, 5);
    // root = insert_node(root, 17);
    // root = insert_node(root, 43);
    // root = insert_node(root, 49);
    // root = insert_node(root, 31);
    // printf("값을 입력하세요: ");
    // scanf("%d", &value);
    // show_node_value(root, value);
    num = num_one_chile(root);
    printf("number of one child is %d\n", num);

 }