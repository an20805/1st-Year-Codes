/*Anshuman Dangwal
21044
Lab 4
making data type rational and performing arithmatic operations*/

#include<stdio.h>

struct rat
{
	int num;
	int den;
	
};

int HCF(int num1, int num2)
{
	int divisor,divident,num3;
		if (num1>num2)
			{
				divisor=num2 ;
				divident=num1;
						}
		else
			{
				divisor=num1;
				divident=num2;
						}
		while ((divident%divisor)!=0)
			{  
				num3=divident%divisor;
				divident=divisor;
				divisor=num3;
							}
	return divisor;
	}

	
void add(struct rat a, struct rat b)
{
	int n,d,s;
	 n=(a.num)*(b.den)+(a.den)*(b.num);
	 d=(a.den)*(b.den);
	
	 if(n==0)
	 printf("\nAddition:0/1");
	 else{
	 int hcf=HCF(n,d);
	 n=n/hcf;
	 d=d/hcf;
	 
	  if(d<0)
	 {
	 	d=d*(-1);
	 	n=n*(-1);
	 	}
	
	printf("\nAddition:%d/%d:",n,d);
	}
}

void sub(struct rat a, struct rat b)
{
	int n,d,s;
	 n=(a.num)*(b.den)-(a.den)*(b.num);
	 d=(a.den)*(b.den);
	
	 if(n==0)
	 printf("\nSubtraction:0/1");
	 else{
	 
	  int hcf=HCF(n,d);
	 n=n/hcf;
	 d=d/hcf;
	 
	  if(d<0)
	 {
	 	d=d*(-1);
	 	n=n*(-1);
	 	}
	
	printf("\nSubraction:%d/%d:",n,d);}
}	

void mul(struct rat a, struct rat b)
{
	int n,d,s;
	 n=(a.num)*(b.num);
	 d=(a.den)*(b.den);
	
	if(n==0)
	 printf("\nMultiplication:0/1");
	 else{
	 int hcf=HCF(n,d);
	 n=n/hcf;
	 d=d/hcf;
	 
	 if(d<0)
	 {
	 	d=d*(-1);
	 	n=n*(-1);
	 	}
	 
	printf("\nMultiplication:%d/%d:",n,d);}
}

void div(struct rat a, struct rat b)
{
	int n,d,s;
	 n=(a.num)*(b.den);
	 d=(a.den)*(b.num);
	
	if(n==0)
	 printf("\nDivision:0/1");
	 else{
	 int hcf=HCF(n,d);
	 n=n/hcf;
	 d=d/hcf;
	 
	  if(d<0)
	 {
	 	d=d*(-1);
	 	n=n*(-1);
	 	}
	 
	printf("\nDivision:%d/%d:",n,d);}
}

int main()
{
	struct rat num1;
	struct rat num2;
	
	printf("Enter numerator of num1:");
	scanf("%d",&num1.num);	
	printf("Enter denomenator of num1:");
	scanf("%d",&num1.den);
	if(num1.den==0)
	{
		printf("\nDenominator cannot be zero");
		return 0;}
	
	printf("Enter numerator of num2:");
	scanf("%d",&num2.num);
	printf("Enter denomenator of num2:");
	scanf("%d",&num2.den);
	if(num1.den==0)
	{
		printf("\nDenominator cannot be zero");
		return 0;}
	
	add(num1,num2);
	sub(num1,num2);
	mul(num1,num2);
	div(num1,num2);
	return 0;

}