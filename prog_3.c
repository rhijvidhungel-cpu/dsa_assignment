#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to reverse traverse the linked list
void reverseTraversal(Node* head) {
    if (head == NULL)
        return;

    reverseTraversal(head->next); // recursive call to next node
    printf("%d ", head->data);   // print after recursive call
}

// Function to display linked list normally
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate reverse traversal
int main() {
    Node* head = NULL;

    // Insert nodes
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    // Display normal list
    printf("Original Linked List: ");
    displayList(head);

    // Display list in reverse
    printf("Reverse Traversal: ");
    reverseTraversal(head);
    printf("\n");

    return 0;
}
