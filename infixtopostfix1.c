#include<stdio.h>
#include<stdlib.h>

int getprec(char);
int main()


{
  int i=0,len,prec,p=0,top=0;
  char postfix[50],stack[25],ch[50],temp;
  stack[top]='#';
  printf("enter infix: ");
  scanf("%s",&ch);
  for(i=0;ch[i]!='\0';i++)
  {
     if(ch[i]=='(')
     {
       top=top+1;
       stack[top]=ch[i];
     }
     else if(isalpha(ch[i]))
     {
       postfix[p]=ch[i];
       p=p++;

     }
     else if(ch[i]==')')
     {
       while((temp=stack[top])!=')')
       {
          postfix[p]=temp;
          top=top-1;
          p=p+1;

       }
     }
     else
     {
        prec=getprec(ch[i]);
        if((stack[top]!='#')&&prec<=getprec(stack[top]))
        {
           postfix[p]=stack[top];
           top=top-1;
           p=p+1;
        }
        top=top+1;
        stack[top]=ch[i];

     }
  }
  while(stack[top]!='#')
  {
    postfix[p]=stack[top];
    top=top-1;
    p=p+1;
  }
  postfix[p]='\0';
  printf("the postfix expression is : %s",postfix);
  return 0;
}

int getprec(char c)
{
   if(c=='^')
        return 3;
    else if(c=='*'||c=='%')
        return 2;
    else if (c=='+'||c=='-')
        return 1;

    else if (c=='(')
         return 0;

    else
       return -1;
}
