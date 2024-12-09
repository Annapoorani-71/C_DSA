#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum number of vertices (dynamic size)

// Function prototypes
void addVertex(int mat[MAX][MAX], int *n);
void removeVertex(int mat[MAX][MAX], int *n, int v);
void addEdge(int mat[MAX][MAX], int u, int v);
void removeEdge(int mat[MAX][MAX], int u, int v);
int searchVertex(int mat[MAX][MAX], int v, int n);
void BFS(int mat[MAX][MAX], int start, int n);
void DFS(int mat[MAX][MAX], int start, int n, int visited[]);

void displayMatrix(int mat[MAX][MAX], int n);

int main()
{
    int mat[MAX][MAX] = {0}; // Initial graph with no edges
    int n = 0;               // Number of vertices

    // Add vertices to the graph
    addVertex(mat, &n);
    addVertex(mat, &n);
    addVertex(mat, &n);
    addVertex(mat, &n);

    // Add edges to the graph
    addEdge(mat, 0, 1);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);
    addEdge(mat, 0, 3);

    printf("Adjacency Matrix after adding vertices and edges:\n");
    displayMatrix(mat, n);

    // Remove a vertex
    removeVertex(mat, &n, 2);
    printf("Adjacency Matrix after removing vertex 2:\n");
    displayMatrix(mat, n);

    // Remove an edge
    removeEdge(mat, 0, 1);
    printf("Adjacency Matrix after removing edge (0,1):\n");
    displayMatrix(mat, n);

    // Searching a vertex
    int found = searchVertex(mat, 3, n);
    printf("Vertex 3 %s found in the graph.\n", found ? "is" : "is not");

    // Traversal
    printf("BFS traversal starting from vertex 0:\n");
    BFS(mat, 0, n);

    int visited[MAX] = {0}; // Mark all vertices as unvisited for DFS
    printf("DFS traversal starting from vertex 0:\n");
    DFS(mat, 0, n, visited);

    return 0;
}

// Function to add a vertex to the graph
void addVertex(int mat[MAX][MAX], int *n)
{
    if (*n >= MAX)
    {
        printf("Vertex limit reached.\n");
        return;
    }
    (*n)++;
}

// Function to remove a vertex from the graph
void removeVertex(int mat[MAX][MAX], int *n, int v)
{
    if (v >= *n)
    {
        printf("Vertex %d does not exist.\n", v);
        return;
    }

    // Remove the vertex by shifting rows and columns
    for (int i = v; i < *n - 1; i++)
    {
        for (int j = 0; j < *n; j++)
            mat[i][j] = mat[i + 1][j];
    }
    for (int i = v; i < *n - 1; i++)
    {
        for (int j = 0; j < *n; j++)
            mat[j][i] = mat[j][i + 1];
    }
    (*n)--;
}

// Function to add an edge to the graph
void addEdge(int mat[MAX][MAX], int u, int v)
{
    if (u >= MAX || v >= MAX)
    {
        printf("Vertex does not exist.\n");
        return;
    }
    mat[u][v] = 1;
    mat[v][u] = 1; // Since the graph is undirected
}

// Function to remove an edge from the graph
void removeEdge(int mat[MAX][MAX], int u, int v)
{
    if (u >= MAX || v >= MAX)
    {
        printf("Vertex does not exist.\n");
        return;
    }
    mat[u][v] = 0;
    mat[v][u] = 0;
}

// Function to search a vertex in the graph
int searchVertex(int mat[MAX][MAX], int v, int n)
{
    return (v < n);
}

// Function to display the adjacency matrix
void displayMatrix(int mat[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Breadth-First Search (BFS)
void BFS(int mat[MAX][MAX], int start, int n)
{
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++)
        {
            if (mat[vertex][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Depth-First Search (DFS)
void DFS(int mat[MAX][MAX], int start, int n, int visited[])
{
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++)
    {
        if (mat[start][i] == 1 && !visited[i])
        {
            DFS(mat, i, n, visited);
        }
    }
}
