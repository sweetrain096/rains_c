#include <stdio.h>

void merge(int *arr, int left, int mid, int right) {
	int temp[20];
	int i = left, j = mid + 1, k = left;
	
	// left의 시작인 i가 mid보다 작거나 같고,
	// mid의 시작인 j가 right보다 작거나 같을때까지
	while (i <= mid && j <= right) {
		// 왼쪽 값이 오른쪽 값보다 작거나 같은 경우 temp 배열에 복사
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		// 반대의 경우에 temp에 복사
		else if (arr[i] > arr[j]) temp[k++] = arr[j++];
	}
	// i가 mid보다 커질 경우(왼쪽 값 모두 복사)
	if (i > mid) {
		// 오른쪽 값 모두 복사
		while (j <= right) temp[k++] = arr[j++];
	}
	else {
		// 반대의 경우 왼쪽 값 모두 복사
		while (i <= mid) temp[k++] = arr[i++];
	}
	// 임시 배열의 값을 원래 배열에 복사
	for (int m = left; m <= right; m++) arr[m] = temp[m];
}
void merge_sort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		// left가 right보다 크거나 같아질 때 까지 반복
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		// 길이가 비슷해지면 merge
		merge(arr, left, mid, right);
	}
}


int main(void) {
	int data[20] = { 61, 324, 21, 56, 243, 6, 1, 634, 43, 3, 52 };
	int n = 11;
	merge_sort(data, 0, n-1);
	for (int i = 0; i < n; i++) printf("%d ", data[i]);
	return 0;
}