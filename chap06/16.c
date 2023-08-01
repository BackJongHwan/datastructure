#include<stdio.h>
#include<stdlib.h>


typedef int element;

typedef struct Node
{
    element data;
    struct Node *next;
    int size;
}Node;

void create(Node **head)
{
    *head = NULL;
    (*head)->size = 0;
}

void insert(Node **head, element data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        (*head)->size = 0;
    }else{
        Node *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    (*head)->size++;
}

void print_list(Node *head)
{
    if(head == NULL){
        printf("There is no data!!\n");
    }else{
        while(head->next != NULL){
            printf("%d-> ", head->data);
            head = head->next;
        }
        printf("%d", head->data);
    }
    printf("\n");
}

void delete(Node**head, Node* node)
{
    if(*head == node){
        *head = node->next;
        free(node);
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL)
        temp= temp->next;
    temp->next = node->next;
    free(node);
    return;
}

void delete_odd(Node **head)
{
    Node *pre = *head;
    Node *delete = *head;
    *head = (*head)->next;
    pre = pre->next;
    free(delete);

    while (pre != NULL && pre->next != NULL) {
        delete = pre->next;
        pre->next = delete->next;
        free(delete);
        pre = pre->next;
    }

}

int main()
{
    Node *list = NULL;
    //list->size = 0;
    //create(&list);
    for(int i = 0; i < 9; i++){
        insert(&list, i);
    }
    print_list(list);
    //printf("%d\n",list->size);
    delete_odd(&list);
    print_list(list);
}