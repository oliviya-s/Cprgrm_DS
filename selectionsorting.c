#include<stdio.h>
void main()
{
    int ar[50],i,j,n,temp;
    printf("enter size:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    for(i=0;i<n;i++)
    {
       for(j=i+1;j<n;j++);
       {
           if(ar[i]>ar[j])
           {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
           }
       }
    }
    printf("sorted array:");
    for(i=0;i<n;i++)
    {
           printf("%d\n",ar[i]);
    }
    printf("\n");
    return 0;
}
