/*Doubly ended queue*/

#include<stdio.h>
#include<ctype.h>
#define SIZE 10

int queue[SIZE], front=-1, rear=-1;

void insert_rear(int queue[], int item)
{
    if(rear==-1)
    {
      front=rear=0;
      queue[rear]=item;
     }
    else if(rear==SIZE-1)
   {
      printf("\n Queue is full\n");
      return;
    }
    else
   {
      rear++;
      queue[rear]=item;
    }
}

void insert_front(int q[],int item)
{ if(front==0&&rear==-1)
  q[++rear]=item;
      
  else if(front!=0)
  q[--front]=item;
  else
  printf("Front insertion not possible");
}

void delete_rear(int q[])
{ if(rear==-1)
  printf("Queue underflow\n");
  printf("Deleted element is %d",q[rear--]);
  if(front>rear)
  { front=0;
    rear=-1;  
  }
    
}

void delete_front(int queue[])
{
    int item;
    if(front==-1)
    {
       printf("\nQueue is empty\n");
       return;
     }
    else if(front==rear)
    {
       item=queue[front];
       printf("\n The element removed is %d\n", item);
       front=rear=-1;
     }
     else
     {
        item=queue[front];
        printf("\n The element removed is %d\n", item);
        front++;
      }
}

void display(int queue[])
{
     int i;
     if(rear==-1)
    {
        printf("\nQueue is empty\n");
        return;
     }
    for(i=front;i<=rear;i++)
    {
        printf("%d\n", queue[i]);
     }
}

int main()
{
    int item, choice;
    while(1)
    {
       printf("\nEnter choice: 1: Insert, 2: Display, 3: Remove,4:Insert front,5:Delete_rear,6: Exit");
       scanf("%d", &choice);

       switch(choice)
       {
          case 1:
          printf("\n Enter item:");
          scanf("%d", &item);
          insert_rear(queue, item);
          break;
         case 2: display(queue);
         break;
         case 3:
         delete_front(queue);
         break;
         case 4:
          printf("\n Enter item:");
          scanf("%d", &item);
         insert_front(queue,item);
         break;
         case 5:
         delete_rear(queue);
         break;
         case 6: exit(0);
         break;
         default:
         printf("Invalid choice");
         break;
      }//end of switch
    }//end of while
return(0);
}
