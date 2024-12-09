//SINGLY USING DOUBLE POINTER



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int newdata) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = newdata;
    newNode->next = *head; 
    
    *head = newNode; 
}


void insertAtEnd(struct Node **head, int newdata) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = newdata;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}



void insertAtSpecificPosition(struct Node **head, int newdata, int position) 
{

    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = newdata;
    
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *current = *head;
        int currentPosition = 1;
        
        while (currentPosition < position - 1 && current != NULL) {
            current = current->next;
            currentPosition++;
        }
        
        if (current == NULL) {
            printf("Position out of range\n");
            free(newNode);
            return;
        }
        
        newNode->next = current->next;
        current->next = newNode;
    }
}


void display(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        // If there's only one node in the list
        free(*head);
        *head = NULL;
        return;
    }
    
    struct Node *current = *head;
    struct Node *previous = NULL;
    
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    
    free(current);
    previous->next = NULL;
}



void deleteAtSpecificPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    struct Node *current = *head;
    struct Node *previous = NULL;
    int currentPosition = 1;
    
    // Traverse to the node at the specified position
    while (currentPosition < position && current != NULL) {
        previous = current;
        current = current->next;
        currentPosition++;
    }
    
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    // Remove the node at the specified position
    if (previous == NULL) {
        // If deleting the first node
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
}



int main() {
    struct Node *head = NULL;
    
    // Insert at beginning
    insertAtBeginning(&head, 8);
    display(head);
    
    // Insert at beginning again
    insertAtBeginning(&head, 5);
    display(head);
    
    // Insert at end
    insertAtEnd(&head, 10);
    display(head);
    
    // Insert at specific position
    insertAtSpecificPosition(&head, 7, 2); // Insert 7 at position 2 (after 5)
    display(head);


     // Delete at beginning
    deleteAtBeginning(&head);
    display(head);
    
    // Delete at end
    deleteAtEnd(&head);
    display(head);
    
    // Delete at specific position
    deleteAtSpecificPosition(&head, 2); // Delete node at position 2
    display(head);
    
    
    // Freeing allocated memory for the linked list
    freeList(head);

    return 0;
}
