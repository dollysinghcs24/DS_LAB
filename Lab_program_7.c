#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node *prev, *next;
} Node;
Node* createNode(int x) {
Node* n = (Node*)malloc(sizeof(Node));
if (!n) {
printf("Memory allocation failed!\n");
exit(1);
}
n->data = x;
n->prev = n->next = NULL;
return n;
}
void display(Node* head) {
if (head == NULL) {
printf("List is empty.\n");
return;
}
printf("DLL: ");
while (head != NULL) {
printf("%d ", head->data);
head = head->next;
}
printf("\n");
}
void createList(Node** head) {
int n, x;
Node *temp, *tail;
// clear old list if any
temp = *head;
while (temp) {
Node* del = temp;
temp = temp->next;
free(del);
}
*head = NULL;
printf("Enter number of nodes: ");
scanf("%d", &n);
if (n <= 0) {
printf("List created as empty.\n");
return;
}
printf("Enter %d values:\n", n);
scanf("%d", &x);
*head = createNode(x);
tail = *head;
for (int i = 2; i <= n; i++) {
scanf("%d", &x);
temp = createNode(x);
tail->next = temp;
temp->prev = tail;
tail = temp;
}
printf("List created.\n");
}
void insertLeft(Node** head) {
if (*head == NULL) {
printf("List is empty. Create list first.\n");
return;
}
int key, x;
printf("Enter the node value (key) to insert LEFT of it: ");
scanf("%d", &key);
printf("Enter new value to insert: ");
scanf("%d", &x);
Node* cur = *head;
while (cur != NULL && cur->data != key) {
cur = cur->next;
}
if (cur == NULL) {
printf("Key %d not found. No insertion done.\n", key);
return;
}
Node* newNode = createNode(x);
// inserting before head
if (cur->prev == NULL) {
newNode->next = cur;
cur->prev = newNode;
*head = newNode;
} else {
Node* left = cur->prev;
newNode->next = cur;
newNode->prev = left;
left->next = newNode;
cur->prev = newNode;
}
printf("Inserted %d to the left of %d.\n", x, key);
}
void deleteByValue(Node** head) {
if (*head == NULL) {
printf("List is empty.\n");
return;
}
int key;
printf("Enter value to delete: ");
scanf("%d", &key);
Node* cur = *head;
while (cur != NULL && cur->data != key) {
cur = cur->next;
}
if (cur == NULL) {
printf("Value %d not found. No deletion done.\n", key);
return;
}
// if deleting head
if (cur->prev == NULL) {
*head = cur->next;
if (*head != NULL) (*head)->prev = NULL;
} else {
cur->prev->next = cur->next;
}
// if deleting middle/tail
if (cur->next != NULL) {
cur->next->prev = cur->prev;
}
free(cur);
printf("Deleted %d from list.\n", key);
}
int main() {
Node* head = NULL;
int ch;
while (1) {
printf("\n---- Doubly Linked List Menu ----\n");
printf("1. Create Doubly Linked List\n");
printf("2. Insert new node to the LEFT of a node (by value)\n");
printf("3. Delete node based on a specific value\n");
printf("4. Display\n");
printf("5. Exit\n");
printf("Enter choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: createList(&head); break;
case 2: insertLeft(&head); break;
case 3: deleteByValue(&head); break;
case 4: display(head); break;
case 5:
// free memory
while (head) {
Node* del = head;
head = head->next;
free(del);
}
printf("Exited.\n");
return 0;
default:
printf("Invalid choice!\n");
}
}
}
