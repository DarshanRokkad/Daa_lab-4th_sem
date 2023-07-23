/*
Digital maps, unlike humans, see cities as a bunch of nodes. We (humans) 
consider this map as a single entity. a GPS navigation or any other digital 
map divides it into hundreds of segments, with some only 24 meters long. 
A map displays n cities and their distances. Design and develop a program 
in C to print all the cities reachable from a given starting city in a digraph 
by using BFS method. Repeat the experiment for different values of n and 
plot a graph of the time taken versus n(n=no of nodes) 
*/

#include <stdio.h>
#include <time.h>

void bfs(int n, int a[n][n], int source)
{
    // 0 => unvisited vertex and 1 => visited vertex
    int visited[n];
    for (int vertex = 0; vertex < n; vertex++)
    {
        visited[vertex] = 0;
    }

    int queue[n], front = 0, rear = -1;
    queue[++rear] = source;
    visited[source] = 1;

    while (front <= rear)
    {
        int current_vertex = queue[front++];
        for (int vertex = 0; vertex < n; vertex++)
        {
            // if the current vertex is connected to other vertex and that vertex is unvisited
            if (a[current_vertex][vertex] == 1 && visited[vertex] == 0)
            {
                queue[++rear] = vertex;
                printf("The bfs traversal is : %d %d\n", current_vertex, vertex);
                visited[vertex] = 1;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the matrix representation: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int source;
    printf("Enter the source vertix : ");
    scanf("%d", &source);

    clock_t start = clock();
    bfs(n, a, source);
    clock_t end = clock();

    double clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The runtime is %f\n", clk);

    return 0;
}


/* Sample input and output

Enter number of vertices : 5
Enter the matrix representation:
0 1 1 0 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 1
0 1 0 0 0
Enter the source vertix : 0
The bfs traversal is : 0 1
The bfs traversal is : 0 2
The bfs traversal is : 1 3
The bfs traversal is : 2 4
The runtime is 0.000000

*/