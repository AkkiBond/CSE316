//Process scheduling
#include<stdio.h>


void findCompletionTime(int pr[],int n,int b[],int comp[])
{
    int bb[n];
    int bb[0] = 0;
    for(int i=1;i<n;i++)
    {
        if(b[i]<=6)
        {
            comp[i] = b[i] + comp[i-1];
        }
        else
        {
            bb[i] = 6;
            b[i] = b[i] - 6;

            if(b[i]<=10)
            {
                comp[i] = b[i] + bb[i];

            }
            else
            {
                bb[i] += 10;
                b[i] = b[i] - 10;
                int m = b[1];
                for(int j=1;j<n;j++)
                {
                    if(m<b[i])
                    {
                        m = b[i];

                    }
                }
            }
        }
    }
}


// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
				int a[], int c[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]

	for (int i = 1; i < n ; i++)
		tat[i] = c[i] - a[i];
}


// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n,
						int bt[], int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = 6 + wt[i-1] ;
}

//Function to calculate average time
void findavgTime( int processes[], int n,int at[], int bt[])
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
    int comp[n] = {0};
	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, at, comp, tat);

	//Display processes along with all details
//	cout << "Processes "<< " Burst time "
//		<< " Waiting time " << " Turn around time\n";
		printf("Processes  Arrival time  Burst time  Waiting time  Turn around time\n");

	// Calculate total waiting time and total turn
	// around time
	for (int i=1; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
//		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
//			<< wt[i] <<"\t\t " << tat[i] <<endl;
			printf("\n\n %d\t\t%d\t\t%d\t %d\t\t %d\n",i,at[i],bt[i],wt[i],tat[i]);
	}

//	cout << "Average waiting time = "
//		<< (float)total_wt / (float)n;
		printf("Average waiting time = %4.2f",(float)total_wt / (float)(n-1);
//	cout << "\nAverage turn around time = "
//		<< (float)total_tat / (float)n;
        printf("Average turn around time = %4.2f",(float)total_tat / (float)(n-1);
}

// Driver code
int main()
{
	//process id's
//	int processes[] = { 1, 2, 3};
//	int n = sizeof processes / sizeof processes[0];
//
//	//Burst time of all processes
//	int burst_time[] = {10, 5, 8};

    int n;
    printf("Please enter the no. of processes:- ");
    scanf("%d",&n);
    int nn = n+1;
    int at[nn];
    int bt[nn];
    int p[nn];
    int at[0] = 0;
    int bt[0] = 0;
    int p[0] = 0;

    for(int i=1;i<nn;i++)
    {
        printf("Enter Details for Process %d:-\n",i+1);
        printf("Arrival Time:-");
        scanf("%d",&at[i]);
        printf("Burst Time:-");
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }

	findavgTime(p, nn, at, bt);
}
