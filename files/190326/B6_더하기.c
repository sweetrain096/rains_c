# include <stdio.h>

int t, n, k;
int data[25];
int result;

void dfs(int num, int sum_data) {
	if (sum_data == k) {
		result = 1;
		return;
	}
	else if (sum_data > k) return;
	if (num == n) return;

	for (int i = 1; i >= 0; i--) {
		if (i == 1) {
			sum_data += data[num];
			dfs(num + 1, sum_data);
			sum_data -= data[num];
		}
		else {
			dfs(num + 1, sum_data);
		}
		
	}
}

int main(void) {
	scanf("%d", &t);
	for (int tc = 0; tc < t; tc++) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &data[i]);
		}
		result = 0;
		dfs(0, 0);
		if (result == 1) printf("YES\n");
		else printf("NO\n");
	}
	
}