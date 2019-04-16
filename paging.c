#include<stdio.h>
int main()
{
int i,j; //Variables for loops.
int n,no,k,avail,count=0; //Variable to store number of pages and no of frames.
int a[50],frame[50];
            n = 12; // No. of pages.
            no = 12; //No of frames assigned to pages
            for(i=1;i<=n;i++)
            {
                a[i] = i; // Loop which stores the page number in page table.
            }

            srand(time(NULL)); // Function to call before using random number for frames.

            for(i=1;i<=no;i++)
            {
                frame[i]= (rand() % 101) + 500; //For assigning the random frame numbers.
            }

            printf("Page Number\tFrame Number\n");

            for(i=1;i<=n;i++)
            {
                printf("%d\t\t",a[i]);
                printf("%d",frame[i]);
                printf("\n");
            }

}

