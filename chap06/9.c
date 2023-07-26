#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node{
    element data;
    struct Node* link;
}NODE;

typedef struct ListType{
    NODE *head;
    NODE *tail;
    int size;
}LISTTYPE;

LISTTYPE* creat()
{
    LISTTYPE* temp = (LISTTYPE*)malloc(sizeof(LISTTYPE));
    temp->size = 0;
    temp->head = temp->tail = NULL;
    return temp;
}


LISTTYPE* insert_last(LISTTYPE *list, element data){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    if(list->head == NULL){
        list->head = list->tail = temp;
        //temp->link = NULL;
    }else{
        list->tail->link = temp;
        list->tail = temp;
        //temp->link = NU
    }
    temp->link = NULL;
    list->size++;
    return list;
}

void print_list(LISTTYPE *list){
    for(NODE*p = list->head; p != NULL; p = p->link){
        printf("%d-> ",p->data);
    }
    printf("\n");
}

element sum_data(LISTTYPE *list){
    NODE *p;
    element sum = 0;
    for(p = list->head; p != NULL; p = p->link){
        printf("%d\n", p->data);
        sum += p->data;
    }
    return sum;
}

void serch_data(LISTTYPE *list, element data){
    NODE *p = list->head;
    int i = 0;
    for(;p!=NULL; p = p->link)
    {
        i++;
        if(p->data == data){
            printf("%d는 연결리스트 %d에서 나타납니다.\n", data, i);
        }
    }
}


LISTTYPE* delete(LISTTYPE *list, NODE* node){
    NODE* pre = list->head;
    while(pre->link != node)
        pre = pre->link;
    pre->link->link = node;
    free(node);
    list->size--;
    return list;
}

void serch_delete(LISTTYPE *list, element data){
    NODE *p = list->head;
    int i = 0;
    for( ;p!=NULL; p = p->link)
    {
        if(p->data == data)
            list = delete(list, p);
    }
}

element max_data(LISTTYPE *list)
{
    element max = list->head->data;
    for(NODE *p = list->head; p != NULL; p = p->link){
        if(p->data > max){
            max = p->data;
        }
    }
    return max;
}
element min_data(LISTTYPE *list)
{
    element min = list->head->data;
    for(NODE *p = list->head; p != NULL; p = p->link){
        if(p->data < min){
            min = p->data;
        }
    }
    return min;
}

LISTTYPE* delete_odd(LISTTYPE *list){
    NODE* temp;
    for(NODE*p = list->head; p!= NULL ; p->link){
        temp = p;
    }
}
int main()
{
    LISTTYPE *list;
    int temp;
    int len;
    element max, min;
    list = creat();
    printf("노드의 개수: ");
    scanf("%d",&len);
    for(int i = 0; i < len; i++){
        printf("노드 #%d 데이터: ", i + 1);
        scanf("%d", &temp);
        list = insert_last(list, temp);
    }
    //print_list(list);
    //element sum = sum_data(list);
    //printf("sum is %d\n", sum);
    //serch_data(list, 5);
    //serch_delete(list, 5);
    print_list(list);
    // max = max_data(list);
    // min = min_data(list);
    // printf("max is %d, min is %d\n", max, min);
    list = delete_odd(list);
    print_list(list);
    free(list);
}