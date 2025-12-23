// Program: Singly Linked List to simulate Stack & Queue operations
// Compile: gcc sll_stack_queue.c -o sll
// Run: ./sll
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node *next;
} Node;
Node* newNode(int x) {
Node *n = (Node*)malloc(sizeof(Node));
if (!n) {
printf("Memory allocation failed!\n");
exit(0);
}
n->data = x;
n->next = NULL;
return n;
}
/* ---------------- STACK (LIFO) using SLL ----------------
Push -> insert at beginning
Pop -> delete from beginning
*/
void stack_push(Node **top) {
int x;
printf("Enter value to PUSH: ");
scanf("%d", &x);
Node *n = newNode(x);
n->next = *top;
*top = n;
printf("%d pushed into STACK.\n", x);
}
void stack_pop(Node **top) {
if (*top == NULL) {
printf("STACK Underflow (Stack is empty).\n");
return;
}
Node *temp = *top;
int x = temp->data;
*top = (*top)->next;
free(temp);
printf("%d popped from STACK.\n", x);
}
void stack_display(Node *top) {
if (top == NULL) {
printf("STACK is empty.\n");
return;
}
printf("STACK (Top -> Bottom): ");
while (top) {
printf("%d ", top->data);
top = top->next;
}
printf("\n");
}
/* ---------------- QUEUE (FIFO) using SLL ----------------
Enqueue -> insert at end
Dequeue -> delete from beginning
*/
void queue_enqueue(Node **front, Node **rear) {
int x;
printf("Enter value to ENQUEUE: ");
scanf("%d", &x);
Node *n = newNode(x);
if (*rear == NULL) { // empty queue
*front = *rear = n;
} else {
(*rear)->next = n;
*rear = n;
}
printf("%d enqueued into QUEUE.\n", x);
}
void queue_dequeue(Node **front, Node **rear) {
if (*front == NULL) {
printf("QUEUE Underflow (Queue is empty).\n");
return;
}
Node *temp = *front;
int x = temp->data;
*front = (*front)->next;
if (*front == NULL) *rear = NULL; // queue became empty
free(temp);
printf("%d dequeued from QUEUE.\n", x);
}
void queue_display(Node *front) {
if (front == NULL) {
printf("QUEUE is empty.\n");
return;
}
printf("QUEUE (Front -> Rear): ");
while (front) {
printf("%d ", front->data);
front = front->next;
}
printf("\n");
}
/* Free whole list */
void free_list(Node **head) {
Node *cur = *head;
while (cur) {
Node *nx = cur->next;
free(cur);
cur = nx;
}
*head = NULL;
}
int main() {
Node *stackTop = NULL;
Node *qFront = NULL, *qRear = NULL;
int mainChoice, choice;
while (1) {
printf("\n========== MAIN MENU ==========\n");
printf("1. STACK using Linked List\n");
printf("2. QUEUE using Linked List\n");
printf("3. Exit\n");
printf("Enter choice: ");
if (scanf("%d", &mainChoice) != 1) return 0;
if (mainChoice == 1) {
while (1) {
printf("\n--- STACK MENU ---\n");
printf("1. Push\n2. Pop\n3. Display\n4. Back\n");
printf("Enter choice: ");
scanf("%d", &choice);
if (choice == 1) stack_push(&stackTop);
else if (choice == 2) stack_pop(&stackTop);
else if (choice == 3) stack_display(stackTop);
else if (choice == 4) break;
else printf("Invalid choice!\n");
}
} else if (mainChoice == 2) {
while (1) {
printf("\n--- QUEUE MENU ---\n");
printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
printf("Enter choice: ");
scanf("%d", &choice);
if (choice == 1) queue_enqueue(&qFront, &qRear);
else if (choice == 2) queue_dequeue(&qFront, &qRear);
else if (choice == 3) queue_display(qFront);
else if (choice == 4) break;
else printf("Invalid choice!\n");
}
} else if (mainChoice == 3) {
break;
} else {
printf("Invalid choice!\n");
}
}
free_list(&stackTop);
free_list(&qFront); // rear will auto become invalid; we're exiting anyway
qRear = NULL;
printf("Program ended.\n");
return 0;
}
}
