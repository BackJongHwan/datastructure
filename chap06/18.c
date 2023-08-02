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
        if(data > list->head->data){
            new_node->link = list->head;
            list->head = new_node;
        }else{
            Node *temp = list->head;
            while(temp->link != NULL){
                if(data > temp->link->data){
                   new_node->link = temp->link;
                   temp->link = new_node;
                   break; 
                }
                temp = temp->link;
            }
            if(temp->link == NULL){
                temp->link = new_node;
            }
        }
    }
    return list;
}


void print_list(Linked_list *list){
    Node *temp = list->head;
    while(temp->link != NULL){
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
    printf("\n");
}

Linked_list* merge_order(Linked_list *merge_list, Linked_list* list1, Linked_list* list2)
{

    Node *temp1 = list1->head;
    Node *temp2 = list2->head;
    Node *temp3 = merge_list->head;
    while(temp1!= NULL && temp2!=NULL){
        if(merge_list->head == NULL){
            if(temp1->data > temp2->data){
                merge_list->head = temp1;
                temp3 = temp1;
                temp1 = temp1->link;
            }else{
                merge_list->head = temp2;
                temp3 = temp2;
                temp2 = temp2->link;
            }
        }else{
            // while(temp3->link != NULL)
            //     temp3 = temp3->link;
            if(temp1->data > temp2->data){
                temp3->link = temp1;
                temp1 = temp1->link;
            }else{
                temp3->link = temp2;
                temp2 = temp2->link;
            }
            temp3 = temp3->link;
        }
    }
    if(temp1->link != NULL){
        while(temp1->link != NULL){
            temp3->link = temp1;
            temp1 = temp1->link;
        }
    }else{
        while(temp2->link != NULL){
            temp3->link = temp2;
            temp2 = temp2->link;
        }
    }
    return merge_list;
}
int main()
{
    Linked_list *list1, *list2, *list3;
    list1 = creat_list(); list2 = creat_list(); list3 = creat_list();
    list1 = insert_order(list1, 7);
    list1 = insert_order(list1, 6);
    list1 = insert_order(list1, 48);
    list1 = insert_order(list1, 23);
    list2 = insert_order(list2, 993);
    list2 = insert_order(list2, 14);
    list2 = insert_order(list2, 100);
    print_list(list1);
    print_list(list2);
    list3 = merge_order(list3, list1, list2);
    print_list(list3);
    //print_list(list1);
    //print_list(list2);
}
