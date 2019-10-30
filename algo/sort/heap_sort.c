#include <stdio.h>

void heapify(int *arr, int index, int heap_size) {
	int largest = index;
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int temp;

	// 왼쪽 자식이 현재 요소보다 크면 인덱스 교체
	if (left < heap_size && arr[left] > arr[largest]) {
		largest = left;
	}
	// 오른쪽 자식이 현재 요소보다 크면 인덱스 교체
	if (right < heap_size && arr[right] > arr[largest]) {
		largest = right;
	}
	// 교체되었다면 index와 largest 요소값 교체
	if (largest != index) {
		temp = arr[largest];
		arr[largest] = arr[index];
		arr[index] = temp;
		// 변경 후 변경된 부분을 중심으로 다시 한 번 heapify
		heapify(arr, largest, heap_size);
	}

}
void heap_sort(int *arr, int heap_size) {
	int temp;
	// 최초 힙
	// 트리의 절반부터 거꾸로 올라가며 heapify
	for (int i = heap_size / 2; i >= 0; i--) {
		heapify(arr, i, heap_size);
	}

	// 한번 구성된 힙을 크기별로 정렬.
	// 가장 큰 값(루트)를 인덱스 맨 뒤로 보낸 뒤 힙 생성
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