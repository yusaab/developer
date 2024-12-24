#include <stdio.h>
#include <ctype.h>
#define SIZE 100
struct stack {
 char arr[SIZE];
 int top;
} st;

int empty() {
 return st.top == -1;
 }
int full() {
 return st.top >= SIZE - 1;
}
void push(char value) {
 if (!full()) {
 st.arr[++st.top] = value;
}
 else 
 {
 printf("Stack is full\n");
 }
}
char pop() {
 if (!empty()) {
 return st.arr[st.top--];
 }
 printf("Stack underflow!\n")
  return '\0'; 
}
int prec(char c) {
 if (c == '(') return 0;
 if (c == '+' || c == '-') return 1;
 if (c == '*' || c == '/') return 2;
 return -1; 
}
int is_operator(char c) {
 return c == '+' || c == '-' || c == '*' || c == '/'
}
void infix_to_postfix(const char* expression, char* output) {
 int j = 0; // Index for the output
 for (int i = 0; expression[i] != '\0'; i++) {
 char current = expression[i];
 // Skip spaces
 if (current == ' ') continue;
 if (isalnum(current)) {
 // If operand, add to output
 output[j++] = current;
 } else if (current == '(') {
 // Push '(' to stack
 push(current);
 } else if (current == ')') {
 // Pop until '(' is found
 while (!empty() && st.arr[st.top] != '(') {
 output[j++] = pop();
 }
 pop(); 
 }
  else if (is_operator(current)) {
 while (!empty() && prec(st.arr[st.top]) >= prec(current)) {
 output[j++] = pop();
 }
 push(current);
 }
 }
 // Pop remaining operators
 while (!empty()) {
 output[j++] = pop();
 }
 output[j] = '\0'; // Null-terminate the output string
}
int main() {
 st.top = -1; // Initialize stack
 char expression[SIZE], output[SIZE];
  printf("Enter an infix expression: ");
 scanf("%s", expression);
 infix_to_postfix(expression, output);
 printf("Postfix expression: %s\n", output);
 return o;
}
