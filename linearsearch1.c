#include<stdio.h>
void main()
{
  int a[10];
  int i=0,loc=-1,n,e;
  printf("enter the size");
  scanf("%d",&n);
  printf("enter the array");
  while(i<n)
  {
    scanf("%d",&a[i]);
    i++;

  }
  printf("enter the element: ");
  scanf("%d",&e);
  for(i=0;i<n;i++)
  {
    if(a[i]==e)
    {
       loc=i;
    }

  }
  if(loc>0)
     printf("element found at %d th position",loc);
  else
      printf("element not found");
}
