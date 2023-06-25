/*
Assume that NMIT college needs to maintain the student details like USN, 
name, and contact details in a record. USN should be generated 
randomly. Design and develop a program in C to sort the records based 
on USN by using quick sort algorithm, Determine the time required to sort
the roll numbers. Repeat the experiment for different values of n and plot 
a graph of the time taken versus n. (n=no of elements).
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[] , int n , int low ,int high)
{
    int pivot = a[low];
    int i = low + 1 ;
    int j = high ;
    while(1)
    {
        while(a[i]<=pivot && i<high)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp ;
        }
        else 
        {
            int temp = a[j];
            a[j] = a[low];
            a[low] = temp ;
            return j ;
        }
    }
}

void quick_sort(int a[],int n,int low , int high)
{
    if(low<high)
    {
        int j = partition(a,n,low,high);
        quick_sort(a,n,low,j-1);
        quick_sort(a,n,j+1,high);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    printf("Quick sort.\n");
    int n ;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    int a[n];
    for(int i = 0 ;i<n ;i++)
    {
        a[i]=rand()%100;
    }
    printf("Unsorted usn : ");
    print_array(a,n);

    clock_t start = clock();
    quick_sort(a,n,0,n-1);
    clock_t end = clock();
    double clk = (double)(end-start)/CLOCKS_PER_SEC;

    printf("Sorted usn : ");
    print_array(a,n);
    printf("The runtime is %f\n", clk);

    return 0 ;
}

/* Sample input and output

Quick sort.
Enter the number of students : 5
Unsorted usn : 41 67 34 0 69 
Sorted usn : 0 34 41 67 69 
The runtime is 0.000000

*/