#include <stdio.h>
int n;
int A[60];
int B[60];
int result;
void merge(int *arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int tmp[60];
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
		else tmp[k++] = arr[j++];
	}
	if (i > mid) while (j <= right) tmp[k++] = arr[j++];
	else while (i <= mid) tmp[k++] = arr[i++];
	for (int m = left; m <= right; m++) arr[m] = tmp[m];
}
void merge_sort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


int main(void) {
	freopen("1026_input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d ", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d ", &B[i]);
	}
	merge_sort(A, 0, n - 1);
	merge_sort(B, 0, n - 1);
	
	
	result = 0;
	for (int i = 0; i < n; i++) {
		result += A[i] * B[n - 1 - i];
	}

	printf("%d", result);


	return 0;
}