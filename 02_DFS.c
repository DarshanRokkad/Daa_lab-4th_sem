/*
An island is surrounded by water and is formed by connecting adjacent 
lands horizontally or vertically. You may assume all four edges of the grid 
are all surrounded by water. Given an m x n 2D binary grid which 
represents a map of '1's (land) and '0's (water), return the number of 
islands using DFS algorithm. Design and develop a program in C to print 
all the lands reachable from a given starting land in a digraph by using DFS 
method. Repeat the experiment for different values of n and plot a graph 
of the time taken versus n(n=no of nodes)
*/

#include <stdio.h>
#include <time.h>

void dfs(int n, int a[n][n], int source, int visited[n], int order[n][2])
{
    static int k = 0;
    visited[source] = 1;
    for (int vertex = 0; vertex < n; vertex++)
    {
        // if source is connected to vertex and that vertex is unvisited
        if (a[source][vertex] == 1 && visited[vertex] == 0)
        {
            order[k][0] = source;
            order[k][1] = vertex;
            k++;
            dfs(n, a, vertex, visited, order);
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the representation matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int source;
    printf("Enter the source vertex : ");
    scanf("%d", &source);
    int visited[n];
    for (int vertex = 0; vertex < n; vertex++)
    {
        visited[vertex] = 0;
    }
    int order_of_visit[n][2];

    clock_t start = clock();
    dfs(n, a, source, visited, order_of_visit);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    for (int vertex = 0; vertex < n; vertex++)
    {
        if (visited[vertex] == 1)
        {
            printf("%d is reachable.\n", vertex);
        }
        else
        {
            printf("%d is not reachable.\n", vertex);
        }
    }

    printf("DFS traversal : \n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d %d\n", order_of_visit[i][0], order_of_visit[i][1]);
    }
    printf("The runtime is %f\n", clk);

    return 0;
}


/* Sample input and output

Enter number of vertices : 5
Enter the representation matrix : 
0 1 1 0 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 1
0 1 0 0 0
Enter the source vertex : 0
0 is reachable.
1 is reachable.
2 is reachable.
3 is reachable.
4 is reachable.
DFS traversal : 
0 1
1 3
3 4
0 2
The runtime is 0.000000

*/