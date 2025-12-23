#include <stdio.h>
#include <ctype.h>
#define MAX 200
char stack[MAX];
int top = -1;
void push(char c) {
if (top == MAX - 1) {
printf("Stack overflow!\n");
return;
}
stack[++top] = c;
}
char pop() {
if (top == -1) return '\0';
return stack[top--];
}
char peek() {
if (top == -1) return '\0';
return stack[top];
}
int precedence(char op) {
switch (op) {
case '*':
case '/': return 2;
case '+':
case '-': return 1;
default: return 0;
}
}
int main() {
char infix[MAX], postfix[MAX];
int i = 0, j = 0;
char ch;

printf("Enter valid parenthesized infix expression: ");
scanf("%s", infix);
while ((ch = infix[i++]) != '\0') {
if (isalnum(ch)) {
postfix[j++] = ch; // operand goes directly to postfix
}
else if (ch == '(') {
push(ch);
}
else if (ch == ')') {
while (top != -1 && peek() != '(') {
postfix[j++] = pop();
}
pop(); // remove '('
}
else { // operator
while (top != -1 && precedence(peek()) >= precedence(ch)) {
if (peek() == '(') break;
postfix[j++] = pop();
}
push(ch);
}
}
while (top != -1) {
postfix[j++] = pop();
}
postfix[j] = '\0';
printf("Postfix expression: %s\n", postfix);
return 0;
}
