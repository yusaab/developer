#include <stdio.h>
#define SIZE 30
int stack[SIZE], top = -1;
// Function prototypes
void push(int item);
int pop();
int peek();
void display();
int main() {
 int choice, value;
 do {
 printf("\nSelect an operation:\n");
 printf("1. Push Operation\n");
 printf("2. Pop Operation\n");
 printf("3. Peek Operation\n");
 printf("4. Display Stack\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter the value to push: ");
 scanf("%d", &value);
 push(value);
 break;
 case 2:
 value = pop();
 if (value != -1) {
 printf("Popped value: %d\n", value);
 }
 break;
 case 3:
 value = peek();
 if (value != -1) {
 printf("Top of the stack: %d\n", value);
 }
 break;
 case 4:
 display();
 break;
 default:
 printf("Invalid choice. Please try again.\n")
 
 printf("Do you want to continue? (1 for Yes / 0 for No): ");
 scanf("%d", &choice);
 } while (choice == 1);
 return 0;
}
void push(int item) {
 if (top < SIZE - 1) {
 stack[++top] = item;
 } else {
 printf("Stack overflow! Cannot push %d.\n", item)
 }
}
int pop() {
 if (top == -1) {
 printf("Stack underflow! No elements to pop.\n");
 return -1;
 }
 return stack[top--]
 }
int peek() {
 if (top == -1) {
 printf("Stack is empty! No elements to peek.\n");
 return -1;
 }
 return stack[top];
}
void display() {
 if (top == -1) {
 printf("Stack is empty.\n");
 } else {
 printf("Stack elements:\n");
 for (int i = top; i >= 0; i--) {
 printf("%d\n", stack[i]);
 }
 }
}
