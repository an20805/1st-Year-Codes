#include <stdio.h>
#include <stdlib.h>
//function that swaps two integers

void sort(int *pa, int *pb)
{
    *pa=*pa+*pb;
    *pb=*pa-*pb;
    *pa=*pa-*pb;
}

int main() {
 int a, b;
 printf("Enter first number\n");
 scanf("%d",&a);
 printf("Enter second number\n");
 scanf("%d",&b);
 
 
 sort(&a,&b)   ;
 printf("Enter first number after swapping %d\n",a);
 printf("Enter second number after swapping %d\n",b);
    
    return 0;
}