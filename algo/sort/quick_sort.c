#include <stdio.h>

void quick_sort(int *data, int l, int r) {
	int L = l, R = r;
	if (L > R) return;

	int mid = (L + R) / 2;
	int pivot = data[mid];

	while (L <= R) {
		while (data[L] < pivot) L++;
		while (pivot < data[R]) R--;

		if (L <= R) {
			int temp;
			temp = data[L];
			data[L] = data[R];
			data[R] = temp;
			L++;
			R--;
		}
	}
	if (L < r) quick_sort(data, L, r);
	if (l < R) quick_sort(data, l, R);
}

int main(void) {
	int data[9] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };
	int l = 0;
	int r = 9;

	quick_sort(data, 0, r-1);
	for (int i = 0; i < r; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}