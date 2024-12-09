#include <stdio.h>
#include <stdbool.h>

#define MAX_V 10 // Set max vertices for dynamic vertex management

int mat[MAX_V][MAX_V];    // Adjacency matrix
int current_vertices = 0; // Track the current number of vertices

// Function to add a vertex to the graph
void addVertex()
{
    if (current_vertices >= MAX_V)
    {
        printf("Cannot add more vertices.\n");
        return;
    }

    current_vertices++;
    printf("Vertex %d added successfully.\n", current_vertices - 1);
}

// Function to remove a vertex from the graph
void removeVertex(int v)
{
    if (v >= current_vertices)
    {
        printf("Vertex doesn't exist.\n");
        return;
    }

    // Shift rows up
    for (int i = v; i < current_vertices - 1; i++)
    {
        for (int j = 0; j < current_vertices; j++)
        {
            mat[i][j] = mat[i + 1][j];
        }
    }

    // Shift columns left
    for (int i = 0; i < current_vertices - 1; i++)
    {
        for (int j = v; j < current_vertices - 1; j++)
        {
            mat[i][j] = mat[i][j + 1];
        }
    }

    current_vertices--;
    printf("Vertex %d removed successfully.\n", v);
}

// Function to add an edge (directed)
void addEdge(int from, int to)
{
    if (from >= current_vertices || to >= current_vertices)
    {
        printf("Invalid vertices.\n");
        return;
    }
    mat[from][to] = 1; // Directed graph: edge from -> to
    printf("Directed edge added from %d to %d.\n", from, to);
}

// Function to remove an edge (directed)
void removeEdge(int from, int to)
{
    if (from >= current_vertices || to >= current_vertices)
    {
        printf("Invalid vertices.\n");
        return;
    }
    mat[from][to] = 0; // Directed graph: remove edge from -> to
    printf("Directed edge removed from %d to %d.\n", from, to);
}

// Function to display the adjacency matrix
void displayMatrix()
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < current_vertices; i++)
    {
        for (int j = 0; j < current_vertices; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// BFS Traversal
void bfs(int start)
{
    bool visited[MAX_V] = {false};
    int queue[MAX_V], front = 0, rear = 0;

    printf("BFS Traversal: ");
    visited[start] = true;
    queue[rear++] = start;

    while (front != rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < current_vertices; i++)
        {
            if (mat[current][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS Traversal
void dfsUtil(int v, bool visited[])
{
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < current_vertices; i++)
    {
        if (mat[v][i] == 1 && !visited[i])
        {
            dfsUtil(i, visited);
        }
    }
}

void dfs(int start)
{
    bool visited[MAX_V] = {false};
    printf("DFS Traversal: ");
    dfsUtil(start, visited);
    printf("\n");
}

// Function to search for an edge or vertex
void searchEntity(int v)
{
    if (v >= current_vertices)
    {
        printf("Vertex doesn't exist.\n");
        return;
    }

    printf("Vertex %d exists.\n", v);
}

int main()
{
    // Initialize the adjacency matrix
    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++)
            mat[i][j] = 0;

    // Add vertices
    addVertex(); // 0
    addVertex(); // 1
    addVertex(); // 2
    addVertex(); // 3

    // Add edges (directed)
    addEdge(0, 1); // Edge from 0 to 1
    addEdge(1, 2); // Edge from 1 to 2
    addEdge(2, 3); // Edge from 2 to 3
    addEdge(3, 1); // Edge from 3 to 1 (cycle)

    // Display the graph
    displayMatrix();

    // Traversals
    bfs(0); // Start BFS from vertex 0
    dfs(0); // Start DFS from vertex 0

    // Search for a vertex
    searchEntity(2); // Check if vertex 2 exists

    // Remove a vertex and edge
    removeEdge(0, 1);
    displayMatrix();

    removeVertex(1);
    displayMatrix();

    return 0;
}
