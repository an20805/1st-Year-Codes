
/*Anshuman Dangwal
21044
Week 11
Program to compute determinant of NxN matrix of rational numbers with arbitrary precision length of numerator and denominator*/

#include<stdio.h> 
#include <stdlib.h>

typedef struct{ //structure for numerator/denominator of a rational number(arbitrary precision Integer)
	int sign;
	char *digits;
	int last_ind;
}Integer;

int no_digit(char a[]){
	int i;
	for(i=0; a[i]!='\0'; i++);
	return i;}

char * remove_zero(char *a){
	char *b;
	int n=no_digit(a);
	int i;
	for(i=0; i<n ;i++){
		if(a[i]!='0'){
			i--;
			break;}}
	b=(char *)calloc((n-i+2),(sizeof(char)));
	if(n!=i){
	for(int j=0; j<n-i; j++){
		b[j]=a[j+i+1];}}
	if(n==i){
		b[0]='0'; b[1]=='\0';}
	return b;
	}
	
Integer readint(){ //taking input
	char a[100];
	scanf("%s",a);
	
	Integer x;
	
	if(a[0]=='-'){
		x.sign=-1;}
	else{
		x.sign=1;}
	
	char b[100];
	if(a[0]=='-'){
		for(int i=0; i<no_digit(a); i++){
			b[i]=a[i+1];}}	
	else{
		for(int i=0; i<=no_digit(a); i++){
			b[i]=a[i];}}
	
	x.last_ind=no_digit(b)-1;
	x.digits=(char *)calloc((x.last_ind+1),sizeof(char));
	for(int i=0; i<=x.last_ind; i++){
		x.digits[i]=b[i];}
	return x;
	}

void printint(Integer a)
{

	if(a.sign==-1) 
		putchar('-');
	
	for(int i=0;i<=a.last_ind;i++)
		putchar(a.digits[i]);
	
	
}

void free_memory(Integer *a)
{
	free(a->digits);
}

int larger_number(char a[], char b[]){
	int a1=no_digit(a); int a2=no_digit(b);
	if(a1>a2){
		return 1;}
	if(a2>a1){
		return 0;}
	if(a1==a2){
		int i=0;
		while(a[i]==b[i] && a[i]!='\0'){
			i++;}
		if(a[i]=='\0'){
			return 1;}
		if(a[i]>b[i]){
			return 1;}
		else{
			return 0;}}
	}
	
int compare(Integer s1, Integer s2)
{
	int n1 = s1.last_ind+1, n2 = s2.last_ind+1; 

  	 if (n1 > n2) 
     	   return 0; 

   	 if (n2 > n1) 
       	 return 1; 

  

  	  for (int i = 0; i < n1; i++) 
   	 { 
      	  if (s1.digits[i] < s2.digits[i]) 
       	     return 1; 
	
     	   else if (s1.digits[i] > s2.digits[i]) 
		    return 0; 
   		 } 

   	 return -1; 
}


Integer un_A(Integer s1, Integer s2) //function to add 
{ 
	Integer sum1;
	sum1.sign=1;
	sum1.digits=(char *)calloc(100,sizeof(char));
	

	int num1[100], num2[100], sum[100]; 
	
	int l1, l2; 
 
	// converting character to integer
 
	for (l1 = 0; s1.digits[l1] != '\0'; l1++) 
	num1[l1] = s1.digits[l1] - '0'; 
 
	for (l2 = 0; s2.digits[l2] != '\0'; l2++) 
	num2[l2] = s2.digits[l2] - '0'; 
 
	int carry = 0; 
	int k = 0; 
	int i = l1 - 1; 
	int j = l2 - 1; 
	
	for (; i >= 0 && j >= 0; i--, j--, k++) { 
		sum[k] = (num1[i] + num2[j] + carry) % 10; 
		carry = (num1[i] + num2[j] + carry) / 10; 
	} 
	
	if (l1 > l2) { 
 
		while (i >= 0) { 
		sum[k] = (num1[i] + carry) % 10; 
		carry = (num1[i] + carry) / 10; 
		k++,i--;
	} 
 
	}
	 else if (l1 < l2) { 
		while (j >= 0) { 
			sum[k] = (num2[j] + carry) % 10; 
			carry = (num2[j] + carry) / 10; 
			k++,j--;
		} 
	} 
	else { 
		if (carry > 0) 
		sum[k++] = carry; 
	} 
 
 	int l=k, o=k, *pl;
 	sum1.last_ind=l-1;
	pl=&l;
	char s[*pl];
	char * ss;

	 for(int m=0;m<l;m++)
		s[m]=(sum[--o]+48);
		
	ss=remove_zero(s);
	sum1.digits=ss;
	
	for(int i=0;i<=sum1.last_ind;i++)
		if(sum1.digits[i]<'0' || sum1.digits[i]>'9'){
			l=i;
			break;}
		
	
	sum1.digits[l]='\0';
	sum1.last_ind=l-1;
	return sum1; 
} 



