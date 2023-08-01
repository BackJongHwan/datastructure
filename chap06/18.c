#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node
{
    element data;
    struct Node *link;
}Node;

typedef struct Linked_list
{
    Node *head;
    Node *tail;
    int size;
}Linked_list;

Linked_list* creat_list()
{
    Linked_list *list = (Linked_list*)malloc(sizeof(Linked_list));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

Linked_list *insert_order(Linked_list *list, element data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = NULL;
    if(list->head == NULL){
        list->head = list->tail = new_node;
    }else{
        Node *temp = list->head;
        if(data > list->head->data){
            new_node->link = list->head;
            list->head = new_node;   
        }else{
            while(temp->link != NULL){
                if(temp->link->data < data){
                    new_node->link = temp->link;
                    temp->link = new_node;
                    break;
                }
            }
        }
        if(temp->link == NULL){
            temp->link = new_node;   
        }

    } 
}
void print_list(Linked_list *list){
    Node *temp = list->head;
    while(temp->link != NULL){
        printf("%d-> ", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
    printf("\n");
}

int main()
{
    Linked_list *list1;
    list1 = creat_list();
    list1 = insert_order(list1, 7);
    list1 = insert_order(list1, 6);
    list1 = insert_order(list1, 48);
    list1 = insert_order(list1, 23);
    print_list(list1);
}