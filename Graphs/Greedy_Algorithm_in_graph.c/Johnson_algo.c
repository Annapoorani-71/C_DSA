// C program to implement Johnson Algorithm
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define INF 99999
#define V 4

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[][V])
{
    printf("Following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Solves the all-pairs shortest path problem using
// Floyd-Warshall algorithm
void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    // Initialize the solution matrix same as input graph matrix.
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist);
}

// Driver program to test above function
int main()
{
    /* Let us create the following weighted graph
             10
        (0)------->(3)
         |         /|\
        5|          |
         |          | 1
        \|/         |
        (1)------->(2)
            3       */
    int graph[V][V] = {{0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};

    // Print the solution
    floydWarshall(graph);
    return 0;
}
