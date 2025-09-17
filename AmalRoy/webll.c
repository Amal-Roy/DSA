#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_SIZE 100

typedef struct Node {
    char url[URL_SIZE];
    struct Node* prev;
    struct Node* next;
} Node;

int main() {
    Node* current = NULL;
    int choice;
    char url[URL_SIZE];

    while (1) {
        printf("\nBrowser Menu:\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter URL to visit: ");
                scanf("%s", url);
                
                Node* newNode = (Node*)malloc(sizeof(Node));
                if (!newNode) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                strncpy(newNode->url, url, URL_SIZE - 1);
                newNode->url[URL_SIZE - 1] = '\0';
                newNode->next = NULL;

                if (current == NULL) {
                    
                    newNode->prev = NULL;
                    current = newNode;
                } else {
               
                    Node* forward = current->next;
                    while (forward != NULL) {
                        Node* toDelete = forward;
                        forward = forward->next;
                        free(toDelete);
                    }
                    current->next = newNode;
                    newNode->prev = current;
                    current = newNode;
                }

                printf("Visited: %s\n", current->url);
                break;

            case 2: 
                if (current == NULL || current->prev == NULL) {
                    printf("Cannot go back\n");
                } else {
                    current = current->prev;
                    printf("Moved back to: %s\n", current->url);
                }
                break;

            case 3:
                if (current == NULL || current->next == NULL) {
                    printf("Cannot go forward\n");
                } else {
                    current = current->next;
                    printf("Moved forward to: %s\n", current->url);
                }
                break;

            case 4: 
                if (current == NULL) {
                    printf("No page visited yet\n");
                } else {
                    printf("Current Page: %s\n", current->url);
                }
                break;

            case 5:
                printf("Exiting Browser Simulation\n");
               
                while (current != NULL && current->prev != NULL) {
                    current = current->prev;
                }
                while (current != NULL) {
                    Node* toDelete = current;
                    current = current->next;
                    free(toDelete);
                }
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}

