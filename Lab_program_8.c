// Program: Binary Search Tree (BST) creation + inorder/preorder/postorder traversal
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node *left, *right;
} Node;
Node* createNode(int x) {
Node* n = (Node*)malloc(sizeof(Node));
if (!n) {
printf("Memory allocation failed!\n");
exit(0);
}
n->data = x;
n->left = n->right = NULL;
return n;
}
Node* insert(Node* root, int x) {
if (root == NULL) return createNode(x);
if (x < root->data) root->left = insert(root->left, x);
else if (x > root->data) root->right = insert(root->right, x);
else printf("Duplicate value %d not inserted.\n", x);
return root;
}
void inorder(Node* root) {
if (root == NULL) return;
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
void preorder(Node* root) {
if (root == NULL) return;
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(Node* root) {
if (root == NULL) return;
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
int main() {
Node* root = NULL;
int ch, x;
while (1) {
printf("\n\n--- BST MENU ---");
printf("\n1. Insert (Construct BST)");
printf("\n2. Inorder Traversal");
printf("\n3. Preorder Traversal");
printf("\n4. Postorder Traversal");
printf("\n5. Display (All Traversals)");
printf("\n6. Exit");
printf("\nEnter choice: ");
if (scanf("%d", &ch) != 1) return 0;
switch (ch) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &x);
root = insert(root, x);
break;
case 2:
if (root == NULL) printf("Tree is empty.\n");
else { printf("Inorder: "); inorder(root); printf("\n"); }
break;
case 3:
if (root == NULL) printf("Tree is empty.\n");
else { printf("Preorder: "); preorder(root); printf("\n"); }
break;
case 4:
if (root == NULL) printf("Tree is empty.\n");
else { printf("Postorder: "); postorder(root); printf("\n"); }
break;
case 5:
if (root == NULL) printf("Tree is empty.\n");
else {
printf("Inorder : "); inorder(root); printf("\n");
printf("Preorder : "); preorder(root); printf("\n");
printf("Postorder: "); postorder(root); printf("\n");
}
break;
case 6:
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice!\n");
}
}
}
