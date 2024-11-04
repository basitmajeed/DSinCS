#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createLinkedList();
void insertAtEnd(int data);
void updateNode(int index, int newData);
void deleteNode(int position);
void searchNode(int data);
void displayList();
void freeList();

int main() {
    int choice, data, index, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at End\n");
        printf("3. Update Node\n");
        printf("4. Delete Node\n");
        printf("5. Search Node\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createLinkedList();
                break;
            case 2:
                if (head == NULL) {
                    printf("Create a linked list first.\n");
                } else {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insertAtEnd(data);
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("Create a linked list first.\n");
                } else {
                    printf("Enter index to update: ");
                    scanf("%d", &index);
                    printf("Enter new data: ");
                    scanf("%d", &data);
                    updateNode(index, data);
                }
                break;
            case 4:
                if (head == NULL) {
                    printf("Create a linked list first.\n");
                } else {
                    printf("Enter position to delete (0 for beginning, -1 for last): ");
                    scanf("%d", &position);
                    deleteNode(position);
                }
                break;
            case 5:
                if (head == NULL) {
                    printf("Create a linked list first.\n");
                } else {
                    printf("Enter data to search: ");
                    scanf("%d", &data);
                    searchNode(data);
                }
                break;
            case 6:
                displayList();
                break;
            case 7:
                freeList();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void createLinkedList() {
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
    printf("Linked list created successfully.\n");
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end of the list.\n", data);
}

void updateNode(int index, int newData) {
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL && count < index) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        temp->data = newData;
        printf("Node at index %d updated to %d.\n", index, newData);
    } else {
        printf("Index out of bounds.\n");
    }
}

void deleteNode(int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = head;

    if (position == 0) { 
        head = temp->next;
        free(temp);
        printf("Deleted the first node.\n");
        return;
    } else if (position == -1) { 
        struct Node *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
            free(temp);
            printf("Deleted the last node.\n");
        } else { 
            head = NULL;
            free(temp);
            printf("Deleted the only node in the list.\n");
        }
        return;
    } else {
        struct Node *prev = NULL;
        int count = 0;
        while (temp != NULL && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
            printf("Deleted node at position %d.\n", position);
        } else {
            printf("Position out of bounds.\n");
        }
    }
}

void searchNode(int data) {
    struct Node *temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Data %d found at index %d.\n", data, index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("Data %d not found in the list.\n", data);
}

void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList() {
    struct Node *current = head;
    struct Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    head = NULL;
    printf("Linked list freed.\n");
}