# include <stdio.h>
int t;
int n, m;
int data[20], tmp[20];
int result;

void dfs(int k, int cnt) {
	int compare = -1;
	if (cnt == m) {
		result += 1;
		return;
	}

	if (k >= n) return;

	for (int i = k; i < n; i++) {
		if (compare == data[i]) continue;
		compare = data[i];

		tmp[k] = data[i];
		dfs(i + 1, cnt + 1);
		tmp[k] = 0;


	}

}


int main() {
	int tc, i, j, tmp;
	freopen("µµÀÚ±â_input.txt", "r", stdin);
	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &data[i]);
		}
		for (i = 0; i < n - 1; i++) {
			for (j = i; j < n; j++) {
				if (data[i] > data[j]) {
					tmp = data[j];
					data[j] = data[i];
					data[i] = tmp;
				}
			}
		}

		result = 0;
		dfs(0, 0);
		printf("%d\n", result);
	}
}

