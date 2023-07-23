/*
DigiMap services is a module in G-Maps which is used to find the distance from
one place to another or from your location to the nearest desired location. This
requires the Shortest Path Algorithm, as there are various routes/paths
connecting them but it has to show the minimum distance. . Represent a
city/place with a vertex and the route between two cities/places as an edge,
then by using Dijkstra’s algorithm, find the shortest routes between any two
cities/places or from one city/place to another city/place.
*/

#include <stdio.h>
#include <time.h>

int choose(int n, int dist[], int selected[])
{
    int j = 1, min = 100;
    for (int i = 1; i <= n; i++)
    {
        if ((dist[i] < min) && (selected[i] == 0))
        {
            min = dist[i];
            j = i;
        }
    }
    return j;
}

void spath(int n, int cost[n + 1][n + 1], int source, int dist[])
{
    int selected[n + 1], i;
    for (i = 1; i <= n; i++)
    {
        selected[i] = 0;
        dist[i] = cost[source][i];
    }
    // except source we have to find for all so loop starts from 2 
    for (int num = 2; num <= n; num++)
    {
        int cur_source = choose(n, dist, selected);
        selected[cur_source] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (((dist[cur_source] + cost[cur_source][i]) < dist[i]) && (!selected[i]))
            {
                dist[i] = dist[cur_source] + cost[cur_source][i];
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    int cost[n + 1][n + 1];
    printf("Enter the cost of adjacency matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int source;
    printf("Enter the source vertices: ");
    scanf("%d", &source);

    int dist[n + 1];
    clock_t start = clock();
    spath(n, cost, source, dist);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Shortest path from %d to all vertices is : \n", source);
    for (int i = 1; i <= n; i++)
    {
        printf("%d to %d = %d\n", source, i, dist[i]);
    }
    printf("The run time is %f\n", clk);

    return 0;
}

/* Sample input and output

Enter number of vertices : 5
Enter the cost of adjacency matrix : 
0       4       2       999     8
999     0       999     4       5
999     999     0       1       999
999     999     999     0       3
999     999     999     999     0
Enter the source vertices: 1
Shortest path from 1 to all vertices is : 
1 to 1 = 0
1 to 2 = 4
1 to 3 = 2
1 to 4 = 3
1 to 5 = 6
The run time is 0.000000

*/