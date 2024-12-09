#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

    typedef struct Node node;
    node* head =NULL;
    node* tail =NULL;

void insertAtBeginning(int val){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=val;
    if(newNode==NULL){
      printf("Out of Memory");
      return;
    }
    newNode->prev=NULL;
    newNode->next=head;
    if(head==NULL){
        newNode->next=NULL;
        tail=newNode;
    }
    else{
        head->prev=newNode;
    }
     head=newNode;
}

void display(){
    if(head==NULL){
        printf("List is Empty");
    }
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void displayReverse(){
    if(tail==NULL){
        printf("List is Empty");
    }
    node* temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void insertAtPos(int pos, int val){
    if(pos==0){
        insertAtBeginning(val);
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
  if(newNode==NULL)
  {
      printf("Out of Memory");
      return;
  }
    newNode->data= val;
    node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("Invalid position");
            return;
        }
    }
    newNode->next=temp->next;
    if(temp->next==NULL)
        tail=newNode;
    else
        temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}

void deleteAtPos(int pos)
{
    node* temp =head;
    node* prev;
    if(head==NULL)
    {
        printf("List is Empty");
        return;
    }
    if(pos==0){
        head = head ->next;
        printf("Deleted %d\n", temp->data);
        head->prev=NULL;
        free(temp);
        return;
    }
     for(int i=0; i<pos; i++)
    {
        prev = temp;
        temp =temp ->next;
        if(temp==NULL)
      {
        printf("Invalid Position");
        return;
      }
    }
    prev ->next = temp-> next;
    if(temp->next==NULL)
        tail=prev;
    else
        temp->next->prev=prev;
    printf("Deleted %d\n", temp->data);
    free(temp);
}


void deleteAtEnd() {
    if (tail == NULL) {
        printf("List is Empty. Cannot delete.\n");
        return;
    }
    node* temp = tail;
    if (head == tail) {
        // Only one node in the list
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted %d\n", temp->data);
    free(temp);
}

void deleteAtSpecificPosition(int pos) {
    if (head == NULL) {
        printf("List is Empty. Cannot delete.\n");
        return;
    }
    node* temp = head;
    node* prev = NULL;
    if (pos == 0) {
        // Delete at the beginning
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        printf("Deleted %d\n", temp->data);
        free(temp);
        return;
    }
    for (int i = 0; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            printf("Invalid Position\n");
            return;
        }
    }
    prev->next = temp->next;
    if (temp->next == NULL) {
        tail = prev;
    } else {
        temp->next->prev = prev;
    }
    printf("Deleted %d\n", temp->data);
    free(temp);
}








// Function to perform linear search for an element in the list
int linearSearch(int key) {
    if (head == NULL) {
        printf("List is Empty\n");
        return -1;
    }
    
    node* temp = head;
    int position = 1;
    
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    
    printf("%d not found in the list\n", key);
    return -1;
}


// Function to perform Bubble Sort on the linked list
// void bubbleSort() {
//     if (head == NULL || head->next == NULL) {
//         // List is empty or has only one element
//         return;
//     }
    
//     int swapped;
//     node* ptr1;
//     node* lptr = NULL;
    
//     do {
//         swapped = 0;
//         ptr1 = head;
        
//         while (ptr1->next != lptr) {
//             if (ptr1->data > ptr1->next->data) {
//                 // Swap data of adjacent nodes
//                 int temp = ptr1->data;
//                 ptr1->data = ptr1->next->data;
//                 ptr1->next->data = temp;
//                 swapped = 1;
//             }
//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//     } while (swapped);
// }



void selectionSort() {
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one element
        return;
    }
    
    node* current = head;
    
    while (current != tail) {
        node* temp = current->next;
        node* min = current;
        
        while (temp != NULL && temp != head) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }
        
        // Swap data of current and min if they are different
        if (min != current) {
            int tempData = current->data;
            current->data = min->data;
            min->data = tempData;
        }
        
        current = current->next;
    }
}














int main()
{
   insertAtBeginning(3);
   display();

   insertAtBeginning(4);
   display();

   insertAtBeginning(7);
   display();

   insertAtBeginning(9);
   display();

   insertAtPos(3,10);
   display();

   deleteAtPos(4);
   display();

   displayReverse();


     // Example of linear search
    int key = 4;
    int position = linearSearch(key);
    if (position != -1) {
        printf("%d found at position %d\n", key, position);
    }
    

    printf("\nBefore sorting:\n");
    display();
    // Sorting using Bubble Sort
    selectionSort();
    printf("\nAfter sorting:\n");
    display();


      deleteAtEnd();
    printf("\nAfter deleting at end:\n");
    display();

    // Example of deletion at specific position
    deleteAtSpecificPosition(2);
    printf("\nAfter deleting at specific position:\n");
    display();


   return 0;

}