#include <stdio.h>

typedef struct Node{
	int pri, key;
}Node;

Node heap[100010];

int n, x;
int heapsize;

int abs(int num) {
	if (num < 0) return -num;
	return num;
}

int get_parent(int node) {
	return node / 2;
}

void push(int pri, int key) {
	heapsize++;
	heap[heapsize].pri = pri;
	heap[heapsize].key = key;
	int cur = heapsize;
	int par = get_parent(cur);

	Node temp;
	while (cur != 1) {
		if (heap[par].pri < heap[cur].pri) break;
		if (heap[par].pri == heap[cur].pri) {
			if (heap[par].key < heap[cur].key) break;
		}
		temp = heap[par];
		heap[par] = heap[cur];
		heap[cur] = temp;

		cur = par;
		par = get_parent(cur);
	}
}

int get_child(int node) {
	if (node * 2 > heapsize) return 0;
	if (node * 2 == heapsize) return node * 2;
	if (heap[node * 2].pri == heap[node * 2 + 1].pri) {
		if (heap[node * 2].key < heap[node * 2 + 1].key) return node * 2;
		return node * 2 + 1;
	}
	if (heap[node * 2].pri < heap[node * 2 + 1].pri) return node * 2;
	return node * 2 + 1;
}

int pop(void) {
	if (heapsize == 0) return 0;

	int return_num = heap[1].key;
	heap[1] = heap[heapsize];
	heap[heapsize].key = 0;
	heap[heapsize].pri = 0;
	heapsize--;

	if (heapsize == 0) return return_num;

	int cur = 1;
	int child = get_child(cur);
	Node temp;
	while (child && heap[cur].pri >= heap[child].pri) {
		if (heap[cur].pri == heap[child].pri) {
			if (heap[cur].key <= heap[child].key) break;
		}
		temp = heap[cur];
		heap[cur] = heap[child];
		heap[child] = temp;
		
		cur = child;
		child = get_child(cur);
	}
	return return_num;
}

void display(void) {
	for (int i = 1; i <= heapsize; i++) printf("%d ", heap[i].pri);
	printf("\n");
	for (int i = 1; i <= heapsize; i++) printf("%d ", heap[i].key);
	printf("\n");
}

int main(void) {
	freopen("11286_input.txt", "r", stdin);
	scanf("%d ", &n);
	heapsize = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &x);
		if (x) push(abs(x), x);
		else printf("%d\n", pop());
		// display();
	}
	return 0;
}