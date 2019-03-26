# include <stdio.h>

int n, result;
int data[50];

int fivo(int n) {
	data[0] = 0;
	data[1] = 1;
	for (int i = 2; i <= n; i++) {
		data[i] = data[i - 1] + data[i - 2];
	}
	return data[n];
}
int main(void) {
	scanf("%d", &n);
	result = fivo(n);
	printf("%d", result);
	return 0;
}