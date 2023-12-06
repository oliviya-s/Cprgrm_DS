#include<stdio.h>
#include<conio.h>

void quicksort(int[10],int,int);

void main()

{
   int list[20],size,i;

   printf("enter size of list: ");
   scanf("%d",&size);

   printf("Enter %d integer values",size);
   for (i=0;i<size;i++)
       {
          scanf("%d",&list[i]);
       }
    quicksort(list,0,size-1);

    printf("list after sorting is: ");
    for(i=0;i<size;i++);
    {
       printf("%d",list[i]);

    }
    getch();
}
void quicksort(int list[10],int first,int last)
{
   int pivot,i,j,temp;
   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j)
      {
         while(list[i]<=list[pivot]&&i<last)
         {
           i++;

         }
         while(list[j]>list[pivot])
         {
             j--;

         }
         if(i<j)
         {
           temp=list[i];
           list[i]=list[j];
           list[j]=temp;
         }
         }
         temp=list[pivot];
         list[pivot]=list[j];
         list[j]=temp;
         quicksort(list,first,j-1);
         quicksort(list,j+1,last);
    }

}
