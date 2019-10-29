#include <stdio.h>

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
int main(void) {
	int data[7] = { 3, 5, 2, 6, 7, 1, 4 };
	int n = 7;
	insertion_sort(data, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}