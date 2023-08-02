#include<stdio.h>
#include<stdlib.h>


typedef int element;

typedef struct Node_
{
   element data;
   struct Node_ *link;
}Node;

typedef struct Linked_list
{
    Node *head;
    Node *tail;
    int size;
}Linked_list; 


void creat_list(Linked_list **list)
{
    *list = (Linked_list*)malloc(sizeof(Linked_list));
    (*list)->head = (*list)->tail = NULL;
    (*list)->size = 0;
}

void insert_last(Linked_list **list, element data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->link = NULL;
    if((*list)->head == NULL){
        (*list)->head = (*list)->tail = new_node;
    }else{
        Node *temp = (*list)->head;
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = new_node;
        (*list)->tail = new_node;
    }
    (*list)->size++;
}
void split(Linked_list *splited_list, Linked_list **list1, Linked_list **list2)
{
    Node* temp1 = (*list1)->head;
    Node* temp2 = (*list2)->head;
    Node *split_node = splited_list->head;
    int i = 1;
    while(split_node != NULL){
        if(i % 2 == 1){
            insert_last(&(*list1), split_node->data);
        }else{
            insert_last(&(*list2), split_node->data);
        }
        split_node = split_node->link;
        i++;
    }
}
void print_list(Linked_list *list){
    if(list->head == NULL){
        printf("Emepy list!!\n");
    }else{
        Node *temp = list->head;
        while(temp->link != NULL){
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}
int main()
{
    Linked_list *a, *b, *c;
    creat_list(&a); creat_list(&b); creat_list(&c);
    for(int i = 1; i < 10; i++){
        insert_last(&c, i);
    }
    print_list(c);
    split(c, &a, &b);
    print_list(c);
    print_list(a);
    print_list(b);
}