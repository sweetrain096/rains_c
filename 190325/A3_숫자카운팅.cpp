# include <stdio.h>
int data[200002];
int lowerSearch(int start, int end, int check);
int upperSearch(int start, int end, int check);

int main(void) {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int check;
		scanf("%d", &check);
		int low = lowerSearch(0, n, check);
		if (low >= 0) {
			int up = upperSearch(0, n, check);
			printf("%d ", up - low + 1);
		}
		else {
			printf("0 ");
		}
	}


	return 0;
}


int lowerSearch(int start, int end, int check) {
	int result = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (data[mid] == check){
			result = mid;
			end = mid - 1;
		}
		else if (data[mid] > check) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return result;
}

int upperSearch(int start, int end, int check) {
	int result = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (data[mid] == check) {
			result = mid;
			start = mid + 1;
		}
		else if (data[mid] > check) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return result;
}