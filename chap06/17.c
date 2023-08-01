#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node
{
    element data;
    struct Node *link;
}Node;

typedef struct Linkedlist{
    Node *head;
    Node *tail;
    int size;
}Linkedlist;

Linkedlist* init_Linkedlist()
{
    Linkedlist *list = (Linkedlist*)malloc(sizeof(Linkedlist));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

Linkedlist *insert_last(Linkedlist *list, element data)
{   
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = NULL;
    if(list->head == NULL){
        list->head = list->tail = new_node;
    }else{
        list->tail->link = new_node;
        list->tail = list->tail->link;
    }

    list->size++;
}

void print_list(Linkedlist *list)
{
    if(list->head == NULL){
        printf("empty list!\n");
    }else{
        Node *temp = list->head;
        while(temp->link != NULL){
            printf("%d-> ",temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

Linkedlist* alternate(Linkedlist *list1, Linkedlist *list2, Linkedlist *merge_list)
{
    Node *temp1, *temp2;
    temp1 = list1->head;
    temp2 = list2->head;
    while(temp1->link != NULL && temp2->link != NULL){
        merge_list = insert_last(merge_list, temp1->data);
        merge_list = insert_last(merge_list, temp2->data);
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    if(temp1->link != NULL){
        while(temp1->link != NULL){
            merge_list = insert_last(merge_list, temp1->data);
            temp1 = temp1->link;
        }
        merge_list = insert_last(merge_list, temp1->data);
    }else{     
        while(temp2->link != NULL){
            merge_list = insert_last(merge_list, temp2->data);
            temp2 = temp2->link;
        }
        merge_list = insert_last(merge_list, temp2->data);
    }
    return merge_list;
}

int main()
{
    Linkedlist *a, *b;
    a = init_Linkedlist();
    b = init_Linkedlist();
    for(int i = 0; i < 10; i+= 2){
        a = insert_last(a, i);
        b = insert_last(b, i+1);
    }
    for(int i = 0; i < 5; i++){
        b = insert_last(b, i);
    }
    print_list(a);
    print_list(b);
    Linkedlist *c;
    c = init_Linkedlist();
    c = alternate(a, b, c);
    print_list(c);

}