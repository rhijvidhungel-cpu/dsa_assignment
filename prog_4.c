#include <stdio.h>
#include <stdlib.h>

// Define structure for doubly linked list node
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Function to insert a node after a given node
void insertAfterNode(Node* target, int val) {
    if (target == NULL) {
        printf("Target node is NULL\n");
        return;
    }

    Node* newNode = createNode(val);
    newNode->next = target->next;
    newNode->prev = target;

    if (target->next != NULL)
        target->next->prev = newNode;

    target->next = newNode;
}

// Function to delete a specific node
void deleteSpecificNode(Node** headRef, Node* delNode) {
    if (*headRef == NULL || delNode == NULL)
        return;

    if (*headRef == delNode)
        *headRef = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Main function to demonstrate the doubly linked list
int main() {
    // Create nodes
    Node* start = createNode(5);
    Node* nodeB = createNode(10);
    Node* nodeC = createNode(15);
    Node* nodeD = createNode(20);

    // Initial linking
    start->next = nodeB;
    nodeB->prev = start;

    nodeB->next = nodeC;
    nodeC->prev = nodeB;

    nodeC->next = nodeD;
    nodeD->prev = nodeC;

    printf("Initial Doubly Linked List:\n");
    displayList(start);

    // Insert after nodeB
    insertAfterNode(nodeB, 12);
    printf("\nAfter inserting 12 after 10:\n");
    displayList(start);

    // Delete nodeC
    deleteSpecificNode(&start, nodeC);
    printf("\nAfter deleting node with value 15:\n");
    displayList(start);

    return 0;
}
