#include<conio.h>

#include<stdio.h>

int main()
{
	int n; //no.of processes.
	
	int i,j,temp;
	
	int burstTime[100],wTime=0,tAT=0; //burst time of processes.
	
	float awt , atat ,_awt =0 ,_atat =0;
	
	printf("Enter the no.of processes : ");
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time for process %d : ",i+1);
		scanf("%d",&burstTime[i]);
	}
	
	for(i=0;i<n;i++) // sort the processes according to their burst times.
	{
		for(j=0;j<n;j++)
		{
			if(burstTime[i] <burstTime[j])
			{
				temp = burstTime[i];
				burstTime[i] = burstTime[j];
				burstTime[j] = temp;
			}
		}
	}
	
	printf("Pid \t\t BT \t\t wt \t\t tAT");
	
	for(i=0;i<n;i++)
	{
		tAT = burstTime[i]+wTime;
		printf("\n%d \t\t %d \t\t %d \t\t %d", i+1 , burstTime[i] , wTime ,tAT );
	
		_awt += wTime;
		_atat +=tAT;
		wTime+=burstTime[i];
	}
	
	awt = _awt/n;
	atat = _atat/n;
	
	printf("\nAverage Waiting time : %f",awt);
	printf("\nAverage Turn around time : %f",atat);
	getch();
}
