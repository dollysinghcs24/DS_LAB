#include <stdio.h>
#define MAX 10
int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;
/* Enqueue */
void enqueue(int v) {
if (rear == MAX - 1)
return;
if (front == -1)
front = 0;
queue[++rear] = v;
}
/* Dequeue */
int dequeue() {
return queue[front++];
}
/* BFS Traversal */
void bfs(int start) {
int i, v;
visited[start] = 1;
enqueue(start);
printf("BFS Traversal: ");
while (front <= rear) {
v = dequeue();
printf("%d ", v);
for (i = 0; i < n; i++) {
if (adj[v][i] == 1 && visited[i] == 0) {
visited[i] = 1;
enqueue(i);
}
}
}
printf("\n");
}
int main() {
int i, j, start;
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &adj[i][j]);
}
visited[i] = 0;
}
printf("Enter starting vertex: ");
scanf("%d", &start);
bfs(start);
return 0;
}
}
