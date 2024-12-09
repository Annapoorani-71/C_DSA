#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 4

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[], int prev[])
{
    printf("Vertex \t\t Distance from Source\t Path\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t\t %d\t\t\t", i, dist[i]);

        // Print the path from source to the vertex
        if (dist[i] != INT_MAX)
        {
            int j = i;
            printf("Path: ");
            while (j != -1)
            {
                printf("%d ", j);
                j = prev[j];
            }
        }
        printf("\n");
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    int prev[V]; // To store previous vertices in the path

    // Initialize distances and set previous vertices to -1
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        prev[i] = -1; // Initialize previous vertices
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u; // Update previous vertex
            }
        }
    }

    printSolution(dist, prev);
}

int main()
{
    int graph[V][V] = {
        {0, 1, 4, 0}, // Connections for vertex 0
        {1, 0, 0, 2}, // Connections for vertex 1
        {4, 0, 0, 3}, // Connections for vertex 2
        {0, 2, 3, 0}  // Connections for vertex 3
    };

    //    0  1  2  3
    // 0 [0, 1, 4, 0]   // Vertex 0 is connected to 1 (weight 1) and 2 (weight 4)
    // 1 [1, 0, 0, 2]   // Vertex 1 is connected to 0 (weight 1) and 3 (weight 2)
    // 2 [4, 0, 0, 3]   // Vertex 2 is connected to 0 (weight 4) and 3 (weight 3)
    // 3 [0, 2, 3, 0]   // Vertex 3 is connected to 1 (weight 2) and 2 (weight 3)

    dijkstra(graph, 0);

    return 0;
}
