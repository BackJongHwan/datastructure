#include<stdio.h>
#include<stdlib.h>

typedef struct element
{
    int coef;
    int exp;
}element;

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

void creat(Linked_list **list){
    (*list) = (Linked_list*)malloc(sizeof(Linked_list));
    (*list)->head = (*list)->tail = NULL;
    (*list)->size = 0;
}

void insert_last(Linked_list *list, element data){
    Node *new_node =(Node *)malloc(sizeof(Node));
    //new_node->data = data;
    new_node->data.coef = data.coef;
    new_node->data.exp = data.exp;
    new_node->link = NULL;
    if(list->head == NULL){
        list->head = new_node;
    }else{
        Node *temp = list->head;
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = new_node;
        list->tail = new_node; 
   }
   list->size++;
}

void print_list(Linked_list *list){
    Node *temp = list->head;
    while(temp->link != NULL){
        printf("%dx%d + ", temp->data.coef, temp->data.exp);
        temp = temp->link;
    }
    printf("%dx%d\n", temp->data.coef, temp->data.exp);
}
void poly_add(Linked_list *add_list, Linked_list *list1, Linked_list*list2)
{
    Node *a = list1->head;
    Node *b = list2->head;
    element temp;
    while(a != NULL || b != NULL){
        if(a->data.exp > b->data.exp){
            insert_last(add_list, a->data);
            a = a->link;
        }else if(a->data.exp < b->data.exp){
            insert_last(add_list, b->data);
            b = b->link;
        }else{
            temp.exp = a->data.exp;
            temp.coef = a->data.coef + b->data.coef;
            insert_last(add_list, temp);
            a = a->link;
            b = b->link;
        }
   }
    for (; a != NULL; a = a->link)
        insert_last(add_list, a->data);
    for (; b != NULL; b = b->link)
        insert_last(add_list, b->data);
}

int poly_eval(Linked_list *list, int sub){
    Node *temp = list->head;
    int sum = 0;
    int value; 
    while(temp != NULL){
        value = 1; 
        for(int i = 0; i < temp->data.exp; i++){
            value *= sub;
        }
        sum += value * temp->data.coef;
        temp = temp->link;
    }
    return sum;
}

int main()
{
    Linked_list* list1, *list2, *list3;
    creat(&list1); creat(&list2), creat(&list3);
    element data1[4] = {{3, 6}, {7, 3}, {-2, 2}, {-9, 0}};
    element data2[5] = {{-2, 6}, {-4, 4}, {6, 2}, {6, 1}, {1, 0}};
    for(int i = 0; i < 4; i++){
        insert_last(list1, data1[i]);
        insert_last(list2, data2[i]);
    }
    insert_last(list2, data2[4]);
    print_list(list1);
    print_list(list2);
    poly_add(list3, list1, list2);
    print_list(list3);
    printf("%d\n", poly_eval(list3, 2));

    return 0;
}