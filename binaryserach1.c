#include<stdio.h>
void bsearch(int[],int,int);

void main()

{
  int n,x,i;
  printf("enter size of array");
  scanf("%d",&n);
  int a[n];
  printf("enter elements:");
  for (i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }
  printf("enter value to be searched: ");
  scanf("%d",&x);
  bsearch(a,n,x);
}

void bsearch( int a[],int n,int x)
{
  int mid,l,d;
  mid=(l+d)/2;
  l=0;
  d=n-1;
  mid=(l+d)/2;
  while(l<+d)
  {
     if(a[mid]>x)
     {
         d=mid;
         mid=(l+d)/2;


     }
     else if (a[mid]==x)
     {
        printf(" %d found at %d location",x,mid+1);
     }
     else
     {
        l=mid+1;
        mid=(l+d)/2;
     }

  }
  if(l>d)
  {
     printf("element not found");
     return 0;
  }
}
