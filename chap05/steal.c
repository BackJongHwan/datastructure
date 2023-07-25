#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//implement Deque
#define MAX_QUEUE_SIZE 20
typedef int element;

typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}Deque;

void init_deque(Deque *q);
int is_full(Deque *q);
int is_empty(Deque *q);
void add_rear(Deque*q, element item);
void add_front(Deque*q, element item);
element get_rear(Deque*q);
element delete_rear(Deque*q);
element get_front(Deque *q);
element delete_front(Deque*q);
void print_deque(Deque *q);

void init_deque(Deque *q){
    q->front = q->rear = 0;
}
int is_full(Deque *q){
    return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}
int is_empty(Deque *q){
    return (q->front == q->rear);
}
void add_rear(Deque*q, element item)
{
    if(!is_full(q)){
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}
void add_front(Deque*q, element item)
{
    if(!is_full(q)){
        q->front = (q->front - 1 + MAX_QUEUE_SIZE)  % MAX_QUEUE_SIZE;
        q->data[q->front] = item;
    }
}
element get_rear(Deque*q){
    if(!is_empty(q)){
        return q->data[q->rear];
    }
}
element delete_rear(Deque*q){
    if(!is_empty(q)){
        int temp = q->rear;
        q->rear = (q->rear  - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        return q->data[temp];
    }
}
element get_front(Deque *q){
    if(!is_empty(q)){
        return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    }
}
element delete_front(Deque*q){
    if(!is_empty(q)){
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}
void print_deque(Deque *q){
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int main()
{
    Deque *q[2];
    int total_job = 0;
    for(int i = 0; i < 2; i++){
        q[i] = (Deque*)malloc(sizeof(Deque));
        init_deque(q[i]);
    }

    for(int i = 0; i < 10; i++){
        add_rear(q[0], i);
        total_job++;
        if(i % 8 == 1){
            add_rear(q[1], i);
            total_job++;
        }
    }
    //print_deque(q[0]);
    //print_deque(q[1]);
    while(1){
        if(rand() % 10 < 5){
            if(!is_empty(q[0])){
                delete_front(q[0]);
                total_job--;
            }else{
                if(!is_empty(q[1])){
                    add_rear(q[0], delete_rear(q[1]));
                    delete_front(q[0]);
                    total_job--;
                }
            }
            if(total_job == 0)
            break;
        }
        if(rand() % 10 < 2){
            if(!is_empty(q[1])){
                delete_front(q[1]);
                total_job--;
            }else{
                if(!is_empty(q[0])){
                    add_rear(q[1], delete_rear(q[0]));
                    delete_front(q[1]);
                    total_job--;
                }
            }
            if(total_job == 0)
            break;
        }
        printf("cpu1: ");
        print_deque(q[0]);
        printf("cpu2: ");
        print_deque(q[1]);
    }

    for(int i = 0; i < 2; i++){
        free(q[i]);
    }

}