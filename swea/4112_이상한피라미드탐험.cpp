#include <stdio.h>

int TC;
int data[150];
int a, b;
int A, B;
int result;

int find_cnt(void) {
	int cnt = 0;
	int l = 0;
	int r = 0;

	while (A <= B) {
		if (A == B) {
			if (l + r == 0) return b - a;
			if (l > b) cnt += l - b;
			if (r < b) cnt += b - r;
			return cnt;
		}

		cnt++;
		int nl = 0;
		int nr = 0;

		if (l + r == 0) {
			if (a + A == b || a + A + 1 == b) return cnt;
			nl = a + A;
			nr = a + A + 1;
		}
		else {
			if (l + A <= b && b <= r + A + 1) return cnt;
			nl = l + A;
			nr = r + A + 1;
		}
		l = nl;
		r = nr;
		A++;

	}
	return 0;
}

int main(void) {
	freopen("4112_input.txt", "r", stdin);
	
	int sum = 0;
	int plus = 0;
	int idx = 0;
	while (1) {
		sum += plus;
		data[idx++] = sum;
		plus++;
		if (sum > 10000) break;
	}
	
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d %d ", &a, &b);
		A = 0;
		B = 0;
		result = 0;
		if (a == b) {
			printf("#%d %d\n", tc, result);
			continue;
		}

		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}

		for (int i = 1; i <= idx; i++) {
			if (a <= data[i] && b <= data[i]) {
				A++;
				B++;
				break;
			}
			if (a > data[i]) A++;
			if (b > data[i]) B++;
		}

		result = find_cnt();
		printf("#%d %d\n", tc, result);
	}
}