#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int d)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node *node) // 2 leftptr, rightptr
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Breadth-First Search (Level-order Traversal using Queue)
void bfs(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *queue[100]; // Create a simple queue (array-based)
    int front = 0, rear = 0;

    queue[rear++] = root; // Enqueue root

    while (front < rear)
    {
        struct Node *current = queue[front++]; // Dequeue node
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left; // Enqueue left child
        if (current->right != NULL)
            queue[rear++] = current->right; // Enqueue right child
    }
}

struct Node *deleteNode(struct Node *root, int val)
{
    if (root == NULL)
        return NULL;

    // Use a queue to perform BFS
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    struct Node *target = NULL;

    // Find the target node
    while (front < rear)
    {
        struct Node *curr = queue[front++];

        if (curr->data == val)
        {
            target = curr;
            break;
        }
        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
    if (target == NULL)
        return root;

    // Find the deepest rightmost node and its parent
    struct Node *lastNode = NULL;
    struct Node *lastParent = NULL;
    struct Node *queue1[100];
    int front1 = 0, rear1 = 0;
    queue1[rear1++] = root;
    struct Node *parents[100];
    parents[rear1 - 1] = NULL;

    while (front1 < rear1)
    {
        struct Node *curr = queue1[front1];
        struct Node *parent = parents[front1++];

        lastNode = curr;
        lastParent = parent;

        if (curr->left)
        {
            queue1[rear1] = curr->left;
            parents[rear1++] = curr;
        }
        if (curr->right)
        {
            queue1[rear1] = curr->right;
            parents[rear1++] = curr;
        }
    }

    target->data = lastNode->data;

    if (lastParent)
    {
        if (lastParent->left == lastNode)
            lastParent->left = NULL;
        else
            lastParent->right = NULL;
        free(lastNode);
    }
    else
    {
        free(lastNode);
        return NULL;
    }

    return root;
}

void inorderIterative(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1)
    {
        // Traverse the left subtree
        while (current != NULL)
        {
            stack[++top] = current; // Push node to stack
            current = current->left;
        }

        // Visit the node at the top of the stack
        current = stack[top--]; // Pop from stack
        printf("%d ", current->data);

        // Traverse the right subtree
        current = current->right;
    }
}

void updateNode(struct Node *root, int oldValue, int newValue)
{
    if (root == NULL)
        return;

    if (root->data == oldValue)
    {
        root->data = newValue;
        printf("\nUpdated node with value %d to %d", oldValue, newValue);
        return;
    }

    updateNode(root->left, oldValue, newValue);
    updateNode(root->right, oldValue, newValue);
}

int main()
{
    // Initialize the root node to NULL
    struct Node *root = NULL;

    // Create and allocate memory for tree nodes
    root = createNode(2);
    struct Node *secondNode = createNode(3);
    struct Node *thirdNode = createNode(4);
    struct Node *fourthNode = createNode(5);
    struct Node *fifthNode = createNode(6);

    // Manual insertion (create the tree structure)
    root->left = secondNode;
    root->right = thirdNode;
    secondNode->left = fourthNode;
    secondNode->right = fifthNode;

    // Perform DFS Traversals
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    // Perform BFS Traversal
    printf("BFS (Level-order) Traversal: ");
    bfs(root);
    printf("\n");

    // Perform Iterative Inorder Traversal
    printf("Iterative Inorder Traversal: ");
    inorderIterative(root);
    printf("\n");

    // Update a node
    updateNode(root, 2, 200);
    printf("\nThe bfs is: ");
    bfs(root);

    // Clean up and delete nodes
    deleteNode(root, 200);
    printf("\n bfs Traversal after removing 200: ");
    bfs(root);
    printf("\n");

    return 0;
}
