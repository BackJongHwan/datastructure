#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int num;
    char str[20];
}Data;


int main()
{
    Data* a = (Data*)malloc(sizeof(Data));
    a->num = 100;
    strcpy(a->str, "just testing");
    printf("%d, %s\n", a->num, a->str);
    free(a);

}
