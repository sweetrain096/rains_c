#include <stdio.h>

int TC;
int n;
int data[10000];

void quick_sort(int l, int r) {
	int L = l;
	int R = r;

	if (L > R) return;

	int mid = (L + R) / 2;
	int pivot = data[mid];

	while (L <= R) {
		while (data[L] > pivot) L++;
		while (pivot > data[R]) R--;

		if (L <= R) {
			int temp;
			temp = data[L];
			data[L] = data[R];
			data[R] = temp;
			L++;
			R--;
		}
	}
	if (L < r) quick_sort(L, r);
	if (l < R) quick_sort(l, R);
}


int main(void) {
	freopen("3503_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		for (int i = 0; i < n; i++) scanf("%d ", &data[i]);
		quick_sort(0, n - 1);

		int diff = data[0] - data[1];
		for (int i = 0; i < n - 2; i++) {
			if (data[i] - data[i + 2] > diff) diff = data[i] - data[i + 2];
		}
		if (data[n - 2] - data[n - 1] > diff) diff = data[n - 2] - data[n - 1];

		printf("#%d %d\n", tc, diff);
	}
	return 0;
}