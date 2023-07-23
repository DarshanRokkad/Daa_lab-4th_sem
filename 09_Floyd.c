/*
There have been a number of fire outbreak cases recorded in the Florida area
that has brought about loss of lives to inhabitants and loss of properties. Some
routes within the district can be reconstructed into shortcut routes, so that fire
man can traverse through the district in order to prevent fire incidents. The
objective is to find the minimum distance and shortest path from the fire station
to all the residential layout in Florida area. Write an algorithm by applying
Floyd’s method to find the solution for the given scenario.
*/

#include <stdio.h>
#include <time.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd(int n, int w[n][n], int d[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = w[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("Enter the cost matrix : \n");
    int w[n][n], d[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }

    clock_t start = clock();
    floyd(n, w, d);
    clock_t end = clock();
    double clk = (end - start) / CLOCKS_PER_SEC;

    printf("\nAll pair shortest path matrix is : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\nThe run time is %f\n", clk);

    return 0;
}


/* Sample input and output

Enter number of vertices : 4
Enter the cost matrix : 
0 999 3 999
2 0 999 999 
999 7 0 1
6 999 999 0

All pair shortest path matrix is : 
0 10 3 4 
2 0 5 6 
7 7 0 1 
6 16 9 0 

The run time is 0.000000

*/