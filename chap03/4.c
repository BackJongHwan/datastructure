#include<stdio.h>

int main()
{
    int two[10], i;
    int temp = 1;
    for(i = 0; i < 10; i++){
        two[i] = temp;
        temp *= 2;
    }

    for(i = 0; i < 9; i++){
        printf("%d " ,two[i]);
    }
    printf("%d", two[9]);
    printf("\n");
}