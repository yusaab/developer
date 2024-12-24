#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Added to use strlen
#define MAX 100
// Stack to hold intermediate results
int stack[MAX];
int top = -1;
// Function to push an element onto the stack
void push(int value) {
 if (top == MAX - 1) {
 printf("Stack Overflow\n");
 return;
 }
 stack[++top] = value;
}
// Function to pop an element from the stack
int pop() {
 if (top == -1) {
 printf("Stack Underflow\n");
 return -1; // Error value
 }
 return stack[top--];
}
// Function to check if a character is an operator
int isOperator(char ch) {
 return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
// Function to evaluate the prefix expression
int evaluatePrefix(char* expr) {
 int i;
 int operand1, operand2, result;
 // Traverse the prefix expression from right to left
 for (i = strlen(expr) - 1; i >= 0; i--) {
 char ch = expr[i];
 if (isdigit(ch)) {
 // If character is an operand (digit), push it onto the stack
 push(ch - '0');
 } else if (isOperator(ch)) {
 operand1 = pop();
 operand2 = pop();
 
 switch (ch) {
 case '+': result = operand1 + operand2; break;
 case '-': result = operand1 - operand2; break;
 case '*': result = operand1 * operand2; break;
 case '/':
 if (operand2 == 0) {
 printf("Error: Division by zero\n");
 return -1; 
 }
 result = operand1 / operand2; 
 break;
 default: result = 0; break;
 }
 
 push(result);
 }
 }
 return pop();
}
int main() {
 char expr[MAX];
 
 printf("Enter a prefix expression: ");
 scanf("%s", expr);
 int result = evaluatePrefix(expr);
 
 if (result != -1) { 
 printf("Result of the prefix expression: %d\n", result);
}
return 0;
}
