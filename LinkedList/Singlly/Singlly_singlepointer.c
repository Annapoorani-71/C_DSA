#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;
node* head = NULL;

// Function to insert at the beginning of the list
void insertAtBeginning(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end of the list
void insertAtEnd(int val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = val;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert at specific position (1-based index)
void insertAtSpecificPosition(int val, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = val;
    
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        node* current = head;
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


// Function to delete at the beginning of the list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    node* temp = head;
    head = head->next;
    free(temp);
}


// Function to delete at the end of the list
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    if (head->next == NULL) {
        // Only one node in the list
        free(head);
        head = NULL;
        return;
    }
    
    node* current = head;
    node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    free(current);
}


// Function to delete at specific position (1-based index)
void deleteAtSpecificPosition(int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    
    node* temp;
    if (position == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }
    
    node* current = head;
    int currentPosition = 1;
    node* prev = NULL;
    
    while (currentPosition < position && current != NULL) {
        prev = current;
        current = current->next;
        currentPosition++;
    }
    
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    prev->next = current->next;
    free(current);
}


// Function to perform Bubble Sort on the linked list
void bubbleSort() {
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one element
        return;
    }
    
    int swapped;
    node* ptr1;
    node* lptr = NULL;
    
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of adjacent nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}







// Function to display the linked list
void display() {
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int search(int val) {
    node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == val)
            return position;
        current = current->next;
        position++;
    }
    
    return -1; // Element not found
}

int main() {
    insertAtBeginning(8);
    display();

    insertAtBeginning(15);
    display();

    insertAtBeginning(1);
    display();

    insertAtEnd(10);
    display();

     int element = 10;
    int position = search(element);
    
    if (position != -1) {
        printf("%d found at position %d\n", element, position);
    } else {
        printf("%d not found in the list\n", element);
    }

    insertAtSpecificPosition(5, 3);
    display();

    deleteAtBeginning();
    display();

    deleteAtEnd();
    display();

    deleteAtSpecificPosition(2);
    display();

    printf("Before sorting:\n");
    display();
    
    bubbleSort();
    
    printf("\nAfter sorting:\n");
    display();

    return 0;
}
