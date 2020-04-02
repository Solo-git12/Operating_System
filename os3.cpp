//#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int testcases;
struct proces
{
      char proces_name;
      int arrival_time, burst_timee, ct, priority;
      int status;
}queue1[10];

void Sorting_Arrival()
{
      struct proces temp;
      int i, j;
      for(i = 0; i < testcases - 1; i++)
      {
            for(j = i + 1; j < testcases; j++)
            {
                  if(queue1[i].arrival_time > queue1[j].arrival_time)
                  {
                        temp = queue1[i];
                        queue1[i] = queue1[j];
                        queue1[j] = temp;
                  }
            }
      }
}


void display()
{
	printf("\nProcess Name\tArrival Time\tBurst Time\tPriority");
      
      for(int i = 0;i<testcases;i++)
      {
      	printf("\n%c\t\t%d\t\t%d\t\t%d", queue1[i].proces_name, queue1[i].arrival_time, queue1[i].burst_timee,queue1[i].priority);
      }
      printf("\n");
}

int main()
{
      int i,p,total = 0, x, counter = 0,burst_timee = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      
	  char c;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &testcases);
      for(i = 0, c = 'A'; i < testcases; i++, c++)
      {
            queue1[i].proces_name = c;
            printf("\nEnter Details For Process[%C]:\n", queue1[i].proces_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &queue1[i].arrival_time );
            arrival_time[i]  = queue1[i].arrival_time ;
            printf("Enter Burst Time:\t");
            scanf("%d", &queue1[i].burst_timee);
            printf("Enter Priority:\t");
            scanf("%d", &queue1[i].priority);
            burst_timee = burst_timee + queue1[i].burst_timee;
            
      }
      
      
     
      
      Sorting_Arrival();
      display();
      printf("--------------------------------------------------------------------------------------------------------------------\n");
      printf("                                AFTER PREMPEMTIVE PRIORITY SCHEDULING\n");
      for(int i = 0;i<testcases-1;i++)
      {
      	 if(queue1[i+1].arrival_time <= queue1[i].burst_timee && queue1[i+1].priority <  queue1[i].priority)
      	 {
      	 	int time_intersect =  queue1[i+1].arrival_time - queue1[i].arrival_time;;
      	 	queue1[i].burst_timee = queue1[i].burst_timee - time_intersect;
      	 	burst_time[i] = queue1[i].burst_timee ;
		    temp[i] = burst_time[i];
		   }
		 else
		  {
		  	queue1[i].burst_timee = 0 ;
		  	burst_time[i] = queue1[i].burst_timee ;
		  temp[i] = burst_time[i];
		  }
		 display();
      }
      queue1[testcases - 1].burst_timee = 0 ;
      display();
      
      printf("--------------------------------------------------------------------------------------------------------------------\n");
      printf("                                AFTER ROUND ROBIN SCHEDULING\n");
      
      
      
     	
      
     printf("\nEnter Time Quantum:\t"); 
     scanf("%d", &time_quantum);
     
     
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, p = 0; x != 0;)
      {
      	cout<<"inside loop"<<endl;
            if(temp[p] <= time_quantum && temp[p] > 0)
            {
                  total = total + temp[p];
                  temp[p] = 0;
                  counter = 1;
                  cout<<"total"<<total;
            }
            else if(temp[p] > 0)
            {
                  temp[p] = temp[p] - time_quantum;
                  total = total + time_quantum;
                  cout<<"total"<<total;
            }
            if(temp[p] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[p], total - arrival_time[p], total - arrival_time[p] - burst_time[p]);
                  wait_time = wait_time + total - arrival_time[p] - burst_time[p];
                  turnaround_time = turnaround_time + total - arrival_time[p];
                  counter = 0;
            }
            if(p == testcases - 1)
            {
                  p = 0;
            }
            else if(arrival_time[p + 1] <= total)
            {
                  p++;
            }
            else
            {
                  p = 0;
            }
      }
 
      average_wait_time = wait_time * 1.0 / testcases;
      average_turnaround_time = turnaround_time * 1.0 / testcases;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;
}
