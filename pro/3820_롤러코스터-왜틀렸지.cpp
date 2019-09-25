#include <stdio.h>
#include <malloc.h>

int T;
int n;
int a, b;
unsigned long long v;

typedef struct Data {
	int a, b;
}Data;
Data *list;
Data *sorted;

void merge(Data *arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if ((list[i].a - 1)*list[j].b >= (list[j].a - 1)*list[i].b) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i <= mid) while (i <= mid) sorted[k++] = list[i++];
	else while (j <= right) sorted[k++] = list[j++];
	for (int m = left; m <= right; m++) list[m] = sorted[m];
}

void merge_sort(Data *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}



int main(void) {
	freopen("3820_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		list = (Data*)malloc(sizeof(Data)*n);
		sorted = (Data*)malloc(sizeof(Data)*n);
		v = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			list[i].a = a;
			list[i].b = b;
		}
		merge_sort(list, 0, n - 1);
		for (int i = 0; i < n; i++) {
			v *= list[i].a;
			v += list[i].b;
			//printf("%d %d %llu\n", list[i].a, list[i].b, v);
		}
		printf("#%d %llu\n", tc, v % 1000000007);
		free(list);
		free(sorted);
	}

	return 0;
}