#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isBalanced(char* s) {
int length= strlen(s);
int stack[length],top=-1;
char temp;
  for(int i=0;i<length;i++)
  {
     
    if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
         stack[++top] = s[i];
        }
    if(s[i]==')' || s[i]=='}' || s[i]==']')
    {
            temp=stack[top--];
        if((s[i]==')'&&temp!='(')||(s[i]=='}'&&temp!='{')||(s[i]==']'&&temp!='['))
             return 0;   
           
        }
  }
    if(top>=0)
    return 0;
    
    else
    return 1;     

}

void main()
{  char str[20]; int result;
   printf("Enter a string\n");
   gets(str);
   result=isBalanced(str);
   if(result==1)
   printf("Balanced brackets string");
   else
   printf("Not a balanced brackets string");
}
