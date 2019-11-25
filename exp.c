#include <stdio.h>
#include <stdbool.h>
union type1{
    int a;
    char b;
}x, y;

void main(){
    x.b = 'a';
    y.a = 1;
    if(x.a <= y.a)
        printf("1");
    else
        printf("0");
}