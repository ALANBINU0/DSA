#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_LENGTH 100

typedef struct Node {
    char url[URL_LENGTH];
    struct Node* prev;
    struct Node* next;
} Node;

Node* current = NULL;
Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void visit(const char* url) {
    Node* newNode = createNode(url);

    if (current == NULL) {
        current = newNode;
    } else {
        Node* temp = current->next;
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }

        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    printf("Visited: %s\n", current->url);
}
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page to go back to.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No next page to go forward to.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}
void displayCurrent() {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}
void freeAll() {
    if (current == NULL) return;
    while (current->prev != NULL) {
        current = current->prev;
    }
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}
int main() {
    int choice;
    char url[URL_LENGTH];

    while (1) {
        printf("\nOptions:\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, URL_LENGTH, stdin);
                url[strcspn(url, "\n")] = '\0';  
                visit(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrent();
                break;
            case 5:
                freeAll();
                printf("Exiting browser.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

