/* name-Anshuman Dangwal
   rollno-21044
   date-04/05/22
   lab-4
   project- sinple calculator
*/
 
#include<stdio.h>
int main()
{
        char operator;
        float num1 , num2 , result = 0;
        printf("\n enter any one operator like +,-,*,/:");
        scanf("%c" , &operator);
        printf("enter the value of operands num1 and num2 \n:");
        scanf("%f%f" , &num1 , &num2);
        switch(operator){
            case '+' : result = num1 + num2;
                break;
            case '-' : result = num1 - num2;
                break;
            case '*' : result = num1 * num2;
                break;
            case '/' : result = num1 / num2;
                break;
            default : printf("\n invalid operator"); 
         }
        printf("the value = %f" , result);
        return 0;
}