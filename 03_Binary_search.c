/*
“Digishop” a online shopping website needsto keep track of the product
availabilitybased on the product ID. Design a program in C to read the 
product ID provided by the customer and search for it’s availability by
using Binary search method and display the relevant message whether 
the product is in stock or not. Determine the time required to search for 
the product. Repeat the experiment for different values of n and plot a
graph of the time taken versus n. (n=no of elements).
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int binary_search(int a[], int n, int data)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data < a[mid])
        {
            high = mid - 1;
        }
        else if (data > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int low = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[low])
            {
                low = j;
            }
        }
        // swap
        if (low != i)
        {
            int temp = a[low];
            a[low] = a[i];
            a[i] = temp;
        }
    }
}
int main()
{
    printf("Binary Search.\n");
    int n;
    printf("Enter the number of product id's : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    int data;
    printf("Enter the product id to be searched : ");
    scanf("%d", &data);
    selection_sort(a, n);
    printf("Product id : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    clock_t start = clock();
    int result = binary_search(a, n, data);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    if (result < 0)
    {
        printf("%d id dont exist in the product id's.\n", data);
    }
    else
    {
        printf("%d is present at %d index of the product id's.\n", data, result);
    }
    printf("The runtime is %f\n", clk);

    return 0;
}


/* Sample input and output

Binary Search.
Enter the number of product id's : 5
Enter the product id to be searched : 45
Product id : 0 34 41 67 69 
45 id dont exist in the product id's.
The runtime is 0.000000

*/