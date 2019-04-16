//Process scheduling
#include<stdio.h>

//Function to calculate the completion time.
void findCompletionTime(int pr[],int n,int br[],int comp[])
{
    int bb[n];
    bb[0] = 0;
    int b[n];
    memcpy(b, br, n*sizeof(int));
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
                comp[i] = b[i] + bb[i] + comp[i-1];

            }
            else
            {
                bb[i] += 10;
                b[i] = b[i] - 10;
                comp[i] = b[i]+bb[i]+comp[i-1];

            }
        }
    }
}


// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
				int a[], int c[], int tat[])
{
	// calculating turnaround time by adding
	// comp[i] - arr[i]

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
    int comp[n];
    comp[0] = 0;
	//Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt);

	findCompletionTime(processes,n,bt,comp);
	//Function to find turn around time for all processes
	findTurnAroundTime(processes, n, at, comp, tat);

	//Display processes along with all details
//	cout << "Processes "<< " Burst time "
//		<< " Waiting time " << " Turn around time\n";
		printf("\n\nProcesses  Arrival time  Burst time Completion Time  Waiting time  Turn around time\n");

	// Calculate total waiting time and total turn
	// around time
	for (int i=1; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf("%d\t\t%d\t\t%d\t%d\t\t  %d\t\t %d\n",i,at[i],bt[i],comp[i],wt[i],tat[i]);
	}
        printf("\nAverage waiting time = %4.2f",(float)total_wt / (float)(n-1));
//	cout << "\nAverage turn around time = "
//		<< (float)total_tat / (float)n;
        printf("\nAverage turn around time = %4.2f",(float)total_tat / (float)(n-1));
}

// Driver code
int main()
{
    int n;
    printf("Please enter the no. of processes:- ");
    scanf("%d",&n);
    int nn = n+1;
    int at[nn]; //Array to store the arrial time of processes
    int bt[nn];	//Array to store the burst time of processes
    int p[nn];  //Array to store the processes
    at[0] = 0;  
    bt[0] = 0;
    p[0] = 0;

    for(int i=1;i<nn;i++)
    {
        printf("\n+++++++++++++++-++++++++++++++++++++++++\nEnter Details for Process %d:-\n",i);
        printf("Arrival Time:-");
        scanf("%d",&at[i]);
        printf("\nBurst Time:-");
        scanf("%d",&bt[i]);
        p[i] = i;
    }

	findavgTime(p, nn, at, bt);
}
