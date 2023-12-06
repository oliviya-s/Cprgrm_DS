#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;
void push();
void pop();
void Display();
int main()
{
    int ch;
    printf("\t\tSTACK IMPLEMENTATION USING LINKED LIST \n");
    printf("\t________________________________________________________");
    while(1)
    {
        printf("\n\t\t Menu");

        printf("\n\t---------------------");

        printf(" \n\t1.PUSH\n");

        printf("\t2.POP\n");

        printf("\t3.Display\n");

        printf("\t4.Exit");

        printf("\n\nEnter your choice : ");

        scanf("%d",&ch);

        switch(ch)
        {
            case 1:

                push();
                 break;

            case 2:

               pop();
                break;

            case 3:

              Display();
               break;

            case 4:

              exit(0);

            default:printf("Wrong statment......");
              break;

        }
    }
}

void push()
{
    int item;
    struct node *temp,*newnode;
    printf("Element to be inserted :");
    scanf("%d",&item);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = top;
    top = newnode;
}
void Display()
{
    struct node *temp;
    temp=top;
    if (temp==NULL)
    {
        printf("The stack is Empty!!!!!");
    }
    else
    {
        while(temp!=NULL)
    {
        printf("%d ->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
    }

}


void pop()
{
    struct node *temp;
    temp = top;
    if (top==NULL)
    {
        printf("The stack is Empty  !!!");
    }
    else
    {
        printf("The poped element is %d",top->data);
        top = temp->link;
        free(temp);
    }
}
