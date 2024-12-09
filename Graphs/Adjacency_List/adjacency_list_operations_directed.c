#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices
#define MAX_V 100 // Adjust as needed

// Node structure for adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Graph structure
struct Graph
{
    int numVertices;
    struct Node **adjLists;
};

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists
    graph->adjLists = malloc(vertices * sizeof(struct Node *));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Function to create a new adjacency list node
struct Node *createNode(int vertex)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add a vertex
void addVertex(struct Graph *graph)
{
    graph->numVertices++;
    graph->adjLists = realloc(graph->adjLists, graph->numVertices * sizeof(struct Node *));
    graph->adjLists[graph->numVertices - 1] = NULL; // Initialize new vertex as empty list
    printf("Vertex %d added successfully.\n", graph->numVertices - 1);
}

// Function to remove a vertex
void removeVertex(struct Graph *graph, int v)
{
    if (v >= graph->numVertices)
    {
        printf("Vertex doesn't exist.\n");
        return;
    }

    // Remove all edges from the vertex to be removed
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *current = graph->adjLists[i];
        struct Node *prev = NULL;

        while (current != NULL)
        {
            if (current->vertex == v)
            {
                if (prev == NULL)
                {
                    graph->adjLists[i] = current->next; // Remove first node
                }
                else
                {
                    prev->next = current->next; // Bypass the node
                }
                free(current);
                break; // Remove only one occurrence
            }
            prev = current;
            current = current->next;
        }
    }

    // Shift adjacency lists left
    for (int i = v; i < graph->numVertices - 1; i++)
    {
        graph->adjLists[i] = graph->adjLists[i + 1];
    }

    graph->numVertices--;
    graph->adjLists = realloc(graph->adjLists, graph->numVertices * sizeof(struct Node *));
    printf("Vertex %d removed successfully.\n", v);
}

// Function to add an edge
void addEdge(struct Graph *graph, int from, int to)
{
    if (from >= graph->numVertices || to >= graph->numVertices)
    {
        printf("Invalid vertices.\n");
        return;
    }

    struct Node *newNode = createNode(to);
    newNode->next = graph->adjLists[from];
    graph->adjLists[from] = newNode; // Add to the adjacency list of the 'from' vertex
    printf("Directed edge added from %d to %d.\n", from, to);
}

// Function to remove an edge
void removeEdge(struct Graph *graph, int from, int to)
{
    if (from >= graph->numVertices || to >= graph->numVertices)
    {
        printf("Invalid vertices.\n");
        return;
    }

    struct Node *current = graph->adjLists[from];
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->vertex == to)
        {
            if (prev == NULL)
            {
                graph->adjLists[from] = current->next; // Remove first node
            }
            else
            {
                prev->next = current->next; // Bypass the node
            }
            free(current);
            printf("Directed edge removed from %d to %d.\n", from, to);
            return; // Edge removed
        }
        prev = current;
        current = current->next;
    }

    printf("Edge from %d to %d does not exist.\n", from, to);
}

// Function to display the adjacency list
void displayGraph(struct Graph *graph)
{
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *current = graph->adjLists[i];
        printf("Vertex %d:", i);
        while (current)
        {
            printf(" -> %d", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// BFS Traversal
void bfs(struct Graph *graph, int start)
{
    bool visited[graph->numVertices]; // Array to keep track of visited vertices
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = false; // Initialize all vertices as unvisited
    }

    int queue[MAX_V], front = 0, rear = 0;

    printf("BFS Traversal: ");
    visited[start] = true;
    queue[rear++] = start;

    while (front != rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        struct Node *adjList = graph->adjLists[current];
        while (adjList != NULL)
        {
            int adjVertex = adjList->vertex;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            adjList = adjList->next;
        }
    }
    printf("\n");
}

// DFS Utility function
void dfsUtil(struct Graph *graph, int v, bool visited[])
{
    visited[v] = true;
    printf("%d ", v);

    struct Node *adjList = graph->adjLists[v];
    while (adjList != NULL)
    {
        int adjVertex = adjList->vertex;
        if (!visited[adjVertex])
        {
            dfsUtil(graph, adjVertex, visited);
        }
        adjList = adjList->next;
    }
}

// DFS Traversal
void dfs(struct Graph *graph, int start)
{
    bool visited[graph->numVertices]; // Array to keep track of visited vertices
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = false; // Initialize all vertices as unvisited
    }
    printf("DFS Traversal: ");
    dfsUtil(graph, start, visited);
    printf("\n");
}

// Function to search for a vertex
void searchEntity(struct Graph *graph, int v)
{
    if (v >= graph->numVertices)
    {
        printf("Vertex doesn't exist.\n");
        return;
    }

    printf("Vertex %d exists.\n", v);
}

int main()
{
    struct Graph *graph = createGraph(4); // Create a graph with 4 vertices

    // Add edges (directed)
    addEdge(graph, 0, 1); // Edge from 0 to 1
    addEdge(graph, 0, 2); // Edge from 0 to 2
    addEdge(graph, 1, 2); // Edge from 1 to 2
    addEdge(graph, 2, 3); // Edge from 2 to 3
    addEdge(graph, 3, 1); // Edge from 3 to 1 (cycle)

    // Display the graph
    displayGraph(graph);

    // Traversals
    bfs(graph, 0); // Start BFS from vertex 0
    dfs(graph, 0); // Start DFS from vertex 0

    // Search for a vertex
    searchEntity(graph, 2); // Check if vertex 2 exists

    // Remove an edge and vertex
    removeEdge(graph, 0, 1);
    displayGraph(graph);

    removeVertex(graph, 1);
    displayGraph(graph);

    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *current = graph->adjLists[i];
        while (current)
        {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}
