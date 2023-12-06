#include<stdio.h>
#include<stdlib.h>

void insert(int c,int e);
void traverse();

struct Node
{
    int expo,coeff;
    struct Node *link;
}*header=NULL;

int main()
{
    int i=0,n,c,e;
    printf("Enter the number of terms in your expression: ");
    scanf("%d",&n);
    printf("Enter the polynomial terms: ");
    while(i<n)
    {
        printf("\nEnter the coefficent and exponent for term %d: ",i+1);
        scanf("%d%d",&c,&e);
        insert(c,e);
        ++i;
    }
    traverse();
}

void insert(int c,int e)
{
    struct Node*newnode,*temp1;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->coeff=c;
    newnode->expo=e;
    newnode->link=NULL;
    if(header==NULL)
        header=newnode;
    else
    {
        temp1=header;
        while(temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        temp1->link=newnode;
    }
}

void traverse()
{
    struct Node *temp;
    if(header==NULL)
    {
        printf("List is empty..\n");
        return;
    }
    printf("\nThe linked list:\n ");
    temp=header;
    while(temp!=NULL)
    {
        printf("%d,%d -> ",temp->coeff,temp->expo);
        temp=temp->link;
    }
    printf("NULL\n");
    printf("\nThe Polynomial:\n");
    temp=header;
    printf("%d x ^ %d ",temp->coeff,temp->expo);
    while(temp->link!=NULL)
    {
        temp=temp->link;
        if(temp->coeff>0)
            printf("+ ");
        printf("%d x ^ %d ",temp->coeff,temp->expo);
    }
}
