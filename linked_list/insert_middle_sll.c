/*Program to insert an element at the middle of Singly Linked List*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
int data;
struct node *link;
};
typedef struct node NODE;
NODE *newnode, *start=NULL, *currptr, *prevptr;

NODE *getnode(int value)
{
newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=value;
 newnode->link =NULL;
 return newnode;

}

void insert_beg()
{
 int value;
 printf("\n enter the value for the node:");
 scanf("%d", &value);
 newnode=getnode(value);
 if(start==NULL)
 {
 start=newnode;
 start->link=NULL;
 }
 else
 {
 currptr=start;
start=newnode;
 start->link=currptr;
 }
}

void insert_end()
{
 int value;
 printf("\n enter the value for the node:");
 scanf("%d", &value);
 newnode=getnode(value);
 if(start==NULL)
 {
 start=newnode;
 start->link=NULL;
 }
 else
 { currptr=start;
 while(currptr->link!=NULL)
 currptr=currptr->link;
 currptr->link=newnode;
 newnode->link=NULL;
 }
 printf("\n NODE INSERTED");
}

void insert_atposition(int pos)
{
 int value,count=0,i;
 
 currptr=start;
 while(currptr!=NULL)
 {
 currptr=currptr->link;
 count++;
 }
 if(pos==1)
 {
 insert_beg();
 }
 else
 if(pos>1&&pos<=count)
 {
 currptr=start;
 printf("\n enter the value for the middle node:");
 scanf("%d", &value);
 newnode=getnode(value);
 for(i=1;i<pos-1;i++)
 {
 currptr=currptr->link;
 }
 newnode->link=currptr->link;
currptr->link=newnode;
printf("\n NODE INSERTED");
}
else
printf("\n Position out of range");
}

void display()
{
if(start==NULL)
{
 printf("\nList Empty, No nodes to display");
 return;
}
else
{
 printf("\n The elements in the list are:");
 for(currptr=start;currptr!=NULL;currptr=currptr->link)
 printf("%d\t", currptr->data);
}
}


int main()
{
 int i,x,n;

 
  printf("Enter the number of nodes");
  scanf("%d",&n);  
  for(i=0;i<n;i++)
  insert_end();
  
  if(n%2==0)
  insert_atposition(n/2+1);
  else if(n==1||n==0)
  insert_end();
  else
  insert_atposition((n+1)/2+1);
  
  printf("The list after operations is");
  display();
return 0;
}
