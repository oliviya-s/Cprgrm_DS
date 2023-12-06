#include<stdio.h>
#include<stdlib.h>
#define max 10
int top=-1,a[max];
void push(int n)
{
    if(top==max-1)
    {
        printf("Stack Overflow");
        return;
    }
    else
    {
        top++;
        a[top]=n;
    }
}
void pop()
{
    int del;
    if(top==-1)
    {
        printf("Stack Underflow");
        return;
    }
    else
    {
        del=a[top];
        top--;
        printf("Deleted element is:%d",del);
    }
}
void status()
{
    int r;
     printf("Current Top element is:%d",a[top]);
     if((max-1)==top)
     printf("No more free space available");
     else
     r=(max-1)-top;
     printf("Total free spcae is:%d",r);
}
int main()
{
    int choice,n;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Status\n4.Exit");
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
             printf("Enter the elements to push:");
             scanf("%d",&n);
             push(n);
             break;
            case 2:
             pop();
             break;
            case 3:
             status();
             break;
            case 4:
             exit(0);
             break;
        }
    }
    while(1);
    return(0);
}
