#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*head == NULL || (*head)->exponent < exponent) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->exponent >= exponent) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);
        if (head->next != NULL && head->next->coefficient > 0) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertNode(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertNode(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
           
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                insertNode(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertNode(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

void readPolynomial(struct Node **poly) {
    int terms, coefficient, exponent;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertNode(poly, coefficient, exponent);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    printf("Enter the first polynomial:\n");
    readPolynomial(&poly1);
    
    printf("Enter the second polynomial:\n");
    readPolynomial(&poly2);

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    struct Node* result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}