Integer un_S(Integer s1, Integer s2) //function to (unsigned) subtract 
{ 
	Integer dif;
	dif.sign=1;
	size_t size=1000;
	dif.digits=(char *)calloc(100,sizeof(char));
	
	char str1[100], str2[100], str[100];
	int n1,n2;
	
	 if(compare(s1,s2)==1) 
    	 { 
		 for(int m=0;m<=s2.last_ind;m++)
       			str1[m]=s2.digits[m];
       			
       		n1=s2.last_ind+1;
       		
		 for(int m=0;m<=s1.last_ind;m++)
	  		 str2[m]=s1.digits[m];
	  		 
	  	 n2=s1.last_ind+1;
   		 }
	else
	{
		 for(int m=0;m<=s1.last_ind;m++)
			str1[m]=s1.digits[m];
			
       		n1=s1.last_ind+1;
       				
		 for(int m=0;m<=s2.last_ind;m++)
		 	str2[m]=s2.digits[m];
		
       		n2=s2.last_ind+1;
		}
	
   	 int diff = n1 - n2, carry=0, j=0;

  	for (int i = n2 - 1; i >= 0; i--) 
   	 { 

       	 int sub = ((str1[i + diff]) -  (str2[i] ) - carry); 


       	 if (sub < 0) 
       	 { 
          	  sub = sub+10; 
          	  carry = 1; 
       		} 

       	 else
         	carry = 0; 
       		 str[j++]= (sub+48); 
   	 } 
   	 
   	 
   	 for (int i = n1 - n2 - 1; i >= 0; i--) 
  	 { 
     	   if (str1[i] == '0' && carry > 0) 

         	  { 
        	       str[j++]='9'; 
       	      	       continue; 
     	   	  } 

      	 int sub = ((str1[i] -48) - carry); 

       	 if (i > 0 || sub > 0) // remove preceding 0's 
           {
         	 str[j++]=(sub+48);}

        carry = 0; 

   	 } 
   	 
   	
   	
   	int nzi=-1;
   	
   	 for(int l=j;l>=0;l--)
   	 if(str[l]>'0' && str[l]<='9'){
   	 	nzi=l;
   	 	break;}
   	 	
   	 	
   	 if(nzi!=-1){
   	 for( int k=nzi, m=0;k>=0;k--,m++){
   	 	dif.digits[m]=str[k];
   	 }
   	 	dif.last_ind=nzi;
   	 }
   	 else{
   	 dif.digits[0]='0';
   	 dif.last_ind=0;
   	 }
	return dif;
}

char * append(char a[], char b){
	int a1=no_digit(a);
	char * new;
	new= (char *)calloc((a1+2),sizeof(char));
	for(int i=0; i<=a1+1; i++){
		if(i<a1)
			new[i]=a[i];
		if(i==a1)
			new[i]=b;
		if(i==a1+1)
			new[i]='\0';	
		}
	return new;
}
		
char * subtract(char *str1, char *str2){//function to subtract 
	int a=no_digit(str1);
	int b=no_digit(str2);
	
	char *num3; char *num4;
	
	num3=(char *)calloc((a+2),sizeof(char));
	num3[a+1]='\0';
	char num1[a+1],num2[a+1];
	
	num1[a]='\0';
	num2[a]='\0';
	int i=0;
	
	while(i<a){
		num1[a-1-i]=(char)(str1[a-1-i]);
		if(i<b){
			num2[a-1-i]=(char)(str2[b-1-i]);}
		else{
			num2[a-1-i]=(char)(48);}
		i+=1;	
		}
	int alpha,carry=0;
	for(int j=0; j<a; j++){
		if ((num1[a-1-j]-carry)>=num2[a-1-j]){
			alpha=num1[a-1-j]-carry-num2[a-1-j]+48;
			num3[a-j]=(char)(alpha);
			carry=0;}
		if ((num1[a-1-j]-carry)<num2[a-1-j]){
			alpha=num1[a-1-j]-carry+10-num2[a-1-j]+48;
			num3[a-j]=(char)(alpha);
			carry=1;}
		}
	num3[0]=(char)(48);
	num4=remove_zero(num3);
	
	free(num3);
	
	return num4;
	}
	
