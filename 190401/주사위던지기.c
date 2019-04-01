# include <stdio.h>
int n, m;
int dice[10], tmp[10], visited[10];
void m1(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", tmp[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < 6; i++) {
		tmp[k] = dice[i];
		m1(k + 1);
		tmp[k] = 0;
	}
}

void m2(int k, int start) {
	for (int i = start; i <= 6; i++) {
		if (k == n) {
			for (int j = 0; j < n; j++) {
				printf("%d ", tmp[j]);
			}
			printf("\n");
			return;
		}
		tmp[k] = i;
		m2(k + 1, i);
		tmp[k] = 0;
	}


}

void m3(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", tmp[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < 6; i++) {
		if (visited[dice[i]]) continue;
		tmp[k] = dice[i];
		visited[dice[i]] = 1;
		m3(k + 1);
		tmp[k] = 0;
		visited[dice[i]] = 0;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= 6; i++) dice[i - 1] = i;
	if (m == 1) m1(0);
	else if (m == 2) m2(0, 1);
	else if (m == 3) m3(0);
	
	return 0;
}