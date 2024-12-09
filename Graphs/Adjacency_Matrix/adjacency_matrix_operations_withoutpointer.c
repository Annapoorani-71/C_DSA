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

// Function to add an edge
void addEdge(int i, int j)
{
    if (i >= current_vertices || j >= current_vertices)
    {
        printf("Invalid vertices.\n");
        return;
    }
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
    printf("Edge added between %d and %d.\n", i, j);
}

// Function to remove an edge
void removeEdge(int i, int j)
{
    if (i >= current_vertices || j >= current_vertices)
    {
        printf("Invalid vertices.\n");
        return;
    }
    mat[i][j] = 0;
    mat[j][i] = 0; // Since the graph is undirected
    printf("Edge removed between %d and %d.\n", i, j);
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

// BFS Traversal using queue
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

// DFS Traversal using explicit stack
void dfs(int start)
{
    bool visited[MAX_V] = {false};
    int stack[MAX_V], top = -1; // Stack implementation

    printf("DFS Traversal: ");
    stack[++top] = start; // Push the start vertex

    while (top != -1) // While the stack is not empty
    {
        int current = stack[top--]; // Pop the top element

        if (!visited[current])
        {
            printf("%d ", current);
            visited[current] = true;
        }

        // Push adjacent unvisited vertices onto the stack
        for (int i = 0; i < current_vertices; i++)
        {
            if (mat[current][i] == 1 && !visited[i])
            {
                stack[++top] = i; // Push unvisited neighbor
            }
        }
    }
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

    // Add edges
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);

    // Display the graph
    displayMatrix();

    // Traversals
    bfs(0); // Start BFS from vertex 0
    dfs(0); // Start DFS from vertex 0 using explicit stack

    // Search for a vertex
    searchEntity(2); // Check if vertex 2 exists

    // Remove a vertex and edge
    removeEdge(0, 1);
    displayMatrix();

    removeVertex(1);
    displayMatrix();

    return 0;
}
