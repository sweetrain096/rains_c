#include <stdio.h>

int n, x;
int heap[100010] = { 0, };
int heapsize;

int get_parent(int node) {
	return node / 2;
}
void push(int x) {
	heapsize++;
	heap[heapsize] = x;
	int cur = heapsize;
	int par = get_parent(cur);
	int temp;
	while (cur != 1) {
		if (heap[par] <= heap[cur]) break;
		temp = heap[par];
		heap[par] = heap[cur];
		heap[cur] = temp;
		cur = par;
		par = get_parent(cur);
	}
	
}

int is_empty() {
	if (heapsize == 0) return 1;
	return 0;
}

int get_small_child(int node) {
	if (node * 2 > heapsize) return 0;
	if (node * 2 == heapsize) return node * 2;
	if (heap[node * 2] < heap[node * 2 + 1]) return node * 2;
	return node * 2 + 1;
}

int pop() {
	if (is_empty()) return 0;
	int return_n = heap[1];
	heap[1] = heap[heapsize];
	heap[heapsize] = 0;
	heapsize--;

	if (heapsize == 0) return return_n;

	int cur = 1;
	int small_child = get_small_child(cur);
	int temp;
	while (small_child && heap[cur] > heap[small_child]) {
		temp = heap[cur];
		heap[cur] = heap[small_child];
		heap[small_child] = temp;
		cur = small_child;
		small_child = get_small_child(cur);
	}
	return return_n;
}

int main(void) {
	freopen("1927_input.txt", "r", stdin);
	scanf("%d ", &n);
	heapsize = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &x);
		if (x) push(x);
		else printf("%d\n", pop());
	}
	return 0;
}