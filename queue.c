#include <stdio.h>
#define SIZE 100
int queue[SIZE];
int front=-1,rear=-1;
void enqueue(int value) {
    if (rear==SIZE-1)
        printf("Queue is full!\n");
    else {
        if (front==-1)
        front=0;
        queue[++rear]=value;
        printf("%d enqueued to queue\n", value);
    }
}
void dequeue(){
    if (front==-1||front>rear)
        printf("Queue is empty\n");
    else
        printf("%d dequeued from queue\n", queue[front++]);
}
void peek() {
    if (front==-1||front > rear)
        printf("Queue is empty\n");
    else
        printf("Front element is:%d\n", queue[front]);
}
void display() {
    if (front==-1||front>rear)
        printf("Queue is empty!\n");
    else {
        printf("Queue elements:");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
int choice, val;
while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}