#include<stdio.h>
#include<stdlib.h>

struct Node 
{ 
    int data; 
    struct Node *link; 
}; 
struct Node *last=NULL;  
// To create a new node of circular 
// linked list 
struct Node *newNode(int info) 
{ 
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
   temp->link = temp; 
   temp->data = info;
   return temp; 
} 
  
/* Function to find the only person left after one in every m-th node is killed in a circle of n nodes */
void getJosephusPosition(int m, int n) 
{ 
    // Create a circular linked list of size n. 
    
     
    for (int i = 1; i <= n; i++) 
    {  struct Node *newnode=newNode(i);
        if(i==1)
        { last=newnode;
          last->link=last;
            
        }
        else
        { newnode->link=last->link;
          last->link=newnode;
          last=newnode;
            
        }
    
    } 
     
    struct Node *ptr1 = last->link, *ptr2 = last->link; 
    while (ptr1->link != ptr1) 
    { 
        // Find m-th node 
        int count = 1; 
        while (count != m) 
        { 
            ptr2 = ptr1; 
            ptr1 = ptr1->link; 
            count++; 
        } 
  
        /* Remove the m-th node */
        ptr2->link = ptr1->link; 
        ptr1 = ptr2->link; 
    } 
  
    printf ("Last person left standing "
            "(Josephus Position) is %d\n ", 
            ptr1->data); 
} 
  
/* Main function */
int main() 
{ 
    int n,m ; 
    printf("Enter length of circle\n");scanf("%d",&n);
    printf("Enter the position to choose from");scanf("%d",&m);
    getJosephusPosition(m, n); 
    return 0; 
} 