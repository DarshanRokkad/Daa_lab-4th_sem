/*
Bangalore Water supply Board responsibility is to distribute water evenly
among all the areas in Bangalore city. A new layout has been developed
by Maxworth real estate developers. BWSB should connect the water
lines to the new layout with minimum cost. The objective is to connect
the water pipes so that it reaches all the houses in new layout with
minimum cost. Write an algorithm by applying Kruskal’s method to find
the minimum spanning tree for the given scenario.
*/

#include <stdio.h>
#include <time.h>

typedef struct edge
{
    int u, v, cost;
} edge;

int find(int v, int parent[])
{
    while (v != parent[v])
    {
        v = parent[v];
    }
    return v;
}

void union_ij(int u, int v, int parent[])
{
    if (u < v)
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
    }
}

void kruskal(int no_vertices, edge e[], int no_edges)
{
    for (int i = 0; i < no_edges; i++)
    {
        for (int j = 0; j < no_edges - 1; j++)
        {
            if (e[j + 1].cost < e[j].cost)
            {
                // swap the edge
                edge temp;

                temp.u = e[j].u;
                temp.v = e[j].v;
                temp.cost = e[j].cost;

                e[j].u = e[j + 1].u;
                e[j].v = e[j + 1].v;
                e[j].cost = e[j + 1].cost;

                e[j + 1].u = temp.u;
                e[j + 1].v = temp.v;
                e[j + 1].cost = temp.cost;
            }
        }
    }

    int parent[no_vertices];
    for (int i = 0; i < no_vertices; i++)
    {
        parent[i] = i;
    }

    int count = 0, p = 0, sum = 0;
    int result[no_vertices][no_vertices];
    int u, v, i, j, k;
    while (count != no_vertices - 1)
    {
        u = e[p].u;
        v = e[p].v;
        i = find(u, parent);
        j = find(v, parent);
        if (i != j)
        {
            count++;
            result[k][0] = u;
            result[k][1] = v;
            k++;
            sum += e[p].cost;
            union_ij(i, j, parent);
        }
        p++;
    }

    if (count == no_vertices - 1)
    {
        printf("Spanning tree exists\n");
        printf("The spanning tree is as follows:\n");
        for (i = 0; i < no_vertices - 1; i++)
        {
            printf("%d  %d\t", result[i][0], result[i][1]);
        }
        printf("\nThe cost of the spanning tree is %d\n", sum);
    }
    else
    {
        printf("\n spanning tree does not exist");
    }
}

int main()
{
    int no_vertices, no_edges;
    printf("Enter the number of vertices : ");
    scanf("%d", &no_vertices);

    printf("Enter the number of edges : ");
    scanf("%d", &no_edges);

    printf("Enter the edge list (u,v,cost) : \n");
    edge e[no_edges];
    for (int i = 0; i < no_edges; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].cost);
    }

    clock_t start = clock();
    kruskal(no_vertices, e, no_edges);
    clock_t end = clock();
    double clk = (end - start) / CLOCKS_PER_SEC;

    printf("The run time is %f\n", clk);

    return 0;
}


/* Sample input and output

Enter the number of vertices : 6
Enter the number of edges : 10
Enter the edge list (u,v,cost) : 
0 1 3
1 2 1
2 3 6
3 4 8
4 0 6
0 5 5
1 5 4
2 5 4
3 5 5
4 5 2 
Spanning tree exists
The spanning tree is as follows:
1  2    4  5    0  1    1  5    3  5
The cost of the spanning tree is 15
The run time is 0.000000

*/