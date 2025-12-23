#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;
/* Insert operation */
void insert() {
int item;
if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
printf("Queue Overflow\n");
return;
}
printf("Enter element to insert: ");
scanf("%d", &item);
if (front == -1) {
front = rear = 0;
} else if (rear == SIZE - 1) {
rear = 0;
} else {
rear++;
}
cq[rear] = item;
}
/* Delete operation */
void delete() {
if (front == -1) {
printf("Queue Underflow (Queue is empty)\n");
return;
}
printf("Deleted element: %d\n", cq[front]);
if (front == rear) {
front = rear = -1;
} else if (front == SIZE - 1) {
front = 0;
} else {
front++;
}
}
/* Display operation */
void display() {

int i;
if (front == -1) {
printf("Queue is empty\n");
return;
}
printf("Circular Queue elements: ");
if (front <= rear) {
for (i = front; i <= rear; i++)
printf("%d ", cq[i]);
} else {
for (i = front; i < SIZE; i++)
printf("%d ", cq[i]);
for (i = 0; i <= rear; i++)
printf("%d ", cq[i]);
}
printf("\n");
}
int main() {
int choice;
while (1) {
printf("\n--- Circular Queue Operations ---\n");
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
}
return 0;
