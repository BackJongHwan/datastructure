#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node{
    element data;
    struct Node *pre;
    struct Node *next;
}Node;

void init(Node *head){
    head->next = head;
    head->pre = head;
}

void insert_next(Node *before, element data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = before->next;
    new_node->pre = before;
    before->next->pre = new_node;
    before->next = new_node;
}

void print_left(Node *head){
    if(head->pre == head){
        printf("It is empty!\n");
    }else{
        Node *p = head;
        do{
            p = p->pre;
            printf("%d, ", p->data);
        }while(p->pre != head);
    }
    printf("\n");
}

Node *serch(Node *head, element data){
    if(head->next == head){
        printf("It is empty list!\n");
        return 0;
    }else{
        Node *p = head;
        do{
            p = p->next;
            if(p->data == data){
                printf("found!!\n");
                return p;
            }
        }while(p->next != head);

        printf("Not found in list!!\n");
        return 0;
    }
}

int main()
{
    int num;
    int temp;
    Node *head = (Node*)malloc(sizeof(Node));
    init(head);
    Node *p = head;
    printf("데이터의 갯수를 입력하세요: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        printf("노드 #%d의 데이터를 입력하세요: ", i + 1);
        scanf("%d", &temp);
        insert_next(p, temp);
        p = p->next;
    }
    print_left(head);
    Node *ser = serch(head, 4);
}