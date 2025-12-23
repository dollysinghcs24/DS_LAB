#include <stdio.h>
#define EMPTY -1
void init(int ht[], int m) {
for (int i = 0; i < m; i++) ht[i] = EMPTY;
}
int hashFunc(int key, int m) {
return key % m;
}
void insertKey(int ht[], int m, int key) {
int index = hashFunc(key, m);
// Linear probing
for (int i = 0; i < m; i++) {
int pos = (index + i) % m;
if (ht[pos] == EMPTY) {
ht[pos] = key;
printf("Inserted %d at location %d\n", key, pos);
return;
}
if (ht[pos] == key) {
printf("Key %d already exists at location %d\n", key, pos);
return;
}
}
printf("Hash Table Overflow! Cannot insert %d (table is full)\n", key);
}
int searchKey(int ht[], int m, int key) {
int index = hashFunc(key, m);
for (int i = 0; i < m; i++) {
int pos = (index + i) % m;
if (ht[pos] == EMPTY) return -1; // stop early (not found)
if (ht[pos] == key) return pos; // found
}
return -1;
}
void display(int ht[], int m) {
printf("\nHash Table:\n");
printf("Index : Key\n");
for (int i = 0; i < m; i++) {
if (ht[i] == EMPTY) printf("%5d : ---\n", i);
else printf("%5d : %d\n", i, ht[i]);
}
}
int main() {
int m, choice, key;
printf("Enter size of hash table (m): ");
scanf("%d", &m);
int ht[m];
init(ht, m);
while (1) {
printf("\n----- MENU -----\n");
printf("1. Insert Key\n");
printf("2. Search Key\n");
printf("3. Display Hash Table\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter key (4-digit integer): ");
scanf("%d", &key);
insertKey(ht, m, key);
break;
case 2:
printf("Enter key to search: ");
scanf("%d", &key);
{
int loc = searchKey(ht, m, key);
if (loc == -1) printf("Key %d NOT found.\n", key);
else printf("Key %d found at location %d\n", key, loc);
}
break;
case 3:
display(ht, m);
break;
case 4:
return 0;
default:
printf("Invalid choice!\n");
}
}
}
