#include <stdio.h>

void counting_sort(int arr[], int count[], int result[], int len, int max) {
	int i;
	for (i = 0; i < len; i++) count[arr[i]]++;
	for (i = 1; i <= max; i++) count[i] += count[i - 1];
	for (i = len - 1; i >= 0; i--) {
		result[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
}
int main(void) {
	int data[10] = { 3, 2, 5, 4, 2, 1, 5, 2, 2, 1 };
	int count[6] = { 0, 0, 0, 0, 0, 0 };
	int result[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int len = 10;
	int max = 5;
	
	counting_sort(data, count, result, len, max);
	
	for (int i = 0; i < len; i++) {
		printf("%d ", result[i]);
	}
	
	return 0;
}