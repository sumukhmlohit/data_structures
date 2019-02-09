/*Queue using 2 stacks*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int q,choice,s1[1000000],s2[10000333],a[10333000];
int top1=-1,top2=-1,i=0,top3=-1;

void enqueue(int x)
{ s1[++top1]=x;
  
    
}

void dequeue()
{   int min;
      if(top2!=-1)
      min=s2[top2--];
      else
      {  if(top1!=-1)
         {   while(top1!=-1)
             s2[++top2]=s1[top1--];
              min=s2[top2--];
         }
          
      }
    
}

void print()
{ if(top2!=-1)
  printf("%d\n",s2[top2]);
  else
  { if(top1!=-1)
    while(top1!=-1)
    { s2[++top2]=s1[top1--];
      
    }
      printf("%d\n",s2[top2]);
  }
    
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    
    
    scanf("%d",&q);
    do
    {
      scanf("%d",&choice);
      
         switch(choice)
         {    case 1:
              { int x;
                scanf("%d",&x);enqueue(x);
                break;
              }
              case 2:
              { dequeue();
                break;
              }
              case 3:
              { print();
                break;
              }
          
         }
        
        
      i++;  
    } while(i<q);
    
    
    
    
    return 0;
}
