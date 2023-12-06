#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int enqueue(int*,int*,int);
int dequeue(int*,int*,int);

void status(int,int);
void main()
{
    int Que[MAX],front=-1,rear=-1,ch;
    int*q=Que;

    while(1)
    {
        printf("\nMenu\n1. ENQUEUE\n2. DEQUEUE\n3. STATUS\n4. EXIT\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: rear=enqueue(q,&front,rear);
                    break;
            case 2: rear=dequeue(q,&front,rear);
                    break;
            case 3: status(front,rear);
                    break;
            case 4: exit(0);
            default: printf("Wrong input");
                    break;
        };
    }
}


int enqueue(int*qu,int*fr,int re)
{
    int item,i;
    if(re==MAX-1)
    {
        printf("Queue is full");
        return re;
    }
    if (*fr==-1)
    {
        *fr=0;
    }
    printf("Enter the element: ");
    scanf("%d",&item);
    re++;
    *(qu+re)=item;
    printf("Enqueued Sucessfully");
    printf("\nCurrent Queue:\t");
    for (i=*fr;i<=re;++i)
        printf ("%d ",*(qu+i));
    return re;
}

int dequeue(int*qu,int*fr,int re)
{
    int item,i;
    if(*fr==-1)
    {
        printf("Queue is Empty");
        return re;
    }
    else
    {

        item=*(qu+*fr);
        printf("%d is Dequeued",item);
        for(i=0;i<re;i++)
        {
            *(qu+i)= *(qu+i+1);
        }
        re=re-1;
        printf("\nCurrent Queue:\t");
        if(re==-1)
        {
            *fr=-1;
            printf("Empty");
        }
        else
        {
            for (i=*fr;i<=re;++i)
                printf ("%d ",*(qu+i));
        }
        return re;
    }
}

void status(int fr,int re)
{
    if(fr==-1||fr==MAX-1)
        printf("Queue is Empty");
    else if(re==MAX-1)
        printf("Queue is Full");
    else
        printf("Free Space = %d",MAX-re-1);
}
