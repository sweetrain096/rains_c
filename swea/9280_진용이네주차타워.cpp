#include <stdio.h>
int T;
int n, m;
int rates[110] = { 0, };
int parking_lot[110] = { 0, };
int weights[2010] = { 0, };
int wait[1910] = { 0, };
int rp, wp;
int car;
int cost;

int main(void) {
	freopen("9280_input.txt", "r", stdin);
	scanf("%d ", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &n, &m);
		for (int r = 1; r <= n; r++) scanf("%d ", &rates[r]);
		for (int w = 1; w <= m; w++) scanf("%d ", &weights[w]);

		cost = 0;
		rp = 0;
		wp = 0;
		int park = 1;
		for (int i = 0; i<2*m; i++){
			scanf("%d ", &car);
			if (car > 0) {
				if (park <= n) {
					parking_lot[park] = 1;
					cost += weights[car] * rates[park];
					weights[car] = park;
					for (int j = park + 1; j <= n + 1; j++) {
						if (parking_lot[j]) continue;
						park = j;
						break;
					}
				}
				else {
					wait[wp++] = car;
				}
				

			}
			else {
				car = -car;
				// 주차되어있던 차의 위치
				int park_idx = weights[car];
				parking_lot[park_idx] = 0;
				if (rp != wp) {
					// 밀렸던 자동차의 순서
					int wait_car = wait[rp++];
					parking_lot[park_idx] = 1;
					cost += weights[wait_car] * rates[park_idx];
					weights[wait_car] = park_idx;
				}
				else {
					if (park_idx < park) park = weights[car];

				}

			}

		}
		printf("#%d %d\n", tc, cost);

	}
	return 0;
}