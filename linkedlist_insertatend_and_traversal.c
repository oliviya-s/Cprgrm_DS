#include<stdio.h>
#include<stdlib.h>

void insert();
void traverse();

struct Node
{
    int data;
    struct Node *link;
}*header=NULL;

int main()
{
    int ch;
   while(1)
   {
       printf("MENU\n1. Insert\n2. Traverse\n3. Exit");
       printf("\nEnter the choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1: insert();
                    break;
            case 2: traverse();
                    break;
            case 3: exit(0);
            default:printf("Wrong input!!");
       };
   }
}

void insert()
{
    int ele;
    struct Node*newnode,*temp1;
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&ele);
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data = ele;
    newnode->link = NULL;
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
    temp=header;
    if(header==NULL)
        printf("List is empty..");
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
}
