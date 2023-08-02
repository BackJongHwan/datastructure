#include<stdio.h>
#define MAX_SIZE 20

typedef struct Sorted_list
{
    int data[MAX_SIZE];
    int len;

}Sorted_list;

void add(Sorted_list *list,int item){
    int i = 0;
    while(list->data[i] < item && i < list->len){
        i++;
    }
}

void delete(Sorted_list *list,int item){
    
}

void clear(Sorted_list *list,int item){
    list->len = 0;
}

int is_in_list(Sorted_list *list,int item){
    for(int i = 0; i < list->len; i++){
        if(list->data[i] == item)
            return 1;
    }
    return 0;
}

int get_length(Sorted_list *list){
    return list->len;
}

int is_empty(Sorted_list *list){
    return(list->len == 0);    
}

int is_full(Sorted_list *list){
    return(list->len == MAX_SIZE);
}

void display(Sorted_list *list){
    for(int i = 0; i <list->len; i++)
        printf("%d->", list->data[i]);
    printf("NULL\n");
}

int main()
{
    Sorted_list list;
    list.len = 0;
}