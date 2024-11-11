#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};



// Main function with menu-driven logic
int main() {
    struct Node* start = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete from the end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&start, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&start, data);
                break;
            case 3:
                deleteFromBeginning(&start);
                break;
            case 4:
                deleteFromEnd(&start);
                break;
            case 5:
                displayList(start);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


// Function to insert a node at the beginning
void insertAtBeginning(struct Node** start, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = data;
    newNode->next = *start;
    *start = newNode;
    printf("Node inserted at the beginning with data: %d\n", data);
}


// Function to insert a node at the end
void insertAtEnd(struct Node** start, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        struct Node* temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end with data: %d\n", data);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** start) {
    if (*start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *start;
    *start = (*start)->next;
    printf("Node deleted from the beginning with data: %d\n", temp->data);
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** start) {
    if (*start == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *start;
    if (temp->next == NULL) {
        printf("Node deleted from the end with data: %d\n", temp->data);
        free(temp);
        *start = NULL;
    } else {
        struct Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Node deleted from the end with data: %d\n", temp->data);
        free(temp);
    }
}

// Function to display the linked list
void displayList(struct Node* start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}