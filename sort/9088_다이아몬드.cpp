#include <stdio.h>
int tc;
int n, k;
int size[1000] = { 0, };
int start, sum;
int result;

void quick_sort(int *arr, int l, int r) {
	int L = l, R = r;
	if (L > R) return;

	int mid = (L + R) / 2;
	int pivot = arr[mid];
	while (L <= R) {
		while (arr[L] < pivot) L++;
		while (pivot < arr[R]) R--;
		
		if (L <= R) {
			int temp = arr[L];
			arr[L] = arr[R];
			arr[R] = temp;
			L++;
			R--;
		}
	}
	if (L < r) quick_sort(arr, L, r);
	if (l < R) quick_sort(arr, l, R);
}


int main(void) {
	freopen("9088_input.txt", "r", stdin);
	scanf("%d ", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d %d ", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", &size[i]);
		quick_sort(size, 0, n - 1);
		result = 0;
		for (int i = 0; i < n - 1; i++) {
			start = size[i];
			sum = 1;
			if (n - i < result) break;
			for (int j = i + 1; j < n; j++) {
				if (size[j] - start <= k) sum++;
				else break;
			}
			if (result < sum) result = sum;
		}

		printf("#%d %d\n", t, result);
	
	}
	return 0;
}