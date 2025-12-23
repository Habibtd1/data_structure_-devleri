#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

//Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

 //Insert at beginning
 void insertAtBeginning(struct Node** head, int data) {
   struct Node* newNode = createNode(data);
   newNode->next = *head;
   *head = newNode;
}

//Insert at end
void insertAtEnd(struct Node** head,int data,int position){
struct Node* newNode = createNode(data);
if(*head == NULL) {
   *head = newNode;
   return;
}
   struct Node* temp = *head;
   while (temp->next != NULL)
        temp = temp->next;
        temp->next = newNode;
 }


//Insert at position 
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
    insertAtBeginning(head, data);
    return;
}
    struct Node* temp = *head;
    for(int i = 1; i < position - 1 && temp != NULL; i++)
    temp = temp ->next;
    
    if(temp == NULL)return;
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

//Delete a node
void deleteNode(struct Node** head, int key) {
      struct Node* temp = *head;
      struct Node* prev = NULL;

      if(temp != NULL && temp->data == key) {
      *head = temp->next;
      free(temp);
      return;
   }
    
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
    
    if (temp == NULL) return;

    prev->next = temp->next;
      free(temp);
    }

//Traversal 
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp ->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 15, 3);
    
    printf("Linked List:\n");
    traverse(head);
     
    deleteNode(&head, 10);
    printf("After deletion:\n");
    traverse(head);

    return 0;

}