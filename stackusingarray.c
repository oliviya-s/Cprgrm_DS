#include<stdio.h>
#define max(5)

int top=-1,a[max];
void push(int n)
{
    if(top==max-1)
    {
        printf("STACK OVERFLOW");
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
        printf("STACK UNDERFLOW");
        return;
    }
    else
    {
        del=a[top];
        top--;
        printf("deleted element is:%d",del);
    }
}
void status()
{
    int r;
        printf("current top element is:%d",a[top]);
        if((max-1)==top)
        printf("no more free space");
        else
        r=(max-1)-top;
        printf("total free spaces is :%d",r);
}
int main()
{
    int choice,n;
    do
    {
        printf("\n1.push\n2.pop\n3.status\n4.exit");
        printf("\n enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
              case 1:
                  printf("enter element to push: ");
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
