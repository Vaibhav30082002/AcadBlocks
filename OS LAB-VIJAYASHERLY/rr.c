// Vaibhav Shah
// 20BBS0162
#include<stdio.h>
struct roundrobin
{
    int wait_time,turnaround_time, arrival_time[10], burst_time[10],pid[10];
    float average_wait_time, average_turnaround_time;
};
 
int main() {
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int temp[10];
    struct roundrobin r;
    r.wait_time=0;
    r.turnaround_time=0;
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d", &limit);
    x = limit;
    for(i = 0; i < limit; i++)
    {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Process id:\t");
        scanf("%d", &r.pid[i]);
        printf("Arrival Time:\t");
        scanf("%d", &r.arrival_time[i]);
        printf("Burst Time:\t"); scanf("%d", &r.burst_time[i]);
        temp[i] = r.burst_time[i];
    }
    printf("\nEnter Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i]; temp[i] = 0; counter = 1; }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
            x--;
            printf("\%d\t\t\t%d\t\t\t %d\t\t\t %d\n", r.pid[i],r.burst_time[i], total - r.arrival_time[i], total - r.arrival_time[i] - r.burst_time[i]);
            r.wait_time =r.wait_time + total -r.arrival_time[i] - r.burst_time[i];
            r.turnaround_time = r.turnaround_time + total - r.arrival_time[i];
            counter = 0;
        }
        if(i == limit - 1)
        {
            i = 0;
            
        }
        else if(r.arrival_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    r.average_wait_time = r.wait_time * 1.0 / limit;
    r.average_turnaround_time = r.turnaround_time * 1.0 / limit;
    printf("\n\nAverage Waiting Time:\t%f", r.average_wait_time);
    printf("\nAvg Turnaround Time:\t%f\n", r.average_turnaround_time);
    printf("\n\n");
    return 0;
}
