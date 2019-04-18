# include <stdio.h>
int data[80] = { 94, 546, 1, 5, 35, 7, 485, 1, 5, 6, 1, 8, 1, 23, 3 ,4, 9, 55, 34, 25 };
void QuickSort(int s, int e) {
	int tmp;
	if (s >= e) return;
	int t = s;
	int p = e;

	for (int l = s; l <= e; l++) {
		if (data[l] < data[p]) {
			tmp = data[t];
			data[t] = data[l];
			data[l] = tmp;
			t++;
		}
	}
	tmp = data[t];
	data[t] = data[p];
	data[p] = tmp;
	QuickSort(s, t - 1);
	QuickSort(t + 1, e);

}

int main() {
	for (int i = 0; i < 20; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	QuickSort(0, 19);
	for (int i = 0; i < 20; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}
/*def Qsort(s, e):
	if s >= e: return
	t, p = s, e
	for l in range(s, e+1):
		if arr[l] < arr[p]:
			arr[l], arr[t] = arr[t], arr[l]
			t += 1
	arr[p], arr[t] = arr[t], arr[p]
	Qsort(s, t-1)
	Qsort(t+1, e)*/