/*Name : Anshuman Dangwal
  Roll no : 21044
  date: 04/05/2022
  C program that will enter a line of text containing a word, a
phrase or a sentence, and determine whether or not the text is a
palindrome(ignoring white spaces).
*/

#include<stdio.h>
int main(){
	char ch[100],new[100];
	int i=0,k=0;
	int len,flag=0,sum=0;
	int d=0;
	printf("Enter your string: ");
	scanf("%[^\n]",ch);
	while (i==0){
		if(ch[d]==' '){
			d=d+1;
			sum=sum+1;}
		if (ch[d]=='\0')
			i=1;
		if((ch[d])!=' '){
			new[k]=ch[d];
			d=d+1;
			k=k+1;}}
	len=(d-1-sum);
	for(int j=0;j<(len-1);j++){
		if(new[j]!=new[len-j-1]){
			printf("not a palindrome\n");
			break;}
		else{
			flag=1;}}
	if (flag==1){
		printf("palindrome\n");}
	return 0;
	}