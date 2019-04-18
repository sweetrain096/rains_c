# include <stdio.h>
int n, m; // m은 남아있는 치킨집개수
int base[25][25]; // 마을 지도
int hr[50], hc[50]; // 집의 row, col
int cr[15], cc[15]; // 치킨집의 row, col
int cnt_h = 0; // 집의 개수
int cnt_c = 0; // 치킨집 개수
int index[15]; // 치킨집 인덱스
int nr, nc; // find_min에서 집 row, col 한개씩
int result; // 최종 결과값(최소값)

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}
int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}

void find_min() {
	int tmp, tmp_sum = 0;
	for (int i = 0; i < cnt_h; i++) {
		nr = hr[i];
		nc = hc[i];

		tmp = 9999999;
		for (int j = 0; j < m; j++) {
			tmp = min(tmp, abs(nr - cr[index[j]]) + abs(nc - cc[index[j]]));
		}
		tmp_sum += tmp;
	}

	result = min(result, tmp_sum);
}


void pick_none(int k, int cnt) {
	if (cnt == m) {
		find_min();
		return;
	}
	if (k >= n) return;

	for (int i = k; i < cnt_c; i++) {
		index[cnt] = i;
		pick_none(i + 1, cnt + 1);
		index[cnt] = 0;
	}

}

int main() {
	int r, c;
	
	freopen("치킨_input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (r = 1; r <= n; r++) {
		for (c = 1; c <= n; c++) {
			scanf("%d", &base[r][c]);
			if (base[r][c] == 1) {
				hr[cnt_h] = r;
				hc[cnt_h] = c;
				cnt_h++;
			}
			else if (base[r][c] == 2) {
				cr[cnt_c] = r;
				cc[cnt_c] = c;
				cnt_c++;
			}
		}
	}
	result = 9999999;

	pick_none(0, 0);
	printf("%d", result);
	

	


	return 0;
}