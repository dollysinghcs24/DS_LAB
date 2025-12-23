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
/* Delete first element */
void delete_begin() {
struct node *temp;

if (head == NULL) {
printf("List is empty\n");
return;
}
temp = head;
head = head->next;
printf("Deleted element: %d\n", temp->data);
free(temp);
}
/* Delete last element */
void delete_end() {
struct node *temp, *prev;
if (head == NULL) {
printf("List is empty\n");
return;
}
if (head->next == NULL) {
printf("Deleted element: %d\n", head->data);
free(head);
head = NULL;
return;
}
temp = head;
while (temp->next != NULL) {
prev = temp;
temp = temp->next;
}
prev->next = NULL;
printf("Deleted element: %d\n", temp->data);
free(temp);
}
/* Delete specified element */
void delete_specified() {
int key;
struct node *temp, *prev;
if (head == NULL) {
printf("List is empty\n");

return;
}
printf("Enter element to delete: ");
scanf("%d", &key);
if (head->data == key) {
delete_begin();
return;
}
temp = head;
while (temp != NULL && temp->data != key) {
prev = temp;
temp = temp->next;
}
if (temp == NULL) {
printf("Element not found\n");
return;
}
prev->next = temp->next;
printf("Deleted element: %d\n", temp->data);
free(temp);
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
printf("\n--- Singly Linked List Deletion Operations ---\n");
printf("1. Create Linked List\n");
printf("2. Delete First Element\n");
printf("3. Delete Specified Element\n");
printf("4. Delete Last Element\n");
printf("5. Display\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: create();
break;
case 2: delete_begin();
break;
case 3: delete_specified();
break;
case 4: delete_end();
break;
case 5: display();
break;
case 6: exit(0);
default: printf("Invalid choice\n");
}
}
return 0;
}
