#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#define MAX 100 // Maximum size of stack
int stack[MAX];
int top = -1;
// Push (add) a number to the stack
void push(int value) {
 if (top == MAX - 1) {
 printf("Stack is full!\n");
 exit(1);
 }
 top++;
 stack[top] = value; // Add the value and move the top up
 }
int pop() {
 if (top == -1) {
 printf("Stack is empty!\n");
 exit(1)
}
 top--;
 return stack[top]; // Return the top value and move the top down
}
int evaluatePostfix(char *expression) {
 for (int i = 0; expression[i] != '\0'; i++) {
 char ch = expression[i];
 if (isdigit(ch)) {
 push(ch - '0');
 } else {
 // Pop two numbers for the operator
 int b = pop();
 int a = pop();
 // Perform the operation
 int result;
 switch (ch) {
 case '+': result = a + b; break;
 case '-': result = a - b; break;
 case '*': result = a * b; break;
 case '/': result = a / b; break;
 default:
 printf("Invalid operator: %c\n", ch);
 exit(1);
 }
 push(result); // Push the result back to the stack
 }
 }
 return pop(); // Final result
}
int main() {
 char expression[MAX];
 printf("Enter a postfix expression (e.g., 53+62/*): ");
 scanf("%s", expression);
 int result = evaluatePostfix(expression);
 printf("The result is: %d\n", result);
 return 0;
}
