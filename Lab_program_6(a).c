#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
struct Node* createNode(int val) {
struct Node* n = (struct Node*)malloc(sizeof(struct Node));
n->data = val;
n->next = NULL;
return n;
}
void insertEnd(struct Node** head, int val) {
struct Node* n = createNode(val);
if (*head == NULL) { *head = n; return; }
struct Node* t = *head;
while (t->next) t = t->next;
t->next = n;
}
void display(struct Node* head) {
if (!head) { printf("List is empty.\n"); return; }
printf("List: ");
while (head) { printf("%d ", head->data); head = head->next; }
printf("\n");
}
void sortList(struct Node* head) { // bubble sort by swapping data
if (!head) return;
for (struct Node* i = head; i != NULL; i = i->next) {
for (struct Node* j = i->next; j != NULL; j = j->next) {
if (i->data > j->data) {
int tmp = i->data;
i->data = j->data;
j->data = tmp;
}
}
}
}
struct Node* reverseList(struct Node* head) {
struct Node *prev = NULL, *cur = head, *next = NULL;
while (cur) {
next = cur->next;
cur->next = prev;
prev = cur;
cur = next;
}
return prev;
}
struct Node* concat(struct Node* a, struct Node* b) {
if (!a) return b;
struct Node* t = a;
while (t->next) t = t->next;
t->next = b;
return a;
}
struct Node* createListFromUser() {
int n, val;
struct Node* head = NULL;
printf("How many nodes? ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Enter value %d: ", i + 1);
scanf("%d", &val);
insertEnd(&head, val);
}
return head;
}
int main() {
int ch;
struct Node *L1 = NULL, *L2 = NULL;
while (1) {
printf("\n1.Create L1 2.Create L2 3.Sort L1 4.Reverse L1 5.Concat(L1+L2) 6.Display
L1 7.Display L2 8.Exit\n");
printf("Enter choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: L1 = createListFromUser(); break;
case 2: L2 = createListFromUser(); break;
case 3: sortList(L1); printf("L1 sorted.\n"); break;
case 4: L1 = reverseList(L1); printf("L1 reversed.\n"); break;
case 5: L1 = concat(L1, L2); L2 = NULL; printf("Concatenated into L1.\n"); break;
case 6: display(L1); break;
case 7: display(L2); break;
case 8: exit(0);
default: printf("Invalid choice!\n");
}
}
}