char * multiply(char a[],char b[]){         //function to multiply 
	int a1,b1,alpha,beta,carry=0;
	a1=no_digit(a);
	b1=no_digit(b);
	
	char arr[b1][a1+b1];
	int min=b1;
	
	for(int i=0; i<b1; i++){
		int max=a1;
		for(int j=0; j<a1+b1; j++){
			if(j<i){
				arr[i][a1+b1-1-j]=(char)(48);
				carry=0;
				continue;}
			if(j>=i && max-1>=0){
				alpha=(a[max-1]-48)*(b[min-1]-48)+carry;
				if(alpha>9){
					beta=alpha%10;
					carry=alpha/10;
					arr[i][a1+b1-1-j]=(char)(beta+48);
					}
				if(alpha<=9){
					carry=0;
					arr[i][a1+b1-1-j]=(char)(alpha+48);
					}
					}
					
			if(max-1<0){
				arr[i][a1+b1-1-j]=(char)(carry+48);
				carry=0;
				}
				
			max=max-1;
			}
		min=min-1;
		}
	/*column addition*/
	int carry2=0,ans;
	char *answer; char *ranswer;
	
	answer = (char *)calloc((a1+b1+1),sizeof(char));
	answer[a1+b1]='\0';
	
	for(int x=0; x<a1+b1; x++){
		int var=0;
		for(int y=0; y<b1; y++){
			var=(arr[y][a1+b1-1-x]-48)+var;
			}
		var=var+carry2;
		ans=var%10;
		carry2=var/10;
		answer[a1+b1-1-x]=(char)(ans+48);
		}
	ranswer=remove_zero(answer);
	
	free(answer);
	return ranswer;
	}
	
char * division(char a[], char b[]){//function to divide 
	char * answer;
	if(larger_number(a,b)==0){
		answer=(char *)calloc(2,sizeof(char));
		answer[0]='0'; answer[1]='\0';}
	else{
		int a1,a2,a3,j=0;
		a1=no_digit(a);
		a2=no_digit(b);
		char * quotient; char * work; char * worker;
		
		quotient=(char *)calloc((a1+1),sizeof(char));
		answer= (char *)calloc((a1+1),sizeof(char));
		worker=(char *)calloc((a2+1),sizeof(char));
		work=(char *)calloc((a2+1),sizeof(char));
		
		for(int i=0; i<a2; i++){
			work[i]=a[i];}
			
		char mul[2]; mul[1]='\0'; char new;
		
		while(a[a2+j-1]!='\0'){
			for(int i=9;i>=0;i--)
			{
				mul[0]=(char)(i+48);
				worker=multiply(b,mul);
				
				if(larger_number(work,worker)==1){
					quotient[j]=mul[0];
					new= a[a2+j];
					work=append(subtract(work,worker),new);
					work=remove_zero(work);
					j++;	
					break;
					}
					}
				}
		quotient[j]='\0';
		answer=remove_zero(quotient);
		free(quotient); free(work); free(worker);
		
		}
		
	return answer;
	}
	
	
Integer A(Integer a, Integer b){//function to add two arbitrary precise integers(signed)
	Integer c,d;
	d.digits=(char *) calloc(100,sizeof(char));
	
	if(a.sign ==1 && b.sign == 1){
		if(a.last_ind >= b.last_ind){
			c=un_A(a,b);
			c.sign=1;}
		else{
			c=un_A(b,a);
			c.sign=1;}
			}
	if(a.sign ==-1 && b.sign ==-1){
		if(a.last_ind >= b.last_ind){
			c=un_A(a,b);
			c.sign=-1;}
		else{
			c=un_A(b,a);
			c.sign=-1;}
			}
	if(a.sign==1 && b.sign==-1){
		if(compare(a,b)==0){
			c=un_S(a,b);
			c.sign=1;}
		else{
			c=un_S(b,a);
			c.sign=-1;}
			}
	if(a.sign==-1 && b.sign==1){
		if(compare(a,b)==0){
			c=un_S(a,b);
			c.sign=-1;}
		else{
			c=un_S(b,a);
			c.sign=1;}
			}
	c.last_ind=no_digit(c.digits)-1;
	
	return c;
}
		
