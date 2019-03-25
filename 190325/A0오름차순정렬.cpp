#include <stdio.h>

int main(void)
{
	int n;
	int data[5002];

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

	for (int i = 0; i < n; i++) {
		printf("%d ", data[i]);
	}



	return 0;
}