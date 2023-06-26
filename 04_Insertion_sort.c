/*
“Aircel” a mobile network company need to maintain the telephone 
numbers of its customer in order to call and inform them about the new 
year offer. They have to sort the contact numbers in ascending order to 
keep track of the customers whom they called. Design and develop a
program in C to sort the phone numbers by using insertion sort algorithm, 
Input should be generated randomly. Determine the time required to sort 
the elements. Repeat the experiment for different values of n and plot a
graph of the time taken versus n. (n=no of elements).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion_sort(long long a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        long long ele = a[i];
        int j = i - 1;
        while (j >= 0 && ele < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1]=ele;
    }
}
void print_array(long long a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", a[i]);
    }
    printf("\n");
}
int main()
{
    printf("Insertion sort.\n");
    int n;
    printf("Enter number of phone numbers : ");
    scanf("%d", &n);
    long long a[n];
    long long max = 9999999999, min = 9000000000;
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % (max - min + 1)) + min;
    }
    printf("Unsorted phone numbers : ");
    print_array(a, n);

    clock_t start = clock();
    insertion_sort(a, n);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted phone numbers : ");
    print_array(a, n);
    printf("The runtime is %f\n", clk);

    return 0;
}

/* Sample input and output 

Insertion sort.
Enter number of phone numbers : 5
Unsorted phone numbers : 9000000041 9000018467 9000006334 9000026500 9000019169 
Sorted phone numbers : 9000000041 9000006334 9000018467 9000019169 9000026500 
The runtime is 0.000000

*/