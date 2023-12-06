#include<stdio.h>
void main()
{
    int i,j,n,temp,ar[5];
    printf("enter size:");
    scanf("%d",&n);
    printf("enter %d elements: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&ar[i]);
    for(i=1;i<n;i++)
    {
        temp=ar[i];
        j=i-1;
        while(temp<ar[j]&&j>=0)
        {
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=temp;
    }
    printf("sorted elements: ");
    for(i=0;i<n;i++)
    printf("%d \n",ar[i]);
}
