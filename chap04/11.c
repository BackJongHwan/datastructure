#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char data;
    int num;
}element;

typedef struct 
{
    element *data;
    int size;
    int top;
}Stack;

void init_stack(Stack *s)
{
    s->size = 1;
    s->top = -1;
    s->data = (element *)malloc(sizeof(element) * s->size);
}

int is_full(Stack *s)
{
    return (s->size == s->top + 1);
}

int is_empty(Stack *s)
{
    return (s->top == -1);
}

void push(Stack *s, element data)
{
    if(is_full(s)){
        s->size *= 2;
        s->data = (element *)realloc(s->data,sizeof(element) * s->size);
    }
    s->data[++(s->top)] = data;
}

element pop(Stack *s)
{
    if(is_empty(s)){
        printf("Stakc is empty!!\n");
        exit(1);
    }else{
        return s->data[s->top--];
    }
}

void paren(char str[])
{
    int i;
    element element1; 
    int len = strlen(str), num = 0;
    Stack *s = (Stack*)malloc(sizeof(Stack));
    init_stack(s);
    for(i = 0; i < len; i++){
        if(str[i] == '('){
            element1.data = '(';
            element1.num = ++num;
            push(s, element1);
            printf("%d ", element1.num);
        }
        else{
            element1 = pop(s);
            printf("%d ", element1.num);
        }
    }
    free(s);
}

int main()
{
    char str[100];
    scanf("%s", str);
    paren(str);
}