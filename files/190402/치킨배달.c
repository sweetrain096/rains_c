# include <stdio.h>
int n, m; // m�� �����ִ� ġŲ������
int base[25][25]; // ���� ����
int hr[50], hc[50]; // ���� row, col
int cr[15], cc[15]; // ġŲ���� row, col
int cnt_h = 0; // ���� ����
int cnt_c = 0; // ġŲ�� ����
int index[15]; // ġŲ�� �ε���
int nr, nc; // find_min���� �� row, col �Ѱ���
int result; // ���� �����(�ּҰ�)

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
	
	freopen("ġŲ_input.txt", "r", stdin);
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