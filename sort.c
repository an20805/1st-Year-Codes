#include <stdio.h>
#include <stdlib.h>
// Sorting of a n-sized integer array

int main() {
   int n, *arr, temp;
   printf("Enter the number of element:\n");
   scanf("%d",&n);
   
   arr=(int*)malloc(n*sizeof(int));
   
   printf("\nEnter the numbers\n");
   for(int i=0;i<n;i++)
   scanf("%d",(arr+i));
   
   for(int i=0;i<n-1;i++)
   {
       for(int j=0;j<n-1-i;j++)
       {
           if(arr[j+1]>arr[j])
           {
               temp=arr[j+1];
               arr[j+1]=arr[j];
               arr[j]=temp;
           }
       }
   }
   printf("\nArray after sorting.");
    
   for(int i=0;i<n;i++)
   printf("\n%d",arr[i]);
    
    
    return 0;
}