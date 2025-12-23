#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
/* Insert operation */
void insert() {
int item;
if (rear == SIZE - 1) {
printf("Queue Overflow\n");
return;
}
if (front == -1)
front = 0;
printf("Enter element to insert: ");
scanf("%d", &item);
queue[++rear] = item;
}
/* Delete operation */
void delete() {
if (front == -1 || front > rear) {
printf("Queue Underflow (Queue is empty)\n");
return;
}
printf("Deleted element: %d\n", queue[front++]);
}
/* Display operation */
void display() {
int i;
if (front == -1 || front > rear) {

printf("Queue is empty\n");
return;
}
printf("Queue elements: ");
for (i = front; i <= rear; i++)
printf("%d ", queue[i]);
printf("\n");
}
int main() {
int choice;
while (1) {
printf("\n--- Queue Operations ---\n");
printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: insert();
break;
case 2: delete();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("Invalid choice\n");
}
}
return 0;
}
