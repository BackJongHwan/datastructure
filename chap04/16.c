#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_LEN 100
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element *data;		// data은 포인터로 정의된다. 
	int capacity;		// 현재 크기
	int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data =
			(element *)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "stack is emplty\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peak(StackType *s)
{
    return s->data[s->top];
}

void palindrome(char str[])
{
    int result = 0;
    //char ch;
    int length = strlen(str);
    StackType *s;
    s = (StackType*)malloc(sizeof(StackType));
    init_stack(s);
    for(int i = 0; i < length; i++){
        push(s, str[i]);
    }
    int i = 0;

    while(1){
        if(!is_empty(s)){
            if(str[i] != pop(s)){
                //printf("%c", pop(s));
                break;
            }
        i++;
        }else break;
    }

    if(i == length)
        result = 1;
    //printf("%d\n", i);

    if(result){
        printf("This is palindrome!\n");
    }else{
        printf("This is not palindrome!\n");
    }
    free(s);
}

int main()
{
    char str[MAX_LEN];
    printf("Input string: ");
    scanf("%s",str);
    palindrome(str);
}