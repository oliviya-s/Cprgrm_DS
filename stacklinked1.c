#include<stdio.h>
#include<stdio.h>
struct node
{
   int data;
   struct node*link;

};
struct node*top=NULL;
void push();
void pop();
void display();
int main()
{
  int ch;
  while(1)
  {
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    printf("enter your choice: ");
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
          display();
          break;
      case 4:
           exit(0);

       default:printf("wrong statement");
    }
  }
}
void push()
{
   int item;
   struct node*temp,*newnode;
   printf("element to be inserted: ");
   scanf("%d",&item);
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=item;
   newnode->link=top;
   top=newnode;
}
void display()
{
   struct node*temp;
   temp=top;
   if(temp==NULL)
   {
      printf("stack is empty");

   }
   else
   {
      while(temp!=NULL)
      {
        printf("%d->",temp->data);
        temp=temp->link;
      }
      printf("NULL\n");
   }
}
void pop()
{
  struct node*temp;
  temp=top;
  if(top==NULL)
  {
    printf("the stack is empty");

  }
  else
  {
     printf("thr poped element is %d",top->data);
     top=temp->link;
     free(temp);
  }
}

