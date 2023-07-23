/*
“Sunshine” a job search portal is looking for engineering graduates, they
need to sort the candidate’s resume based on their ranking(Average
Percentage). Ranking should be generated randomly. Design and develop
a program in C to sort the resumes by using heap sort algorithm.
Determine the time required to sort the elements. Repeat the experiment
for different values of n and plot a graph of the time taken versus n.(n=no of elements).
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n)
{
    // heap construction
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    // sorting
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    printf("Heap sort.\n");
    int n;
    printf("Enter the number of students : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printf("Unsorted students ranking : ");
    print_array(a, n);

    clock_t start = clock();
    heap_sort(a, n);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted students ranking : ");
    print_array(a, n);
    printf("The runtime is %f\n", clk);

    return 0;
}


/* Sample input and output

Heap sort.
Enter the number of students : 10
Unsorted students ranking : 41 67 34 0 69 24 78 58 62 64 
Sorted students ranking : 0 24 34 41 58 62 64 67 69 78 
The runtime is 0.000000

*/