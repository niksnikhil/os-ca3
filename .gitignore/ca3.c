#include<stdio.h> 
 
int main() 
{ 
 
  int c,i,n,time,r,fg=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  r=n; 
  for(count=0;c<n;c++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",c+1); 
    scanf("%d",&at[c]); 
    scanf("%d",&bt[c]); 
    rt[c]=bt[c]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,c=0;r!=0;) 
  { 
    if(rt[c]<=time_quantum && rt[c]>0) 
    { 
      time+=rt[c]; 
      rt[c]=0; 
      fg=1; 
    } 
    else if(rt[c]>0) 
    { 
      rt[c]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[c]==0 && fg==1) 
    { 
      r--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[c],time-at[c]-bt[c]); 
      wait_time+=time-at[count]-bt[c]; 
      turnaround_time+=time-at[c]; 
      fg=0; 
    } 
    if(c==n-1) 
      c=0; 
    else if(at[c+1]<=time) 
      c++; 
    else 
      c=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
