#include <stdio.h>

int T, n, m;
int result;
int snacks[1000];

void insertion_sort(int arr[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int find_max(int arr[], int n, int m) {
	int i, j, max;
	max = 0;
	for (i = n - 1; i > 0; i--) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[i] + arr[j] == m) return arr[i] + arr[j];
			if (arr[i] + arr[j] < m) {
				if (arr[i] + arr[j] > max) max = arr[i] + arr[j];
				break;
			}
		}
	}
	if (max) return max;
	return -1;
}
int main(void) {
	freopen("9229_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &n, &m);
		result = 0;
		for (int i = 0; i < n; i++) scanf("%d ", &snacks[i]);
		insertion_sort(snacks, n);
		

		if (snacks[0] + snacks[1] > m) result = -1;
		else result = find_max(snacks, n, m);

		printf("#%d %d\n", tc, result);
	}

	return 0;
}