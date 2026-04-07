#include <stdio.h>

int stack[100], top = -1, n;

// Push operation
void push() {
    int item;
    if (top == n - 1) {
        printf("Stack is full\n");
    } else {
        printf("Enter item: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("%d is popped\n", stack[top]);
        top--;
    }
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Enter stack size: ");
    scanf("%d", &n);

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
