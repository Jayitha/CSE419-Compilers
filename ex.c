#include<stdio.h>
#include<stdbool.h>

union data{
    int a;
    char b;
    bool c;
}x;

int main(void)
{
    x.b = 'a';
    printf("%d",x.c);  
}