Integer S(Integer a, Integer b)//function to subtract two arbitrary precise integers(signed)
{
	
	Integer d;
	d.digits=(char *) calloc(100,sizeof(char));
	if(compare(a,b)==-1)
	{
		if(a.sign*b.sign==1){
		d.sign=1;
		d.digits[0]='0';
		d.last_ind=0;}
		
		else if(a.sign==1)
		{
			d=un_A(a,b);
			d.sign=1;
			}
		else
		{
			d=un_A(a,b);
			d.sign=-1;
			}
		}
	else if(compare(a,b)==0){
		
		if(a.sign==1 && b.sign==1)
		{
			d=un_S(a,b);
			d.sign=1;
		}	
		if(a.sign==1 && b.sign==-1)
		{
			d=un_A(a,b);
			d.sign=1;
		}	
		if(a.sign==-1 && b.sign==1)
		{
			d=un_A(a,b);
			d.sign=-1;
		}	
		if(a.sign==-1 && b.sign==-1)
		{
			d=un_S(a,b);
			d.sign=-1;
		}	
	}
	else{
		
		if(b.sign==1 && a.sign==1)
		{
			d=un_S(a,b);
			d.sign=-1;
		}	
		if(b.sign==1 && a.sign==-1)
		{
			d=un_A(a,b);
			d.sign=-1;
		}	
		if(b.sign==-1 && a.sign==1)
		{
			d=un_A(a,b);
			d.sign=1;
		}	
		if(b.sign==-1 && a.sign==-1)
		{
			d=un_S(a,b);
			d.sign=1;
		}	
	}
	return d;	
	}
	
Integer M(Integer a, Integer b){//function to multiply two arbitrary precise integers(signed)
	Integer c;
	if(a.sign*b.sign==1){
		c.sign=1;}
	if(a.sign*b.sign==-1){
		c.sign=-1;}
	c.digits=multiply(a.digits,b.digits);
	c.last_ind=no_digit(c.digits)-1;
	return c;
	}
	
Integer Q(Integer a, Integer b){//function to find quotient of two arbitrary precise integers
	
	Integer d;
	d.digits=(char *) calloc(100,sizeof(char));
	

	if(a.sign*b.sign==1){
		d.sign=1;
		d.digits=division(a.digits,b.digits);
		d.last_ind=no_digit(d.digits)-1;
		}
		
	if(a.sign*b.sign==-1){
		d.sign=-1;
		d.digits=division(a.digits,b.digits);
		d.last_ind=no_digit(d.digits)-1;}
		
		
	return d;	
	
}
	
Integer R(Integer a, Integer b)//function to find remainder of two arbitrary precise integers when one is divided by the other
{
	Integer r;
	r.sign=1;
	a.sign=1;
	b.sign=1;
	r.digits=(char *) calloc(100,sizeof(char));
	
	r=S(a,M(b,Q(a,b)));
	return r;
}	

Integer HCF(Integer num1, Integer num2)//function to find HCF of two arbitrary precise integers
{	
	Integer divisor,divident,num3;
	
	num1.sign=1;
	num2.sign=2;
	
		if (compare(num1,num2)==0)
			{
				divisor=num2 ;
				divident=num1;
						}
		else
			{
				divisor=num1;
				divident=num2;
						}
		while (R(divident,divisor).digits[0]!='0')
			{  
				num3=R(divident,divisor);
				divident=divisor;
				divisor=num3;
							}
	
	return divisor;
	}
	
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

typedef struct ratint{ //structure for rational number of arbitrary precise numerator/denominator
	int sgn;
	Integer num;
	Integer den;
	}ratint;
	
ratint normalize(ratint a)
{
	Integer hcf;
	hcf=HCF(a.num, a.den);
	a.num=Q(a.num, hcf);
	a.den=Q(a.den, hcf);
	return a;
	}

ratint readrat(){

	ratint num1;
	Integer a,b;
	a=readint();
	b=readint();
	
	if(a.sign*b.sign==1)
		num1.sgn=1;
		
	if(a.sign*b.sign==-1)
		num1.sgn=-1;
		
	b.digits=remove_zero(b.digits);
	if(b.digits[0]=='0'){
		printf("Denominator cannot be zero!\n");
		exit(1);}
	num1.num=a;
	num1.den=b;
	if(R(num1.num,num1.den).digits[0]=='0'){
		
		num1.num=Q(num1.num,num1.den);
		num1.den=Q(num1.den,num1.den);
		
	}
	else
		num1=normalize(num1);
		
	return num1;
	} 
	
void printrat(ratint a)
{
	if(a.sgn==-1)
		printf("-");
	
	printf("%s/%s",a.num.digits,a.den.digits);
	}	
		
ratint ratA(ratint a, ratint b)
{
	ratint sum;
	sum.num=A(M(a.num,b.den),M(b.num,a.den));
	sum.den=M(a.den,b.den);
	
	if(R(sum.num,sum.den).digits[0]=='0'){
		
		sum.num=Q(sum.num,sum.den);
		sum.den=Q(sum.den,sum.den);
		
	}
	else{
	sum=normalize(sum);
	
	if((sum.num.sign*sum.den.sign)==-1)
		sum.sgn=-1;
	else
		sum.sgn=1;
	}
	return sum;
	}
	
