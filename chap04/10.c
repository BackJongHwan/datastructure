#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct 
{
    element *data;
    int size;
    int top;
}Stack;

void init_stack(Stack *s)
{
    s->top = -1;
    s->size = 1;
    s->data = (element *)malloc(sizeof(element) * s->size);
}

int is_full(Stack *s)
{
    return (s->size == s->top + 1);
}

int is_empty(Stack *s)
{
    return (s->top == - 1);
}

void push(Stack *s, element data)
{
    if(is_full(s)){
        s->size *= 2;
        s->data = (element*)realloc(s->data,sizeof(element) * s->size);
    }
    s->data[++(s->top)] = data;
}

element pop(Stack *s)
{
    if(is_empty(s)){
        printf("Stack is empty!!\n");
        return 0;
    }else{
        return (s->data[(s->top)--]);
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 4,5,6 };
    Stack *a;
    a = (Stack*)malloc(sizeof(Stack));
    init_stack(a);
    for(int i = 0; i < 6; i++){
        push(a, arr[i]);
    }
    for(int i = 0; i < 6; i++){
        printf("%d, ", pop(a));
    }
}
