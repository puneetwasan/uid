#include<bits/stdc++.h> 
 
int main() 
{ 
 
  int i,count,j,n,time,remain,flag=0,time_quantum=10; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10],temp; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("\nEnter Arrival Time for Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    if(at[count]<=3)
    {
    	printf("Invalid Cpu must remain idle\n");
    	continue;
	}
    printf("Enter Burst Time for Process Number %d :",count+1); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
 /* printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum);
  */ 
  printf("\n\nProcess\t|Burst Time|Turnaround Time|Waiting Time\n\n"); 
  
  	/*for(i=0;i<n;i++) // sort the processes according to their burst times.
	{
		for(j=0;j<n;j++)
		{
			if(bt[i] <bt[j])
			{
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
			}
		}
	}
	*/
	
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\n",count+1,bt[count],time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}