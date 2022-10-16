/*Anshuman Dangwal(21044)
lab 4
10 may 2022
C code (function) that takes an argument as character
(0-9) and convert it into an integer value.
*/
#include<stdio.h>
int chartoint(char ch)
{
	char a;
	a=ch-48;
	return (int)a;
}
int main()
{
	printf("Enter a numerical character-");
	char c;
	scanf(" %c", &c);
	int b=(chartoint(c));
	printf("Interger value-%d", b);

	printf("\nEnter a number-");
	int n,count=0,m;
	scanf("%d",&n);
	
	m=n;
	while(m!=0)
	{	
		++count;
		m/=10;
	}
	char str[100];
	printf("%d\n",count);
	int t=(count-1),l=n,d;
	
	while(l!=0)
	{
		d=l%10;
		str[t]=(char)(d+48);

		t--;
		l=l/10;
	}

	printf("%s",str);
	return 0;
}