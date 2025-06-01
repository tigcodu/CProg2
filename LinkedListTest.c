#include <stdio.h>
#include <stdlib.h>

struct Node {
    char value;
    struct Node *next;
};

int main() {

    struct Node *head, *temp, *current, *newNode;
    int pos;
    head = NULL;

    do {

    printf("Menu: 1 - Display, 2 - Insert, 3 - Delete, 4 - Exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            if (head == NULL) {
                printf("List is empty.\n");
            } else {
                current = head;
                printf("Linked List: ");
                while (current != NULL) {
                    printf("%c -> ", current->value);
                    current = current->next;
                }
                printf("NULL\n");
            }
            break;
        case 2:
            newNode = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            printf("Enter value to insert: ");
            scanf(" %c", &newNode->value);
            newNode->next = NULL;

            if (pos < 1) {
                printf("Invalid position. Insertion failed.\n");
                free(newNode);
                break;
            }
            else if (pos == 1) {
                newNode->next = head;
                head = newNode;
            } else {
                current = head;
                for (int i = 1; i < pos - 1 && current != NULL; i++) {
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Position out of bounds. Insertion failed.\n");
                    free(newNode);
                    break;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
            
            printf("Value '%c' inserted.\n", newNode->value);
            break;
        case 3:
            if (head == NULL) {
                printf("List is empty. Nothing to delete.\n");
            } else {
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                
                if (pos < 1) {
                    printf("Invalid position. Deletion failed.\n");
                    break;
                }
                
                if (pos == 1) {
                    temp = head;
                    head = head->next;
                    free(temp);
                    printf("First node deleted.\n");
                } else {
                    current = head;
                    for (int i = 1; i < pos - 1 && current != NULL; i++) {
                        current = current->next;
                    }
                    if (current == NULL || current->next == NULL) {
                        printf("Position out of bounds. Deletion failed.\n");
                        break;
                    }
                    temp = current->next;
                    current->next = temp->next;
                    free(temp);
                    printf("Node at position %d deleted.\n", pos);
                }
            }
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    } while (1);

    return 0;
}