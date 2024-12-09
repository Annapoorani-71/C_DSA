#include <stdio.h>
#include <stdbool.h>

#define MAX_V 5 // Number of vertices

int graph[MAX_V][MAX_V]; // Adjacency matrix

// Stack structure for DFS
struct Stack
{
    int top;
    int items[MAX_V];
};

// Initialize the stack
void initStack(struct Stack *s)
{
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack *s, int v)
{
    s->items[++(s->top)] = v;
}

// Pop an element from the stack
int pop(struct Stack *s)
{
    return s->items[(s->top)--];
}

// DFS using an explicit stack
void dfsMatrix(int start, int vertices)
{
    bool visited[MAX_V] = {false};
    struct Stack stack;
    initStack(&stack);

    push(&stack, start);
    printf("DFS Traversal: ");

    while (!isEmpty(&stack))
    {
        int current = pop(&stack);

        if (!visited[current])
        {
            visited[current] = true;
            printf("%d ", current);

            // Push adjacent unvisited vertices to the stack
            for (int i = vertices - 1; i >= 0; i--)
            {
                if (graph[current][i] == 1 && !visited[i])
                {
                    push(&stack, i);
                }
            }
        }
    }
    printf("\n");
}

// Add edge to the adjacency matrix
void addEdgeMatrix(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1; // Undirected graph
}

int main()
{
    // Initialize the graph (adjacency matrix)
    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++)
            graph[i][j] = 0;

    // Add edges
    addEdgeMatrix(0, 1);
    addEdgeMatrix(0, 2);
    addEdgeMatrix(1, 3);
    addEdgeMatrix(2, 4);
    addEdgeMatrix(3, 4);

    // Perform DFS traversal
    dfsMatrix(0, MAX_V);

    return 0;
}
