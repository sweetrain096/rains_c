# include <stdio.h>
int n, result;
int data[3002];

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < i + 2; j++) {
			for (int k = j + 1; k < n; k++) {
				if (data[j] > data[k]) {
					int tmp = data[k];
					data[k] = data[j];
					data[j] = tmp;
				}
			}
		}
		data[i + 1] = data[i + 1] + data[i];
		result = result + data[i + 1];
	}

	printf("%d", result);

	return 0;
}