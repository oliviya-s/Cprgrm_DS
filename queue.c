#include<stdio.h>
#include<stdlib.h>
#define max 5

int queue[10],rear=-1,front=-1;
void enqueu();
void dequeu();
void display();

void enqueue()
{
   int n;
   if(rear==max-1)
   {
     printf("OVERFLOW");
   }
   else
   {
      if(rear=-1,front=-1)
      {
         front=0;
      }
    rear=rear+1;
    queue[rear]=n;
   }
}
void dequeue()
{
    int n;
    if(front==-1)
    {
       printf("UNDERFLOW");
    }
    else
    {
       n=queue[front];
       if(front=rear)
       {
           rear=-1;
           front=-1;
       }
       else
       {
         printf("%d is deleted",n);
         front=front+1;

       }
    }
}
void display()
{
     int i;
     if(rear=-1)
     {
       printf("empty queue");
     }
     else
     {
        printf("queue is: ");
        for(i=front;i<=rear;i++)
        {
           printf("%d",queue[i]);
        }
      }
}
void main()
{
   int choice,n;
   do
   {
     printf("\n 1.enqueue");
     printf("\n 2.dequeue");
     printf("\n 3.display");
     printf("\n 4.exit");
     printf("\n enter your choice: ");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:
        printf("insert element: ",n);
        scanf("%d",&n);
        enqueue(n);
        break;
       case 2:
        dequeue();
        break;
       case 3:
        display();
        break;
       case 4:
        exit(0);
       default:
        printf("wrong choice\n");
     }
   }
   while(1);
   return(0);
}

