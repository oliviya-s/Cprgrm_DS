#include <stdio.h>
#include<stdlib.h>
#define MAX 10
void enqueue();
void dequeue();
void status();
int ar[MAX], rear = - 1, front = - 1;
void main()
{
    int choice;
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
    while (1)
    {
        printf("\n1.enqueue \n2.dequeue \n3.status \n4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                status();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice \n");
        }
    }

}
void enqueue()
{
    int x;
    if(rear==MAX-1)
    printf("Queue Overflow \n");
    else
    {
        if(front==-1)
        front=0;
        printf("Inset the element in queue : ");
        scanf("%d", &x);
        rear=rear+1;
        ar[rear] = x;
    }
}
void dequeue()
{
    if(front== - 1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("Element Deleted from queue is : %d", ar[front]);
        front = front + 1;
    }
}
void status()
{
    if(front == - 1)
    printf("Queue is empty \n");
    else
    {
        printf("Queue is : ");
        for(int i = front; i <= rear; i++)
        printf("%d ", ar[i]);
    }
}
