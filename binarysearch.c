#include<stdio.h>
void bsearch(int[],int,int);
void main()
{
    int n,x;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the value to be searched: ");
    scanf("%d",&x);
    bsearch(a,n,x);
}


void bsearch(int a[],int n,int x)
{
    int mid,l,d;
    mid=(l+d)/2;
    l= 0;
    d= n - 1;
    mid = (l+d)/2;
    while (l<=d)
    {
        if (a[mid] < x)
            l = mid + 1;
        else if (a[mid] == x)
        {
            printf("%d found at %d location.\n", x, mid+1);
            break;
        }
        else
        d = mid - 1;
        mid = (l + d)/2;
    }
    if (l > d)
    printf("\nElement not found.");
    return 0;

}
