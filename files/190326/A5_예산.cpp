# include <stdio.h>

int n, m;
int data[10010];
int result, sum_data;
int main(void) {
	int i, j;
	int tmp;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			tmp = 0;
			if (data[i] > data[j]) {
				tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}
	}

	result = 0;
	sum_data = 0;
	for (i = 0; i < n; i++) {
		if (sum_data + data[i] * (n - i) <= m) {
			sum_data += data[i];
		}
		else {
			result = (m - sum_data) / (n - i);
			break;
		}
	}
	if (result == 0) {
		printf("%d", data[n - 1]);
	}
	else {
		printf("%d", result);
	}
	
	return 0;
}