// Vaibhav Shah
// 20BBS0162
#include<stdio.h>
int main()
{
    int at[10],bt[10],x[10], pid[10];
    int wt[10],tt[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tat=0,end;
    printf("\nEnter the number of Processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Process id of process[%d] : ",i+1); scanf("%d",&pid[i]);
        printf("\nEnter arrival time of process %d : ",i+1); scanf("%d",&at[i]);
        printf("\nEnter burst time of process %d : ",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        x[i]=bt[i];
        bt[9]=9999;
    }
    for(time=0;count!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++){
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
                smallest=i;
        }
        bt[smallest]--;
        if(bt[smallest]==0)
        {
            count++;
            end=time+1;
            wt[smallest] = end - at[smallest] - x[smallest];
            tt[smallest] = end - at[smallest];
        }
    }
    printf("pid \t burst \t arrival \twaiting \tturnaround ");
    for(i=0;i<n;i++)
    {
        printf("\n %d \t %d \t %d\t\t%d \t\t%d\t",pid[i],x[i],at[i],wt[i],tt[i]);
        avg = avg + wt[i];
        tat = tat + tt[i];
    }
    printf("\n\nAverage waiting time = %lf\n",avg/n);
    printf("Average Turnaround time = %lf",tat/n);
}
