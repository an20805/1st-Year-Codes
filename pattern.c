/*Name: Anshuman Dangwal
Roll Number: 21044
Date: 5 May 2022
program that prints a triangular pattern*/

#include<stdio.h>

int main()
{
	int i,j,k,l,m,n;
	
	for(i=1;i<=10;i++)
	{
		for(j=9;j>=i;j--)
		printf(" ");

		for(k=i;k<i+i;k++)
		{
			if(k<10)
			printf("%d", k);

			else{
			m=k-10;
			printf("%d", m);}		
		}
		for(l=i+i-2;l>=i;l--)
		{
			if(l<10)
			printf("%d", l);

			else{
			n=l-10;
			printf("%d", n);}
		}
		printf("\n");
	}
}