#include <stdio.h>

void merge(int *arr, int left, int mid, int right) {
	int temp[20];
	int i = left, j = mid + 1, k = left;
	
	// left�� ������ i�� mid���� �۰ų� ����,
	// mid�� ������ j�� right���� �۰ų� ����������
	while (i <= mid && j <= right) {
		// ���� ���� ������ ������ �۰ų� ���� ��� temp �迭�� ����
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		// �ݴ��� ��쿡 temp�� ����
		else if (arr[i] > arr[j]) temp[k++] = arr[j++];
	}
	// i�� mid���� Ŀ�� ���(���� �� ��� ����)
	if (i > mid) {
		// ������ �� ��� ����
		while (j <= right) temp[k++] = arr[j++];
	}
	else {
		// �ݴ��� ��� ���� �� ��� ����
		while (i <= mid) temp[k++] = arr[i++];
	}
	// �ӽ� �迭�� ���� ���� �迭�� ����
	for (int m = left; m <= right; m++) arr[m] = temp[m];
}
void merge_sort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		// left�� right���� ũ�ų� ������ �� ���� �ݺ�
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		// ���̰� ��������� merge
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