/*
DMART is providing special offer to its customer on New Year’s Eve.
Customers can buy anything they want with flat80% discount, but the
products they buy should fit into the basket provided by DMART. The
objective is to collect the expensive products which fit into the given
basket and overall weight of the basket cannot exceed 15kg.Write an
algorithm by using knapsack algorithm using dynamic programming to
find the best subset for the given scenario.
*/

#include <stdio.h>
#include <time.h>

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int knapsack(int no_items, int weight[no_items], int cost[no_items], int capacity, int y[no_items + 1][capacity + 1])
{
    for (int i = 0; i <= no_items; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                y[i][j] = 0;
            }
            else if (j < weight[i])
            {
                y[i][j] = y[i - 1][j];
            }
            else
            {
                y[i][j] = max((y[i - 1][j]), (y[i - 1][j - weight[i]] + cost[i]));
            }
        }
    }
    printf("The table for solving knapsack using dynamic programming is: \n");
    for (int i = 0; i <= no_items; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            printf("%d ", y[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int no_items;
    printf("Enter the number of items : ");
    scanf("%d", &no_items);

    // storing the weight of the items in there positions(1 to number_of_times) not in index(0 to number_of_times-1)
    int weight[no_items+1];
    printf("Enter the weight of %d items : ", no_items);
    for (int i = 1; i <= no_items; i++)
    {
        scanf("%d", &weight[i]);
    }

    // storing the cost of the items in there positions(1 to number_of_times) not in index(0 to number_of_times-1)
    int cost[no_items+1];
    printf("Enter the cost of %d items : ", no_items);
    for (int i = 1; i <= no_items; i++)
    {
        scanf("%d", &cost[i]);
    }

    int capacity;
    printf("Enter the capacity of the basket : ");
    scanf("%d", &capacity);

    int y[no_items + 1][capacity + 1];

    clock_t start = clock();
    knapsack(no_items, weight, cost, capacity, y);
    clock_t end = clock();
    double clk = (end - start) / CLOCKS_PER_SEC;
    
    printf("Optimal solution from knapsack problem is %d\n", y[no_items][capacity]);
    printf("\nThe run time is %f\n", clk);

    return 0;
}


/* Sample input and output

Enter the number of items : 4
Enter the weight of 4 items : 2 1 3 2
Enter the cost of 4 items : 12 10 20 15
Enter the capacity of the basket : 5
The table for solving knapsack using dynamic programming is: 
0 0 0 0 0 0 
0 0 12 12 12 12 
0 10 12 22 22 22 
0 10 12 22 30 32 
0 10 15 25 30 37 
Optimal solution from knapsack problem is 37

The run time is 0.000000

*/
