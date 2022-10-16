/*Name-Anshuman Dangwal
Roll no-21044
Week 9
Lab-4
To input NxN integer matrix and print its inverse*/


#include<stdio.h>
#include<stdlib.h>

void readMatrix(int **arr, int a)//taking input
{
	printf("Enter elements of matrix\n");
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
		{
			printf("Enter %d,%d element of matrix:", i,j);
			scanf("%d", &arr[i][j]);
			}
		}
	}
	
	
void displayMatrix(int **arr, int a)//printing matrix
{
	printf("Displaying the matrix\n");
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
		}
	}
		
void subMatrix(int **arr, int **submat, int n, int r, int s)//removing rth row and sth column
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
			
int deter(int **arr, int n)//calculating determinant
{
	int det=0, cofac, **submat, sgn=1;
	
	 if(n==1)
		return arr[0][0];
	else if(n==2)
	{
		det=arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
		return det;
		}
	else
	{
		//declaring submat 	
		submat=(int**)malloc((n-1)*sizeof(int*));
		for(int i=0;i<n-1;i++)
		{
			submat[i]=(int*)malloc((n-1)*sizeof(int));
			}
	
			for(int j=0;j<n;j++)
			{
				//if else for sign of cofactor
				if(j%2==0)
					sgn=1;
				else
					sgn=-1;
				
				subMatrix(arr, submat, n, 1, j+1);//removing row and column
			
				cofac=sgn*deter(submat, n-1);//calculating cofactor;
			
				det=det+arr[0][j]*cofac;//calculating determinant
				}
		
		return det;
		}
	}
	
void inverse(float **inv, int **arr, int n)
{
	
	int cofac, **submat, sgn;
	
	
	submat=(int**)malloc((n-1)*sizeof(int*));
		for(int i=0;i<n-1;i++)
		{
			submat[i]=(int*)malloc((n-1)*sizeof(int));
			}	
				
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//if else for sign of cofactor
			if((i+j)%2==0)
				sgn=1;
			else
				sgn=-1;
				
				
			subMatrix(arr, submat, n, i+1, j+1);//removing row and column
			
			cofac=sgn*deter(submat, n-1);//calculating cofactor;
			
			inv[j][i]=cofac;
		}
	}	
	
	
}	
int main()
{
	int n,determinant=0, **mat;
	printf("Enter size of matrix\n");
	scanf("%d",&n);
	if(n==0)
	{
		printf("Error enter a valid value");
		return 0;}
		else
		{
		
	
	//declaring NxN matrix
	mat=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++)
	{
		mat[i]=(int*)malloc(n*sizeof(int));
		}
		
	readMatrix(mat, n);
	
	displayMatrix(mat, n);
	
	determinant=deter(mat, n);
	if(determinant==0)
	{
		printf("\nMatrix not invertible\n");
		return 0;
		}
	else
	{
		printf("\nDetermnant is:%d", determinant);
		
		
		float** inv;
		inv=(float**)malloc(n*sizeof(float*));
		for(int i=0;i<n;i++)
		{
			inv[i]=(float*)malloc(n*sizeof(float));
			}
			
			
		inverse(inv, mat, n);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				inv[i][j]=inv[i][j]/determinant;
				}
			}
	
		printf("\nInverse matrix is:\n");
				
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%f ", inv[i][j]);
			printf("\n");
			}
		
		//freeing the memory of matrix
		for(int i=0;i<n;i++)
		free(mat[i]);
		free(mat);
	
		return 0;
		}
	}
}
