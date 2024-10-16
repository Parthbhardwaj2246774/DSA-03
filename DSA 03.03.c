#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end\n", data);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Inserted %d at the end\n", data);
}

// Insert after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("Inserted %d after node with data %d\n", data, prevNode->data);
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Deleted node with data %d\n", key);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Node with data %d not found\n", key);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted node with data %d\n", key);
}

// Display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Create a linked list from an array of values
struct Node* createLinkedList(int arr[], int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = createNode(arr[i]);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    struct Node* head = NULL;

    // Creating a list from an array
    int arr[] = {10, 20, 30, 40, 50};
    head = createLinkedList(arr, 5);
    displayList(head);

    // Inserting elements
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 60);
    insertAfter(head->next->next, 25); // Insert after node with data 20

    displayList(head);

    // Deleting nodes
    deleteNode(&head, 25);
    deleteNode(&head, 10); // Delete the head node

    displayList(head);

    return 0;
}

