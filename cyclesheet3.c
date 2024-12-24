#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
struct stack {
 char arr[SIZE];
 int top;
} st;

int empty() {
 return st.top == -1;
}
int full() {
 return st.top >= SIZE - 1
}
void push(char value) {
 if (!full()) {
 st.arr[++st.top] = value;
 } else {
 printf("Stack overflow!\n");
 }
}
char pop() {
 if (!empty()) {
 return st.arr[st.top--];
 }
 printf("Stack underflow!\n");
 return '\0'; 
}
char peek() {
 if (!empty()) {
 return st.arr[st.top];
 }
 return '\0'; 
}
int prec(char c) {
 if (c == '+' || c == '-') return 1;
 if (c == '*' || c == '/') return 2;
 if (c == '^') return 3;
 return -1; 
}
// Check if a character is an operator
int is_operator(char c) {
 return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'
}
void reverse(char* str) {
 int len = strlen(str);
 for (int i = 0; i < len / 2; i++) {
 char temp = str[i];
 str[i] = str[len - i - 1];
 str[len - i - 1] = temp;
}
}
void infix_to_prefix(const char* infix, char* prefix) {
 char reversed[SIZE], postfix[SIZE];
 int j = 0;
 // Step 1: Reverse the infix expression
 strcpy(reversed, infix);
 reverse(reversed);
 // Step 2: Replace '(' with ')' and vice versa
 for (int i = 0; reversed[i] != '\0'; i++) {
 if (reversed[i] == '(') {
 reversed[i] = ')';
 } else if (reversed[i] == ')') {
 reversed[i] = '(';
 }
 }
 for (int i = 0; reversed[i] != '\0'; i++) {
 char current = reversed[i];
 if (isalnum(current)) {
 postfix[j++] = current; 
 }
  else if (current == '(') {
  	push(current);
 } else if (current == ')') {
 while (!empty() && peek() != '(') {
 postfix[j++] = pop();
 }
 pop(); 
 } else if (is_operator(current)) {
 while (!empty() && prec(peek()) >= prec(current)) {
 postfix[j++] = pop();
 }
 push(current);
 }
 }
 while (!empty()) {
 postfix[j++] = pop(); 
 }
 postfix[j] = '\0'; 
  strcpy(prefix, postfix);
 reverse(prefix);
}
int main() {
 st.top = -1; 
 char infix[SIZE], prefix[SIZE];
 printf("Enter an infix expression: ");
 scanf("%s", infix);
 infix_to_prefix(infix, prefix);
 printf("Prefix expression: %s\n", prefix)
 return o;
}
