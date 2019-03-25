# include <stdio.h>
int data[1002];
int upperSearch(int start, int end, int check);
int lowerSearch(int start, int end, int check);
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (data[i] > data[j]) {
				int tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int length = data[j] - data[i];
			int low = lowerSearch(j + 1, n - 1, data[j] + length);
			int up = upperSearch(j + 1, n - 1, data[j] + (length * 2));
			
			if ((low >= 0) && (up >= 0)) {
				result += up - low + 1;
			}
		
		}
	}

	printf("%d", result);

	return 0;
}

int lowerSearch(int start, int end, int check) {
	int result = -1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (data[mid] >= check) {
			result = mid;
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
		if (data[mid] <= check) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return result;
}