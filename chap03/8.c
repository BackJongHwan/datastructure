#include<stdio.h>

#define items 11
void insert(int arr[], int locate, int value)
{
    for(int i = items - 1; i > locate; i--){
        arr[i] = arr[i - 1];
    }
    arr[locate] = value;
}

void delete(int arr[], int locate)
{
    arr[locate] = arr[locate + 1];
    for(int i = locate; i < items - 1; i++){
        arr[i] = arr[i + 1];
    }
}


int main()
{
    int arr[items];
    for(int i = 0; i < 10; i++){
        arr[i] = i + 1;
    }  
    for(int i = 0; i < 11; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
    insert(arr, 6, 100);
    for(int i = 0; i < 11; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
    delete(arr, 4);
     for(int i = 0; i < 11; i++){
        printf("%d, ", arr[i]);
    }
}