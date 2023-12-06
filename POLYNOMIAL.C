#include<stdio.h>
#include<stdlib.h>
struct poly
{
int coeff;
int exp;
}p1[20],p2[20],p3[20],p4[100];
void read(struct poly[],int);
void display(struct poly[],int);
void add(struct poly[],int,struct poly[],int,struct poly[],int);
void multiply(struct poly[],int,struct poly[],int,struct
poly[],int);
void main()
{
int i,n1,n2,n3,o,j=0,k=0;
printf(&quot;Enter the no. of terms of the 1st and 2nd
polynomial:&quot;);
scanf(&quot;%d %d&quot;,&amp;n1,&amp;n2);

printf(&quot;\nEnter the coefficients and exponents of the 1st
polynomial in descending order of exponents &quot;);
read(p1,n1);
printf(&quot;\nEnter the coefficients and exponents of the 2nd
polynomial in descending order of exponents &quot;);
read(p2,n2);
printf(&quot;The first polynomial: &quot;);
display(p1,n1);
printf(&quot;\nThe second polynomial:&quot;);
display(p2,n2);
while(1)
{
printf(&quot;\nchoose\n1.Addition\n2.Multiplication\n3.Exit\nEnt
er your choice:&quot;);
scanf(&quot;%d&quot;,&amp;o);
switch(o)
{
case 1:add(p1,n1,p2,n2,p3,n3);
break;
case 2:multiply(p1,n1,p2,n2,p3,n3);
break;
case 3:exit(0);
break;

default:printf(&quot;Invalid choice&quot;);
break;
}
}
}
void add(struct poly x1[10],int e1,struct poly x2[10],int
e2,struct poly x3[10],int e3)
{
int i=0,j=0,k=0;
while((i&lt;e1)&amp;&amp;(j&lt;e2))
{
if(x1[i].exp==x2[j].exp)
{
x3[k].coeff=x1[i].coeff+x2[j].coeff;
x3[k].exp=x1[i].exp;
i++;
j++;
k++;
}
else if(x1[i].exp&gt;x2[j].exp)
{
x3[k].coeff=x1[i].coeff;

x3[k].exp=x1[i].exp;
i++;
k++;
}
else
{
x3[k].coeff=x2[j].coeff;
x3[k].exp=x2[j].exp;
j++;
k++;
}
}
while(i&lt;e1)
{
x3[k].coeff=x1[i].coeff;
x3[k].exp=x1[i].exp;
i++;
k++;
}
while(j&lt;e2)
{
x3[k].coeff=x2[j].coeff;

x3[k].exp=x2[j].exp;
j++;
k++;
}
printf(&quot;\nThe sum of the two polynomials:&quot;);
display(x3,k);
}
void read(struct poly a[10],int m)
{
int i;
for(i=0;i&lt;m;i++)
{
printf(&quot;\nTerm %d&quot;,i+1);
printf(&quot;\nEnter the coefficient:&quot;);
scanf(&quot;%d&quot;,&amp;a[i].coeff);
printf(&quot;Enter the exponent :&quot;);
scanf(&quot;%d&quot;,&amp;a[i].exp);
}
}
void display(struct poly b[10],int l)
{
int i;

for(i=0;i&lt;l-1;i++)
{
printf(&quot;%dx^%d+&quot;,b[i].coeff,b[i].exp);
}
printf(&quot;%dx^%d&quot;,b[i].coeff,b[i].exp);
}
void multiply(struct poly r1[10],int f1,struct poly r2[10],int
f2,struct poly
r3[100],int f3 )
{
int i=0,j=0,k=0,te=0,tc=0;
for(i=0;i&lt;f1;i++)
{
for(j=0;j&lt;f2;j++)
{
r3[k].coeff=r1[i].coeff*r2[j].coeff;
r3[k].exp=r1[i].exp+r2[j].exp;
k++;
}
}
for(i=0;i&lt;k;i++)
{

for(j=i+1;j&lt;k;j++)
{
if(r3[i].exp==r3[j].exp)
{
r3[i].coeff+=r3[j].coeff;
int l=j;
while(j&lt;k)
{
r3[j]=r3[j+1];
j++;
}
k--;
j=l-1;
}
}
}
for(i=0;i&lt;k-i;i++)
{
for(j=i+1;j&lt;k;j++)
{
if(r3[i].exp&lt;r3[j].exp)
{

int te=r3[j].exp;
int tc=r3[j].coeff;
while(j&gt;i)
{
r3[j].exp=r3[j-1].exp;
r3[j].coeff=r3[j-1].coeff;
j--;
}
r3[i].exp=te;
r3[i].coeff=tc;
}
}
}
printf(&quot;\ product of polynomials:&quot;);
display(r3,k);
}
