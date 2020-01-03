#include <stdio.h>

int heap[100010] = { 0, };
int n;
int x;
int idx, heapsize;

int get_parent(int node) {
	return node / 2;
}

void push(int key) {
	heapsize++;
	heap[heapsize] = key;
	int cur = heapsize;
	int par = get_parent(heapsize);
	int temp;
	while (cur != 1) {
		if (heap[par] >= heap[cur]) break;
		temp = heap[par];
		heap[par] = heap[cur];
		heap[cur] = temp;
		cur = par;
		par = get_parent(cur);
	}
}

int is_empty(int len) {
	if (len == 0) return 1;
	return 0;
}

int get_big_child(int node) {
	if (node * 2 > heapsize) return 0;
	if (node * 2 == heapsize) return node * 2;
	if (heap[node * 2] > heap[node * 2 + 1]) return node * 2;
	return node * 2 + 1;
}

int pop() {
	if (is_empty(heapsize)) return 0;

	int return_num = heap[1];
	heap[1] = heap[heapsize];
	heap[heapsize] = 0;
	heapsize--;

	if (heapsize == 0) return return_num;

	int cur = 1;
	int big_child = get_big_child(cur);
	int temp;
	while (big_child && heap[big_child] > heap[cur]) {
		temp = heap[big_child];
		heap[big_child] = heap[cur];
		heap[cur] = temp;
		cur = big_child;
		big_child = get_big_child(cur);
	}

	return return_num;
}


int main(void) {
	freopen("11279_input.txt", "r", stdin);
	
	scanf("%d ", &n);
	heapsize = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d ", &x);
		if (x != 0) push(x);
		else printf("%d\n", pop());
	}
	return 0;
}