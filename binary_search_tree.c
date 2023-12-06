#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
}*root=NULL;

void insertion();
void preorder(struct Node *temp);
void inorder(struct Node *temp);
void postorder(struct Node *temp);
void search();
void deletion();

int main()
{
    int ch;
    printf("\t\tBinary Search Tree\n");
    while(1)
    {
        printf("\n\nMENU\n1. Preorder Traverse\n2. Inorder Traverse\n3. Postorder Traverse\n4. Insertion");
        printf("\n5. Deletion\n6. Search\n7. Exit");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: preorder(root);
                    break;
            case 2: inorder(root);
                    break;
            case 3: postorder(root);
                    break;
            case 4: insertion();
                    break;
            case 5: deletion();
                    break;
            case 6: search();
                    break;
            case 7: exit(0);
            default:printf("Wrong input!!");
        };
    }
}

void insertion()
{
    int ele;
    struct Node*newnode,*curr,*parnt;
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&ele);
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=ele;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
       curr=root;
       while(curr!=NULL)
       {
            parnt=curr;
            if(ele > curr->data)
                curr=curr->right;
            else
                curr=curr->left;
       }
        if(ele > parnt->data)
            parnt->right=newnode;
        else
            parnt->left=newnode;
    }
    printf("\nSuccessfully inserted");
}

void preorder(struct Node*temp)
{

    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
    else
        return;
}

void inorder(struct Node *temp)
{
    if(temp!=NULL)
   {
      inorder(temp->left);
      printf("%d ",temp->data);
      inorder(temp->right);
    }
    else
        return;
}

void postorder(struct Node *temp)
{
    if(temp!=NULL)
   {
      postorder(temp->left);
      postorder(temp->right);
      printf("%d ",temp->data);
    }
    else
        return;
}

void search()
{
    int ele,flag=0;
    struct Node*curr;
    printf("\nEnter the element to be searched: ");
    scanf("%d",&ele);
    curr=root;
	while(curr!=NULL)
	{
        if(curr->data==ele)
        {
            flag=1;
            break;
        }
        else if(ele>curr->data)
            curr=curr->right;
        else
            curr=curr->left;
	}
	if (flag==1)
        printf("Found");
    else
        printf("Not found");

}


void deletion()
{
  int ele,flag=0;
    struct Node*curr,*parnt;
    printf("\nEnter the element to be deleted: ");
    scanf("%d",&ele);
    curr=root;
	while(curr!=NULL)
	{
        if(curr->data==ele)
        {
            flag=1;
            break;
        }
        else
        {
            parnt=curr;
            if(ele>curr->data)
                curr=curr->right;
            else
                curr=curr->left;
        }

	}
	if (flag==0)
	{
        printf("Element not existing!!");
        return;
	}
	if(curr->left==NULL && curr->right==NULL)           //if leafnode
	{
        if(parnt==NULL)
        {
            free(curr);
            root=NULL;
        }
        else if(parnt->left==curr)
        {
            parnt->left=NULL;
            free(curr);
        }
        else if(parnt->right==curr)
        {
            parnt->right=NULL;
            free(curr);
        }
    }
    else if(curr->left==NULL &&curr->right!=NULL)       //if with one child in right
    {
        if(parnt==NULL)
        {
            root=root->right;
            free(curr);
        }
        else if(parnt->left==curr)
        {
            parnt->left=curr->right;
            free(curr);
        }
        else if(parnt->right==curr)
        {
            parnt->right=curr->right;
            free(curr);
        }
    }
    else if(curr->left!=NULL &&curr->right==NULL)       //if with one child in left
    {
        if(parnt==NULL)
        {
            root=root->left;
            free(curr);
        }
        else if(parnt->left==curr)
        {
            parnt->left=curr->left;
            free(curr);
        }
        else if(parnt->right==curr)
        {
            parnt->right=curr->left;
            free(curr);
        }
    }
    printf("Element deleted Successfully");
}
