#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct{
    element *data;
    int size;
    int top;
}Stack;

void init_stack(Stack *s)
{
    s->size = 1;
    s->top =  - 1;
    s->data = (element *)malloc(sizeof(element) * s->size);
}
int is_empty(Stack *s){
    return(s->top == -1);
}
int is_full(Stack *s)
{
	return (s->top == s->size - 1);
}
void push(Stack *s, element item)
{
    if(is_full(s)){
        s->size *= 2;
        s->data = (element*)realloc(s->data, sizeof(element) * s->size);
    }
    s->data[++(s->top)] = item;
}

element pop(Stack *s)
{
    if(!is_empty(s)){
        return s->data[(s->top)--];
    }else
        printf("Empty Stack!!\n");
}

int main(void)
{
    Stack *s1, *s2;
    int num, siu;
    s1 = (Stack *)malloc(sizeof(Stack));
    s2 = (Stack *)malloc(sizeof(Stack));
    init_stack(s1);
    init_stack(s2);
    while (1)
    {
        printf("enque is 0, deque is 1\n");
        scanf("%d", &siu);
        if(siu == 1){
            if(!is_empty(s2)){
                num = pop(s2);
                printf("%d\n", num);
            }else{
                if(is_empty(s1)){
                    printf("Empty!!\n");
                }else{
                    while(!is_empty(s1)){
                        push(s2, pop(s1));
                    }
                    num = pop(s2);
                    printf("%d\n", num);
                }
            }
        }else if(siu == 0){
            printf("Input number: ");
            scanf("%d", &num);
            push(s1, num);
        }else{
            printf("end program!!");
            break;
        }
    }
    free(s1);
    free(s2);
    return 0;


}