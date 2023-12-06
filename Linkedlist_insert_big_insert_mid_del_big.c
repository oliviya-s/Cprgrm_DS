#include <stdio.h>
#include<stdlib.h>
void insertatbegin();
void insertatpos();
void deleteatbegin();


struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()
{
        int choice;
        while(1){



                printf("\n 1.Insert at front  \n");
                printf("\n 2.Insert at a position   \n");
                printf("\n 3.Delete at front   \n");
                printf("\n 4.Exit       \n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        insertatbegin();
                                        break;
                        case 2:
                                        insertatpos();
                                        break;
                        case 3:
                                        deleteatbegin();
                                        break;

                        case 4:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n It is a Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}

void insertatbegin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\n Memory is Out of Space:>\n");
                return;
        }
        printf("\nEnter value for the node:\t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insertatpos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\n Memory Out of Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the value for the node:\t");
        scanf("%d",&temp->info) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\n The Position not is found:\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void deleteatbegin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\n Sorry the List is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is :%d\t",ptr->info);
                free(ptr);
        }
}
