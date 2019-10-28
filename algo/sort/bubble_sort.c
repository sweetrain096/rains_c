#include <stdio.h>

void bubble_sort(int arr[], int n) {
	int temp;
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main(void) {
	int data[5] = { 2, 4, 1, 3, 5 };
	int n = 5;
	bubble_sort(data, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	return 0;
}