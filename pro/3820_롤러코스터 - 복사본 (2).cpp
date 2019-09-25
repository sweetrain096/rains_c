#include <stdio.h>
#include <malloc.h>

int T;
int n;
int a, b, v;

struct Data {
	int a, b;
};

Data *list;
Data *tmp;
/*
void merge(Data *list, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	printf("%d %d %d \n", left, mid, right);
	tmp = (Data*)malloc(sizeof n);

	while (i <= mid && j <= right) {
		printf("%d %d %d %d\n", i, j, mid, right);
		if ((list[i].a - 1)*list[j].b >= (list[j].a - 1)*list[i].b) tmp[k++] = list[i++];
		else tmp[k++] = list[j++];
	}
	if (i <= mid) while (i <= mid) tmp[k++] = list[i++];
	else while (j <= right) tmp[k++] = list[j++];
	for (int m = left; m <= right; m++) list[m] = tmp[m];
	//for (int m = left; m <= right; m++) printf("%d %d \n", tmp[m].a, tmp[m].b);
	

}

void merge_sort(Data *list, int left, int right) {
	printf("%d %d\n", left, right);
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
*/

int main(void) {
	freopen("3820_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n);
		list = (Data*)malloc(sizeof(Data)*n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			list[i].a = a;
			list[i].b = b;
		}

		//merge_sort(list, 0, n - 1);
		for (int i = 0; i < n; i++) {
			printf("%d %d\n", list[i].a, list[i].b);
		}
		printf("#%d \n", tc);
		free(list);
	}

	return 0;
}