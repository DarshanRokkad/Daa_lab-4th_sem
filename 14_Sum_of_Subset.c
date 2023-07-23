/*
Consider the Subset sum problem in which the objective is to find subset of
elements that are selected from a given set whose sum adds up to a given
number K. Assume the set contains non-negative values and also the input set
is unique (no duplicates are present.). Design and develop a program in C to
find the subset of a given set whose sum is equal to a positive integer K and
display an appropriate message if the given problem instance does not have the
solution. Note : Use Backtracking method.
*/

#include <stdio.h>

int req_sum, no_solution, consider[10];

/*  EXPLAINATION


void subset(int a[], int pos, int cur_sum, int rem_sum)
{
    // considering current element
    consider[pos] = 1;
    // if current sum and including of current element gives the required sum then print sequence
    if ((cur_sum + a[pos]) == req_sum)
    {
        printf("Subset solution %d is : ", ++no_solution);
        for (int i = 0; i <= pos; i++)
        {
            // if element is considered to get subset sum then print it
            if (consider[i] == 1)
            {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
    // can make including call only if including current and next element to current sum is less than required sum
    if (((cur_sum + a[pos]) + a[pos + 1]) <= req_sum)
    {
        // including recursive call
        subset(a, pos + 1, cur_sum + a[pos], rem_sum - a[pos]);
    }
    // can make excluding call only if sum of (current sum and remaining sum excluding current element)
    // and
    // sum of( current sum and (next element excluding current element to current sum))
    if ((((rem_sum - a[pos]) + cur_sum) >= req_sum) && ((cur_sum + a[pos + 1]) <= req_sum))
    {
        // excluding current current element
        consider[pos] = 0;
        // excluding recursive call
        subset(a, pos + 1, cur_sum, rem_sum - a[pos]);
    }
}*/


void subset(int a[], int pos, int cur_sum, int rem_sum)
{
    consider[pos] = 1;
    if ((cur_sum + a[pos]) == req_sum)
    {
        printf("Subset solution %d is : ", ++no_solution);
        for (int i = 0; i <= pos; i++)
        {
            if (consider[i] == 1)
            {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
    if (((cur_sum + a[pos]) + a[pos + 1]) <= req_sum)
    {
        subset(a, pos + 1, cur_sum + a[pos], rem_sum - a[pos]);
    }
    if ((((rem_sum - a[pos]) + cur_sum) >= req_sum) && ((cur_sum + a[pos + 1]) <= req_sum))
    {
        consider[pos] = 0;
        subset(a, pos + 1, cur_sum, rem_sum - a[pos]);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of array in ascending order : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the required sum : ");
    scanf("%d", &req_sum);

    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += a[i];
    }

    if (req_sum > arr_sum)
    {
        printf("No solution exists.");
    }
    else
    {
        printf("The solution is : \n");
        no_solution = 0;
        subset(a, 0, 0, arr_sum);
    }

    return 0;
}


/* Sample input and output

Enter the number of elements : 4
Enter the elements of array in ascending order : 1 2 3 4
Enter the required sum : 7
The solution is : 
Subset solution 1 is : 1 2 4 
Subset solution 2 is : 3 4 

*/