#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct element{
    char name[100];
    int age;
    float height;
}element;

typedef struct Node{
    element data;
    struct  Node* next;
}NODE;

typedef struct linked_list{
    NODE *head;
    NODE *tail;
    int size;
}Linked_list;

Linked_list* creat(){
    Linked_list *list = (Linked_list*)malloc(sizeof(Linked_list));
    list->head = list->tail = NULL;
    list->size = 0;
    return list;
}

Linked_list *insert_last(Linked_list* list, element data){
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    if(list->head == NULL){
        list->head = list->tail = new_node;
    }else{
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->tail->next = NULL;
    return list;
}

void print_list(Linked_list* list)
{
    for(NODE *p = list->head; p != NULL; p = p->next){
        printf("name: %s, age: %d, height: %f\n", p->data.name, p->data.age, p->data.height);
        printf("next\n");
    }
}

int main()
{
    Linked_list *list = creat();
    element data;

    strcpy(data.name, "kim");
    data.age = 34;
    data.height = 1.7;
    list = insert_last(list, data);

    strcpy(data.name, "park");
    data.age = 27;
    data.height = 1.5;
    list = insert_last(list, data);

    strcpy(data.name, "lee");
    data.age = 45;
    data.height = 1.9;
    list = insert_last(list, data);

    print_list(list);

}