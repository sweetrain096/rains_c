# include <stdio.h>
int data[50002], checks[10002];
int binSearch(int start, int end, int check);

int main(void) {
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int check, result;
		scanf("%d", &check);
		result = binSearch(0, n - 1, check);
		printf("%d\n", result);
	}

	return 0;
}

int binSearch(int start, int end, int check) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (data[mid] == check) {
			return mid + 1;
		}
		else if (data[mid] > check) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}