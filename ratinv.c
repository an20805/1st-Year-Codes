/*Name-Anshuman Dangwal
Roll no-21044
Week 10
Lab-4
To input NxN rational matrix and print its inverse*/


#include<stdio.h>
#include<stdlib.h>

typedef struct rat
{
	int num;
	int den;
	
}rat;

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
	
rat A( rat a,  rat b)
{
	rat add;
	 add.num=(a.num)*(b.den)+(a.den)*(b.num);
	 add.den=(a.den)*(b.den);
	
	if(add.num==0){
	 add.num=0;
	 add.den=1;
	 return add;
	 }
	 else{
	 int hcf=HCF(add.num,add.den);
	 add.num=add.num/hcf;
	 add.den=add.den/hcf;
	 
	  if(add.den<0)
	 {
	 	add.den=add.den*(-1);
	 	add.num=add.num*(-1);
	 	}
	
	return add;
	}
}

rat S( rat a,  rat b)
{
	rat sub;
	 sub.num=(a.num)*(b.den)-(a.den)*(b.num);
	 sub.den=(a.den)*(b.den);
	
	if(sub.num==0){
	 sub.num=0;
	 sub.den=1;
	 return sub;
	 }
	 else{
	 
	  int hcf=HCF(sub.num,sub.den);
	 sub.num=sub.num/hcf;
	 sub.den=sub.den/hcf;
	 
	  if(sub.den<0)
	 {
	 	sub.den=sub.den*(-1);
	 	sub.num=sub.num*(-1);
	 	}
	
	return sub;}
}	

rat M( rat a,  rat b)
{
	rat mul;
	 mul.num=(a.num)*(b.num);
	 mul.den=(a.den)*(b.den);
	
	if(mul.num==0){
	 mul.num=0;
	 mul.den=1;
	 return mul;
	 }
	 else{
	 int hcf=HCF(mul.num,mul.den);
	 mul.num=mul.num/hcf;
	 mul.den=mul.den/hcf;
	 
	 if(mul.den<0)
	 {
	 	mul.den=mul.den*(-1);
	 	mul.num=mul.num*(-1);
	 	}
	 
	return mul;}
}

rat D( rat a,  rat b)
{
	rat div;
	 div.num=(a.num)*(b.den);
	 div.den=(a.den)*(b.num);
	
	if(div.num==0){
	 div.num=0;
	 div.den=1;
	 return div;
	 }
	 else{
	 int hcf=HCF(div.num,div.den);
	 div.num=div.num/hcf;
	 div.den=div.den/hcf;
	 
	 if(div.den<0)
	 {
	 	div.den=div.den*(-1);
	 	div.num=div.num*(-1);
	 	}
	 
	return div;}
}
void readMatrix(rat **arr, int a)//taking input
{
	printf("Enter elements of matrix\n");
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			printf("Enter numerator of %d,%d element of matrix:", i,j);
			scanf("%d", &arr[i][j].num);
			printf("Enter denominator of %d,%d element of matrix:", i,j);
			scanf("%d", &arr[i][j].den);
			}
		}
	}
	
	
void displayMatrix(rat **arr, int a)//printing matrix
{
	printf("Displaying the matrix\n");
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++){
			printf("%d/%d ", arr[i][j].num, arr[i][j].den);
			}
		printf("\n");
		}
	}
		
void subMatrix(rat **arr, rat **submat, int n, int r, int s)//removing rth row and sth column
{

	for(int i=0, k=0;i<n;i++)
	{
		for(int j=0, m=0;j<n;j++)
		{
			if(i==(r-1) || j==(s-1))
				continue;
			else
			{
				submat[k][m]=arr[i][j];
				m++;
				}
			}
		if(i!=(r-1))
			k++;
		}

	}
			
rat deter(rat **arr, int n)//calculating determinant
{
	 rat det={0,1}, cofac,sgn;
	struct rat **submat;
	
	 if(n==1)
	 {
		det.num=arr[0][0].num;
		det.den=arr[0][0].den;
		return det;
		}
	else if(n==2)
	{
		det=S(M(arr[0][0],arr[1][1]),M(arr[0][1],arr[1][0]));
		return det;
		}
	else
	{
		//declaring submat 	
		submat=(struct rat **)malloc((n-1)*sizeof(struct rat *));
		for(int i=0;i<n-1;i++)
		{
			submat[i]=(struct rat *)malloc((n-1)*sizeof(struct rat));
			}
	
			for(int j=0;j<n;j++)
			{
				//if else for sign of cofactor
				if(j%2==0){
					sgn.num=1;
					sgn.den=1;}
				else{
					sgn.num=-1;
					sgn.den=1;}
				
				subMatrix(arr, submat, n, 1, j+1);//removing row and column
			
				cofac=M(sgn,deter(submat, n-1));//calculating cofactor;
			
				det=A(det,M(arr[0][j],cofac));//calculating determinant
				}
		
		return det;
		}
	}
	
void inverse(rat **inv, rat **arr, int n)
{
	
	rat cofac, **submat, sgn;
	
	
	submat=(rat**)malloc((n-1)*sizeof(rat*));
		for(int i=0;i<n-1;i++)
		{
			submat[i]=(rat*)malloc((n-1)*sizeof(rat));
			}	
					
	for(int i=0;i<n;i++)

	{
		for(int j=0;j<n;j++)
		{
			//if else for sign of cofactor
			if((i+j)%2==0)
				{
					sgn.num=1;
					sgn.den=1;}
			else
				{
					sgn.num=-1;
					sgn.den=1;}
				
				
			subMatrix(arr, submat, n, i+1, j+1);//removing row and column
			
			cofac=M(sgn,deter(submat, n-1));//calculating cofactor;
			
			inv[j][i]=cofac;
		}
	}	
	
	
}	
int main()
{
	int n;
	rat determinant;
	rat **mat;
	printf("Enter size of matrix\n");
	scanf("%d",&n);
	if(n==0)
	{
		printf("Error enter a valid value");
		return 0;}
		else
		{
		
	
	//declaring NxN matrix
	mat=(rat **)malloc(n*sizeof(rat *));
	for(int i=0;i<n;i++)
	{
		mat[i]=(rat *)malloc(n*sizeof(rat));
		}
		
	readMatrix(mat, n);
	
	displayMatrix(mat, n);
	
	determinant=deter(mat, n);
		
	if(determinant.num==0)
	{
		printf("\nMatrix not invertible\n");
		return 0;
		}
	else
	{
		printf("\nDetermnant is:%d/%d", determinant.num, determinant.den);
		
		
		rat** inv;
		inv=(rat**)malloc(n*sizeof(rat*));
		for(int i=0;i<n;i++)
		{
			inv[i]=(rat*)malloc(n*sizeof(rat));
			}
			
			
		inverse(inv, mat, n);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				inv[i][j]=D(inv[i][j],determinant);
				}
			}
	
		printf("\nInverse matrix\n");
				
		displayMatrix(inv, n);
		
		//freeing the memory of matrix
		for(int i=0;i<n;i++)
		free(mat[i]);
		free(mat);
	
		return 0;
		}
	}
}
