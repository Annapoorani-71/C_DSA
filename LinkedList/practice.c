#include<stdio.h>
#include<stdlib.h>

struct lnode{
    int data;
    struct lnode* prev;
    struct lnode* next;
};

    typedef struct lnode node;
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

int main()
{
   insertAtBeginning(3);
   insertAtBeginning(4);
   insertAtBeginning(7);
   insertAtBeginning(9);
   insertAtPos(3,10);
   deleteAtPos(4);
   display();
   displayReverse();
   return 0;

}