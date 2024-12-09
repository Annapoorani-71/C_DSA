#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 5 // Number of vertices

// Graph structure for adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    struct Node *adjLists[MAX_V]; // Array of adjacency lists
};

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

// Create a new node
struct Node *createNode(int v)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph *createGraph()
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_V; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge to the adjacency list
void addEdgeList(struct Graph *graph, int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

// DFS using an explicit stack
void dfsList(struct Graph *graph, int start)
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

            struct Node *adj = graph->adjLists[current];
            while (adj)
            {
                if (!visited[adj->vertex])
                {
                    push(&stack, adj->vertex);
                }
                adj = adj->next;
            }
        }
    }
    printf("\n");
}

int main()
{
    // Create a graph
    struct Graph *graph = createGraph();

    // Add edges
    addEdgeList(graph, 0, 1);
    addEdgeList(graph, 0, 2);
    addEdgeList(graph, 1, 3);
    addEdgeList(graph, 2, 4);
    addEdgeList(graph, 3, 4);

    // Perform DFS traversal
    dfsList(graph, 0);

    return 0;
}
