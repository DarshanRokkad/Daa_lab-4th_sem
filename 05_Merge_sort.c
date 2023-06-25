/*
“Deloit”, a software company needs to maintain its employee details like
employeeid, name, address in a record, design and develop a program in
C to sort the employee records based on their employee ID by using
merge sort algorithm, employee ID should be generated randomly.
Determine the time required to sort theelements. Repeat the experiment
for different values of n and plot a graph of the time taken versus n. (n=no
of elements).
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int a[], int low, int mid, int high)
{
    int b[high+1];
    int i = low;
    // lai = left array index and rai = right array index
    int lai = low;
    int rai = mid + 1;
    while (lai <= mid && rai <= high)
    {
        if (a[lai] < a[rai])
        {
            b[i++] = a[lai++];
        }
        else
        {
            b[i++] = a[rai++];
        }
    }
    if (lai > mid)
    {
        for (int k = rai; k <= high; k++)
        {
            b[i++] = a[k];
        }
    }
    else
    {
        for (int k = lai; k <= mid; k++)
        {
            b[i++] = a[k];
        }
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
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
    printf("Merge sort.\n");
    int n;
    printf("Enter number employee id's : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printf("Unsorted employee id's : ");
    print_array(a, n);

    clock_t start = clock();
    merge_sort(a, 0, n - 1);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted employee id's : ");
    print_array(a, n);
    printf("The runtime is %f\n", clk);

    return 0;
}

/* Sample input and output

Merge sort.
Enter number employee id's : 5
Unsorted employee id's : 41 67 34 0 69
Sorted employee id's : 0 34 41 67 69
The runtime is 0.000000

*/