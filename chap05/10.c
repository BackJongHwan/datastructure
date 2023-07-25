#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef int element;
typedef struct 
{
    element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
}Queue;

void init_fibonacci(Queue *q)
{
    q->front = 0;
    q->rear = 2;
    q->data[1] = 0;
    q->data[2] = 1;
}

int is_empty(Queue *q){
    return (q->front == q->rear);
}

int is_full(Queue *q){
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

void print_queue(Queue *q)
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if(!is_empty(q)) {
			int i = q->front;
			do {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%d | ", q->data[i]);
				if (i == q->rear)
					break;
			}while (i != q->front);
		}
	printf("\n");
}

void enqueue(Queue *q, element item)
{
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Queue *q)
{
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(Queue *q)
{
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_rear(Queue *q){
    return(q->data[q->rear]);
}

int main()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    init_fibonacci(q);
    int num;
    scanf("%d" ,&num);
    for(int i = 0; i < num; i++){
        enqueue(q, dequeue(q) + get_rear(q));
        print_queue(q);
    }
    return 0;
}
