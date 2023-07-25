#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUEUE_SIZE 30
#define MAX_LEN 100
typedef char element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Deque;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_dqueue(Deque *q)
{
    q->front = 0;
    q->rear = 0;
}

int is_empty(Deque *q){
    return (q->front == q->rear);
}

int is_full(Deque *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//출력함수
void print_queue(Deque *q)
{
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("%c |", q->data[i]);
            if(i == q->rear)
                break;
        }while(i != q->front);
    }
    printf("\n");
}
//큐 구현
//front 삭제하면서 얻기
element delete_front(Deque *q)
{
    if(!is_empty(q)){
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}
//front 삭제하지 않고 얻기
element get_front(Deque *q)
{
      if(!is_empty(q)){
        int temp = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[temp];
    }
}
//front에 삽입
void add_front(Deque *q, element item)
{
    if(!is_full(q)){
        q->data[q->front] = item;
        q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
}

void add_rear(Deque*q, element item)
{
    if(!is_full(q)){
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element get_rear(Deque *q)
{
    if(!is_empty(q)){
        return q->data[q->rear];
    }
}

element delete_rear(Deque *q)
{
  if(!is_empty(q)){
    int temp = q->rear;
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[temp];
    }
}

void is_palindrome(char *str)
{
    Deque *q;
    q = (Deque*)malloc(sizeof(Deque));
    init_dqueue(q);
    int len = strlen(str);
    //printf("%d\n", len);
    int palin_len = 0;
    int check = 0;
    for(int i = 0; i < len; i++){
        if( 65 <= str[i] && str[i]<= 90){
            add_rear(q, str[i]);
            palin_len++;
        }
        else if(97<= str[i]  && str[i] <= 122){
            add_rear(q, str[i] - 32);
            palin_len++;
        }
    }
    //print_queue(q);
    // if(palin_len % 2 == 1){
    //     for(int i = 0; i < palin_len / 2; i++)
    // }
    // else{
        for(int i = 0; i < palin_len / 2; i++){
            if(!(get_front(q) == get_rear(q))){
                printf("This is not palindrome\n");
                check = 1;
                break;
            }
        }
    //}
    if(check == 0){
        printf("This is palindrome\n");
    }
    free(q);
}

int main()
{
    char string[MAX_LEN];
    printf("Input string: ");
    scanf("%s", string);
    is_palindrome(string);
    return 0;
}
