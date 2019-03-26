# include <stdio.h>
int n, m;
int datas[10];

void find(int depth, int sum_data) {
	if (sum_data > m)	return;
	if ((sum_data + (n - depth) * 6) < m)	return;
	if (depth == n) {
		for (int j = 0; j < depth; j++) {
			printf("%d ", datas[j]);
		}
		printf("\n");
	}

	for (int i = 1; i <= 6; i++) {
		datas[depth] = i;
		sum_data += i;
		depth++;
		find(depth, sum_data);
		depth--;
		datas[depth] = 0;
		sum_data -= i;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	find(0, 0);
	return 0;
}