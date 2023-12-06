#include<stdio.h>
int a[10],v[11],t=0;
int check(int a)
{
int i,f=0;
for(i=0;i<t;i++)
{
if(v[i]==a)
f+=1;
}
if(f==0)
return 1;
else
return 0;
}
void main()
{
int k,i,e,o;
while(1)
{
printf("Enter data: ");
scanf("%d",&e);
k=e%10;
if(k<0)
k*=-1;
i=k;
if(check(k))
{
a[k]=e;
v[t++]=k;
}
else
{
do
{
k++;
k=k%10;
if(check(k))
{
a[k]=e;
v[t++]=k;
break;
}
}while(k!=i);
if(k==i)
printf("Element not inserted!!!");
}
printf("\nDo you want to continue: (Yes=1/No=0) ");
scanf("%d",&o);
if(o==0)
break;
}
printf("Element now:\n");
for(i=0;i<10;i++)
{
if(!check(i))
printf("%d -> %d",i,a[i]);
printf("\n");
}
}







