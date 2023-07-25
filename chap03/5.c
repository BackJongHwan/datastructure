#include<stdio.h>
#define MAX_LEN 100
typedef struct 
{
    char name[MAX_LEN];
    int age;
    float salary;
}person;

typedef struct Complex
{
    float real;
    float imaginary;
}Complex;

Complex complex_add(Complex a, Complex b)
{
    Complex temp;
    temp.real = a.real + b.real;
    temp.imaginary = a.imaginary + b.imaginary;

    return temp;
}

int main(){

    //Complex c1, c2;
    Complex c1 = {3.0, 4.0};
    Complex c2 = {5.0, 4.0};
    Complex c3 = complex_add(c1, c2);
    printf("%f %f\n", c1.real, c1.imaginary);
    printf("%f %f\n", c2.real, c2.imaginary);
    printf("%f %f\n", c3.real, c3.imaginary);
    return 0;
}