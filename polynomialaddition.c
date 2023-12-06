#include<stdio.h>
#include<stdlib.h>

void insert(int,int,int);
void add();
void traverse();

struct Node
{
    int expo,coeff;
    struct Node *link;
}*header1=NULL,*header2=NULL,*result=NULL;

int main()
{
    int i=0,y=0,n,p,expon;
    while(y<2)
    {
        printf("Expression %d:\n",y+1);
        printf("Enter the terms for the  expression: ");
        scanf("%d",&n);
        printf("Enter the polynomial terms: ");
        while(i<n)
        {
            printf("\nEnter the coefficent and exponent for term %d: ",i+1);
            scanf("%d%d",&p,&expon);
            insert(p,expon,y);
            ++i;
        }
        i=0;
        ++y;
    }
    add();
    traverse();
}

void insert(int p,int expon,int a)
{
    struct Node*newnode,*temp1,*header;
    if(a==0)
        header=header1;
    else if(a==1)
        header=header2;

    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->coeff=p;
    newnode->expo=expon;
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
    if(a==0)
        header1=header;
    else if(a==1)
        header2=header;
}

void add()
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 	temp->link = NULL;
 	result = temp;
 	while(header1 && header2)
 	{
 		if(header1->expo > header2->expo)
 		{
 			temp->coeff = header1->coeff;
 			temp->expo = header1->expo;
 			header1 = header1->link;
 		}
 		else if(header1->expo < header2->expo)
 		{
 			temp->coeff = header2->coeff;
 			temp->expo = header2->expo;
 			header2 = header2->link;
 		}
 		else
 		{
 			temp->coeff = header1->coeff + header2->coeff;
 			temp->expo = header1->expo;
 			header1 = header1->link;
 			header2 = header2->link;
 		}

 		if(header1 && header2)
 		{
 			temp->link = (struct Node*)malloc(sizeof(struct Node));
 			temp = temp->link;
 			temp->link = NULL;
 		}
 	}
 	while(header1 || header2)
 	{
 		temp->link = (struct Node*)malloc(sizeof(struct Node));
 		temp = temp->link;
 		temp->link = NULL;

 		if(header1)
 		{
 			temp->coeff = header1->coeff;
 			temp->expo = header1->expo;
 			header1 = header1->link;
 		}
 		else if(header2)
 		{
 			temp->coeff = header2->coeff;
 			temp->expo = header2->expo;
 			header2 = header2->link;
 		}
 	}
}

void traverse()
{
    struct Node *temp;
    if(result==NULL)
    {
        printf("List is empty..\n");
        return;
    }
    printf("\nThe linked list:\n ");
    temp=result;
    while(temp!=NULL)
    {
        printf("%d,%d -> ",temp->coeff,temp->expo);
        temp=temp->link;
    }
    printf("NULL\n");
    printf("\nThe Polynomial:\n");
    temp=result;
    printf("%d y ^ %d ",temp->coeff,temp->expo);
    while(temp->link!=NULL)
    {
        temp=temp->link;
        if(temp->coeff>0)
            printf("+ ");
        printf("%d y ^ %d ",temp->coeff,temp->expo);
    }
}
