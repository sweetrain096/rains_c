# include <stdio.h>
int n;
int data[510];
int sum(int n) {
	data[0] = 0;
	for (int i = 1; i <= n; i++) {
		data[i] = data[i - 1] + i;
	}
	return data[n];
}
int main(void) {
	int result;
	scanf("%d", &n);

	result = sum(n);
	printf("%d", result);
	return 0;
}