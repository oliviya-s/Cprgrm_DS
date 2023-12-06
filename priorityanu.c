#include <stdio.h>
#include <stdlib.h>
#define MAX 30

void main()
{

    int n,wt[20],bt[20],at[10],tat[20],avgwt,avgtat,i,j,p[20],comp_t[20],priority[30];
    printf("enter the number of processes ");
    scanf("%d",&n);

    printf("enter the arrival time\n");

    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("p[%d]",i+1);
        scanf("%d",&at[i]);
    }
    printf("enter the process burst time\n");

    for(i=0;i<n;i++)
    {
        printf("p[%d]",i+1);
        scanf("%d",&bt[i]);
        wt[i]=tat[i]=comp_t[i]=0;
    }
     printf("enter the process  priority \n");

    for(i=0;i<n;i++)
    {
        printf("p[%d]",i+1);
        scanf("%d",&priority[i]);
    }
    tat[0]=comp_t[0]=bt[0];
    int tempid,tempat,tempbt,tempri;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(priority[i]>priority[j]){
            tempid= p[i];
            tempat=at[i];
            tempbt=bt[i];
            tempri=priority[i];
            p[i]=p[j];
            at[i]=at[j];
            bt[i]=bt[j];
            priority[i]=priority[j];
            p[j]=tempid;
            at[j]=tempat;
            bt[j]=tempbt;
            priority[j]=tempri;
                            }
                }
            }

    for(i=1;i<n;i++){
        int ct=0;
        for(j=i;j>=0;j--){
            ct+=bt[j];
        }
        comp_t[i]=ct;
        wt[i]=comp_t[i-1]-at[i];
        tat[i]=bt[i]+wt[i];
    }
    printf("***********\n");
    printf("Process ID |Priority  | Arrival Time | Burst Time  | Waiting Time  | Completion Time | TurnAround Time |");
    printf("\n");
    printf("\n");
    for(i=0;i<n;i++){
    printf("   %d       |       %d      |      %d      |     %d         |       %d         |       %d         |", p[i],priority[i], at[i], bt[i], wt[i],comp_t[i],tat[i]);
    printf("\n");
    }

    printf("gantt chart\n");
     for(i=0;i<n;i++){
    printf("|__p[%d]__",p[i]);
     }
     printf("\n");
     printf("0        ");
       for(i=0;i<n;i++){
           printf("%d     ",comp_t[i]);
       }
}
