#include <stdio.h>

void heapify(int *arr, int index, int heap_size) {
	int largest = index;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int temp;

	// ���� �ڽ��� ���� ��Һ��� ũ�� �ε��� ��ü
	if (left < heap_size && arr[left] > arr[largest]) {
		largest = left;
	}
	// ������ �ڽ��� ���� ��Һ��� ũ�� �ε��� ��ü
	if (right < heap_size && arr[right] > arr[largest]) {
		largest = right;
	}
	// ��ü�Ǿ��ٸ� index�� largest ��Ұ� ��ü
	if (largest != index) {
		temp = arr[largest];
		arr[largest] = arr[index];
		arr[index] = temp;
		// ���� �� ����� �κ��� �߽����� �ٽ� �� �� heapify
		heapify(arr, largest, heap_size);
	}

}
void heap_sort(int *arr, int heap_size) {
	int temp;
	// ���� ��
	// Ʈ���� ���ݺ��� �Ųٷ� �ö󰡸� heapify
	for (int i = heap_size / 2; i >= 0; i--) {
		heapify(arr, i, heap_size);
	}

	// �ѹ� ������ ���� ũ�⺰�� ����.
	// ���� ū ��(��Ʈ)�� �ε��� �� �ڷ� ���� �� �� ����
	for (int i = heap_size - 1; i >= 0; i--) {
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, 0, i);
	}
}

int main(void) {
	int data[20] = { 61, 324, 21, 56, 243, 6, 1, 634, 43, 3, 52 };
	int n = 11;
	heap_sort(data, n);
	for (int i = 0; i < n; i++) printf("%d ", data[i]);

	return 0;
}