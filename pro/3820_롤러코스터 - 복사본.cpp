#include <stdio.h>
#include <malloc.h>

int testcase, n;
int a, b, v;
float sorted[200010];
int min;

typedef struct data {
	int a, b;
	float v;
}data;

data data_list[200010];

void merge(data list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if ((list[i].a-1)*list[j].b <= (list[j].a - 1) * list[i].b)
			sorted[k++] = list[i++].v;
		else
			sorted[k++] = list[j++].v;
	}
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l].v;
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l].v;
	}
	for (l = left; l <= right; l++)
		list[l].v = sorted[l];
}

void merge_sort(data list[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}



int main(void) {
	freopen("3820_input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++) {
		scanf("%d", &n);
		for (int cnt = 0; cnt < n; cnt++) {
			scanf("%d %d", &a, &b);
			data_list[cnt].a = a;
			data_list[cnt].b = b;
			data_list[cnt].v = (a - 1) / b;
		}
		
		merge_sort(data_list, 0, n - 1);

		v = 1;
		for (int i = 0; i < n; i++) {
			v *= data_list[i].a;
			v += data_list[i].b;
			printf("%d, %d, %f\n", data_list[i].a, data_list[i].b, data_list[i].v);
		}
		printf("#%d %d\n", tc, v % 1000000007);
	}

	return 0;
}