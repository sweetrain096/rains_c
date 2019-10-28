#include <stdio.h>
void selection_sort(int arr[], int n) {
	int i, j, min_index, temp;
	for (i = 0; i < n - 1; i++) {
		min_index = i;
		for (j = i + 1; j < n; j++) {
			if (arr[min_index] > arr[j]) min_index = j;
		}
		if (i == min_index) continue;
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
}
int main(void) {
	int data[9] = { 4, 6, 3, 7, 8, 1, 9, 5, 2 };
	int n = 9;
	selection_sort(data, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}
	
	return 0;
}