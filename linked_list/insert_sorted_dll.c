/*Inserting into a sorted Doubly linked list*/

#include <stdio.h>

#include<stdlib.h>


struct node

{ int data;
 
  struct node*next;
 
  struct node*prev;

};

typedef struct node Node;

Node*head=NULL;

Node *getnode(int value)
{ Node *Newnode;
  
  Newnode=(Node*)malloc(sizeof(Node));
 
  if(Newnode==NULL)
  
{ printf("Memory not allocated");
  
  return 0;  
 
}
 
else
  
{ Newnode->data=value;
 
  Newnode->next=NULL;
   
  Newnode->prev=NULL;
   
  return Newnode;
 
 }
   

}


void display()

{ Node *currptr=head;
  
  if(head==NULL)
 
 { printf("Empty list");
    
 }
  
 else

 { printf("Elements in list are:");
   
   for(currptr=head;currptr!=NULL;currptr=currptr->next)
  
   printf("%d ",currptr->data);  
 
 }
    

}


void sortedInsert(int data)

{  Node* currptr=head;
   
 
   Node* Newnode=getnode(data);
  
   if(head==NULL)
 
  {  
head=Newnode;
    
   
  }
 

   else if(Newnode->data<=head->data)
 
  { Newnode->next=head;
     
    Newnode->next->prev=Newnode;
  
    head=Newnode;
  
  }
 
   
   else
  
  { while(currptr->next&&Newnode->data>currptr->next->data)
   
    currptr=currptr->next;

    
    Newnode->next=currptr->next;
       
 
    if(currptr->next)
     
    Newnode->next->prev=Newnode;

    
    currptr->next=Newnode;
      
   Newnode->prev=currptr;
  
  }



}




void main()

{ int choice,value;
 
  printf("Enter 1 to insert and 2 to display");
 
  do
  
{ scanf("%d",&choice);
   
  switch(choice)
   
 { case 1:
   
   {printf("Enter element to be inserted");
   
    scanf("%d",&value);
    
    sortedInsert(value);
  
    break;
    
  }
     
 case 2:
     
 {display();
  
  break;
      
  }
     
 case 3:
      
 exit(0);
   
 }  
 fflush(stdin);
  
}
while(choice!=3);
   
 
}
