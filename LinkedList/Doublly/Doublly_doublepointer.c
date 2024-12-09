//DOUBLLY USING DOUBLE POINTER


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int newdata) {
    struct Node *newNode = createNode(newdata);
    if (newNode == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node **head, int newdata) {
    struct Node *newNode = createNode(newdata);
    if (newNode == NULL) {
        return;
    }
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void insertAtSpecificPosition(struct Node **head, int newdata, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    struct Node *newNode = createNode(newdata);
    if (newNode == NULL) {
        return;
    }
    
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
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
        newNode->prev = current;
        
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        
        current->next = newNode;
    }
}



void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }
    
    free(current);
}

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }
    
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    struct Node *current = *head;
    int currentPosition = 1;
    
    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }
    
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    free(current);
}

void displayForward(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayBackward(struct Node *head) {
    struct Node *current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
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


int main() {
    struct Node *head = NULL;
    
    // Insert at beginning
    insertAtBeginning(&head, 8);
    displayForward(head);
    
    // Insert at beginning again
    insertAtBeginning(&head, 5);
    displayForward(head);
    
    // Insert at end
    insertAtEnd(&head, 10);
    displayForward(head);
    
    // Insert at specific position
    insertAtSpecificPosition(&head, 7, 2); // Insert 7 at position 2 (after 5)
    displayForward(head);
    
    // Delete at beginning
    deleteAtBeginning(&head);
    displayForward(head);
    
    // Delete at end
    deleteAtEnd(&head);
    displayForward(head);
    
    // Delete at specific position
    deleteAtPosition(&head, 2); // Delete node at position 2
    displayForward(head);
    
    // Display list backward
    displayBackward(head);
    
    // Freeing allocated memory for the linked list
    freeList(head);

    return 0;
}