#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL, *current;

void initializeList();
void display();
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtPosition(int, int);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromPosition(int);
void deleteByValue(int);

int main() {
    initializeList();
    int choice, data, pos;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2: 
                printf("1. Insert at Beginning\n");
                printf("2. Insert at End\n");
                printf("3. Insert at Position\n");
                printf("Enter the insert option: ");
                int insertChoice;
                scanf("%d", &insertChoice);
                
                switch (insertChoice) {
                    case 1:
                        printf("Enter value to insert: ");
                        scanf("%d", &data);
                        insertAtBeginning(data);
                        break;
                    case 2:
                        printf("Enter value to insert: ");
                        scanf("%d", &data);
                        insertAtEnd(data);
                        break;
                    case 3:
                        printf("Enter position to insert at: ");
                        scanf("%d", &pos);
                        printf("Enter value to insert: ");
                        scanf("%d", &data);
                        insertAtPosition(data, pos);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 3:
                printf("1. Delete from Beginning\n");
                printf("2. Delete from End\n");
                printf("3. Delete from Position\n");
                printf("4. Delete by Value\n");
                printf("Enter the delete option: ");
                int deleteChoice;
                scanf("%d", &deleteChoice);
                
                switch (deleteChoice) {
                    case 1:
                        deleteFromBeginning();
                        break;
                    case 2:
                        deleteFromEnd();
                        break;
                    case 3:
                        printf("Enter position to delete from: ");
                        scanf("%d", &pos);
                        deleteFromPosition(pos);
                        break;
                    case 4:
                        printf("Enter value to delete: ");
                        scanf("%d", &data);
                        deleteByValue(data);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 4:
                printf("Thank you for using the program..\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void initializeList() {
    struct Node *current;
    
    current = (struct Node*) malloc(sizeof(struct Node));
    current->data = 1;
    current->next = NULL;
    head = current;
    tail = current;
 
    current = (struct Node*) malloc(sizeof(struct Node));
    current->data = 2;
    current->next = NULL;
    tail->next = current;
    tail = current;
 
    current = (struct Node*) malloc(sizeof(struct Node));
    current->data = 3;
    current->next = NULL;
    tail->next = current;
    tail = current;
}

void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}


void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}


void deleteFromPosition(int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}


void deleteByValue(int value) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
}