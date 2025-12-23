#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
struct node *head = NULL;
/* Create linked list */
void create() {
int n, i, data;
struct node *newnode, *temp;
printf("Enter number of nodes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
newnode = (struct node *)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d", &data);
newnode->data = data;
newnode->next = NULL;
if (head == NULL) {
head = newnode;
temp = head;
} else {
temp->next = newnode;
temp = newnode;
}
}
}
/* Insert at beginning */
void insert_begin() {
int data;
  
struct node *newnode = (struct node *)malloc(sizeof(struct node));
printf("Enter data to insert at beginning: ");
scanf("%d", &data);
newnode->data = data;
newnode->next = head;
head = newnode;
}
/* Insert at end */
void insert_end() {
int data;
struct node *newnode, *temp;
newnode = (struct node *)malloc(sizeof(struct node));
printf("Enter data to insert at end: ");
scanf("%d", &data);
newnode->data = data;
newnode->next = NULL;
if (head == NULL) {
head = newnode;
return;
}
temp = head;
while (temp->next != NULL)
temp = temp->next;
temp->next = newnode;
}
/* Insert at any position */
void insert_pos() {
int pos, data, i;
struct node *newnode, *temp;
printf("Enter position: ");
scanf("%d", &pos);
printf("Enter data: ");
scanf("%d", &data);
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = data;

if (pos == 1) {
newnode->next = head;
head = newnode;
return;
}
temp = head;
for (i = 1; i < pos - 1 && temp != NULL; i++)
temp = temp->next;
if (temp == NULL) {
printf("Invalid position\n");
free(newnode);
return;
}
newnode->next = temp->next;
temp->next = newnode;
}
/* Display list */
void display() {
struct node *temp = head;
if (head == NULL) {
printf("Linked list is empty\n");
return;
}
printf("Linked list contents: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
int main() {
int choice;
while (1) {
printf("\n--- Singly Linked List Operations ---\n");
printf("1. Create Linked List\n");
printf("2. Insert at Beginning\n");
printf("3. Insert at End\n");

printf("4. Insert at Any Position\n");
printf("5. Display\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: create();
break;
case 2: insert_begin();
break;
case 3: insert_end();
break;
case 4: insert_pos();
break;
case 5: display();
break;
case 6: exit(0);
default: printf("Invalid choice\n");
}
}
return 0;
}
