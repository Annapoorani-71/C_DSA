#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition of Node for Binary search tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node in heap
struct Node *GetNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
struct Node *Insert(struct Node *root, int data)
{
    if (root == NULL)
    { // empty tree
        root = GetNewNode(data);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    // else, insert in right subtree.
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

// To search an element in BST, returns true if element is found
bool Search(struct Node *root, int searchData)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == searchData)
    {
        return true;
    }
    else if (searchData <= root->data) // 7<=8
    {
        return Search(root->left, searchData);
    }
    else
    {
        return Search(root->right, searchData);
    }
}
// Function to find minimum in a tree.
struct Node *FindMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to search a delete a value from tree.
struct Node *Delete(struct Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data) // 8<8
        root->left = Delete(root->left, data);
    else if (data > root->data) // 8>8
        root->right = Delete(root->right, data);
    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        // case 3: 2 children
        else
        {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

// In-order traversal: Left, Root, Right
void InOrder(struct Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

// Pre-order traversal: Root, Left, Right
void PreOrder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

// Post-order traversal: Left, Right, Root
void PostOrder(struct Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node *root = NULL; // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root, 15); // 200
    root = Insert(root, 10); // 200
    root = Insert(root, 20); // 200
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int number;
    printf("Enter number be searched\n");
    scanf("%d", &number); // 7
    // If number is found, print "FOUND"
    if (Search(root, number) == true)
        printf("Found\n");
    else
        printf("Not Found\n");

    printf("Enter number be deleted\n");
    scanf("%d", &number);
    Delete(root, number);

    printf("In-order Traversal: ");
    InOrder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    PreOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    PostOrder(root);
    printf("\n");
}