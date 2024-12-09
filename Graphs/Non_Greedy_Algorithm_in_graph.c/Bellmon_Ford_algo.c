#include <limits.h>
#include <stdio.h>

// Define the number of vertices in the graph
#define V 4
// Define infinity for large value
#define INF INT_MAX

void bellmanFord(int graph[][3], int vertices, int edges, int source)
{
    int distance[V];

    for (int i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[source] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < vertices - 1; i++)
    {
        // Traverse each edge in the graph
        for (int j = 0; j < edges; j++)
        {
            int u = graph[j][0];      // source vertex
            int v = graph[j][1];      // destination vertex
            int weight = graph[j][2]; // weight of the edge

            // If the distance to the source vertex is not infinite
            // and the new distance to the destination vertex is shorter
            if (distance[u] != INF && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    // Check for negative-weight cycles by trying to relax one more time
    for (int i = 0; i < edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (distance[u] != INF && distance[u] + weight < distance[v])
        {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print the final shortest distances from the source
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; i++)
    {
        if (distance[i] == INF)
            printf("%d \t\t INFINITY\n", i);
        else
            printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main()
{
    // Number of vertices and edges
    int vertices = V;
    int edges = 5;

    // Simplified 4x4 graph as an edge list:
    // Each row is {source, destination, weight}
    int graph[][3] = {
        {0, 1, 4},  // Edge from vertex 0 to 1 with weight 4
        {0, 2, 5},  // Edge from vertex 0 to 2 with weight 5
        {1, 2, -3}, // Edge from vertex 1 to 2 with weight -3
        {1, 3, 6},  // Edge from vertex 1 to 3 with weight 6
        {2, 3, 2}   // Edge from vertex 2 to 3 with weight 2
    };

    // Perform Bellman-Ford starting from vertex 0
    bellmanFord(graph, vertices, edges, 0);

    return 0;
}