ratint ratS(ratint a, ratint b)
{
	ratint diff;
	diff.num=S(M(a.num,b.den),M(b.num,a.den));
	diff.den=M(a.den,b.den);
	if(R(diff.num,diff.den).digits[0]=='0'){
		
		diff.num=Q(diff.num,diff.den);
		diff.den=Q(diff.den,diff.den);
		
	}
	else{
	diff=normalize(diff);
	
	if((diff.num.sign*diff.den.sign)==-1)
		diff.sgn=-1;
	else
		diff.sgn=1;
	}
	return diff;
	}

ratint ratM(ratint a, ratint b)
{
	ratint mul;
	mul.num=M(a.num,b.num);
	mul.den=M(a.den,b.den);
	
	if(R(mul.num,mul.den).digits[0]=='0'){
		
		mul.num=Q(mul.num,mul.den);
		mul.den=Q(mul.den,mul.den);
		
	}
	else{
	mul=normalize(mul);
	
	if((mul.num.sign*mul.den.sign)==-1)
		mul.sgn=-1;
	else
		mul.sgn=1;
	}
	return mul;
	}
		
ratint ratD(ratint a, ratint b)
{
	ratint div;
	div.num=M(a.num,b.den);
	div.den=M(a.den,b.num);
	
	if(R(div.num,div.den).digits[0]=='0'){
		
		div.num=Q(div.num,div.den);
		div.den=Q(div.den,div.den);
		
	}
	else{
	div=normalize(div);
	
	if((div.num.sign*div.den.sign)==-1)
		div.sgn=-1;
	else
		div.sgn=1;
	}
	return div;
	}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


ratint ** readmat(int n){
	ratint ** mat;
	mat= (ratint **)calloc(n,sizeof(ratint *));
	for(int i=0; i<n; i++){
		mat[i]= (ratint *)calloc(n,sizeof(ratint));
		}
	ratint a;	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("Enter the %d,%d element:\n",i+1,j+1);
			a=readrat();
			mat[i][j]=a;}}
			
	return mat;}
	
void printmat(ratint ** arr , int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printrat(arr[i][j]);
			printf("\t");
			}
		printf("\n");
		}
	}

void free_matrix(ratint ** matrix, int n)
{

	for(int i=0; i<n; i++){
			free(matrix[i]);}
		free(matrix);
		
		}
		

void subMatrix(ratint **arr, ratint **submat, int n, int r, int s)//removing rth row and sth column
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

ratint deter(ratint **arr,int n)//calculating determinant
{
	 ratint det;
	struct ratint **submat;
	
	det.sgn=1;
	det.num.digits=(char *)calloc(3,sizeof(char));
	det.den.digits=(char *)calloc(3,sizeof(char));
	det.num.digits[0]='0';
	det.num.digits[1]='\0';
	det.num.sign=1;
	det.den.digits[0]='1';
	det.den.digits[1]='\0';
	det.den.sign=1;
	
	 if(n==1)
	 {
		det.num=arr[0][0].num;
		det.den=arr[0][0].den;
		return det;
		}
	else if(n==2)
	{
		det=ratS(ratM(arr[0][0],arr[1][1]),ratM(arr[0][1],arr[1][0]));
		return det;
		}
	else
	{
		//declaring submat 	
		submat=(struct ratint **)calloc((n-1),sizeof(struct ratint *));
		for(int i=0;i<n-1;i++)
		{
			submat[i]=(struct ratint *)calloc((n-1),sizeof(struct ratint));
			}
	
			for(int j=0;j<n;j++)
			{
				
				subMatrix(arr, submat, n, 1, j+1);//removing row and column
				//printmat(submat,n-1);
				if(j%2==0)
					det=ratA(det,ratM(arr[0][j],deter(submat, n-1)));//calculating determinant
																	
				else					
					det=ratS(det,ratM(arr[0][j],deter(submat, n-1)));//calculating determinant
					
								
					}				
						
				}
		return det;		
	}

int main()
{
	ratint a;
	
	int n;
	printf("Enter the number of rows/column: ");
	scanf("%d",&n);
	ratint ** mat; 
	mat=readmat(n);
	
	
	printf("\n");
	printf("*****************************************\n");
	printmat(mat,n);
	printf("*****************************************\n");
	printf("\n");
	
	printf("The determinant of the matrix is:\n");
	a=deter(mat,n);
	printrat(a);
	
	return 0;
			
}	
	




	







