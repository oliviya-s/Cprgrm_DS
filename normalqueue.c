#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int enqueue (int *, int *, int);
int dequeue (int *, int, int *);
void status(int,int);

void
main ()
{
  int Que[MAX], front = -1, rear = -1, ch;
  int *q = Que;
  printf ("\t\tSIMPLE QUEUE\n");
  while (1)
    {
      printf ("\nMenu\n1. ENQUEUE\n2. DEQUEUE\n3. Status\n4. EXIT\n");
      printf ("Enter the choice: ");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  rear = enqueue (q, &front, rear);
	  break;
	case 2:
	  front = dequeue (q, front, &rear);
	  break;
	case 3: status(front,rear);

	  break;
	case 4:
	  exit (0);
	default:
	  printf ("Wrong input");
	  break;
	};
    }
}


int enqueue (int *qu, int *fr, int re)
{
    int item, i;
    if (re == MAX - 1)
    {
      printf ("Queue is full");
      return re;
    }
    if (*fr == -1)
    {
      *fr = 0;
    }
    printf ("Enter the element: ");
    scanf ("%d", &item);
    re++;
    *(qu + re) = item;
    printf ("Enqueued Sucessfully");
    printf("\n Current Queue:\n");
    for (i = *fr; i <= re; ++i)
        printf ("%d ", *(qu + i));
    return re;
}

int dequeue (int *qu, int fr, int *re)
{
  int item,i;
  if (fr == -1)
    {
      printf ("Queue is Empty");
      return fr;
    }
  else
    {
      if (*re == fr)
	{
	  item = *(qu + fr);
	  printf ("%d is Dequeued", item);
	  fr = *re = -1;
	}
      else
	{
	  item = *(qu + fr);
	  fr++;
	  printf ("%d is Dequeued", item);
	}
	printf("\n Current Queue: \n");
    for(i=fr;i<*re;++i)
        printf("%d ",*(qu+i));
    return fr;
    }
}
void status(int fr,int re)
{
    if(fr==-1)
        printf("Queue is Empty");
    else if(re==MAX-1)
        printf("Queue is Full");
    else
        printf("Free Space = %d",MAX-re-1);
}
