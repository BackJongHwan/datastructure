#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct Node_
{
    element data;
    struct Node_* link;
}Node;

void print_list(Node *head){
    if(head == NULL){
        printf("Emepy list!!\n");
        return;
    }
    Node *p = head->link;
    do{
        printf("%d-> ", p->data);
        p = p->link;
    }while(p != head);
    printf("%d\n", p->data);
}

void insert_first(Node **head, element data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if((*head) == NULL){
        (*head) = new_node;
        new_node->link = (*head);
    }else{
        new_node->link = (*head)->link;
        (*head)->link = new_node;
    }
}

void insert_last(Node **head, element data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    if((*head) == NULL){
        (*head) = new_node;
        new_node->link = (*head);
    }else{
        new_node->link = (*head)->link;
        (*head)->link = new_node;
        (*head) = new_node;
    }
}

Node* serch(Node *head, element data){
    if(head == NULL){
        printf("Empty!!\n");
        return 0;
    }
    Node *p = head->link;
    do{
        if(p->data == data){
           return p; 
        }
        p = p->link;
    }while(p != head);
    if(p->data == data){
        return p;   
    }
    return 0;
}

int main()
{
	Node *head = NULL;
	// list = 10->20->30->40
	insert_last(&head, 20);
	insert_last(&head, 30);
	insert_last(&head, 40);
	insert_first(&head, 10);
    Node *p = serch(head, 24);
    p = serch(head, 40);
    printf("%d\n", p->data);
	print_list(head);
}