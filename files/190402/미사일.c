# include <stdio.h>
int n;
int data[20][2];
int m_n, m_fire, m_range;//m_n : 미사일수, m_fire : 화력, m_range : 화력범위
int index[5];
int en[20], tmp[20]; // 에너지만 따로 적기
int result;


int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}
int min(int a, int b) {
	if (a <= b) return a;
	else return b;
}
void find_min() {
	int nr, nc, t_r, t_c, cnt = 0;
	

	for (int i = 0; i < m_n; i++) {
		nr = data[index[i]][0];
		nc = data[index[i]][1];
		//tmp[index[i]] -= m_fire;
		for (int j = 0; j < n; j++) {
			if (index[i] == j && tmp[j] == 0) return;
			t_r = data[j][0];
			t_c = data[j][1];
			if (abs(nr - t_r) + abs(nc - t_c) > m_range) continue;
			
			tmp[j] -= m_fire;
		}

		//printf("%d ", index[i]);
	}
	//printf("\n");
	for (int i = 0; i < n; i++) {
		if (tmp[i] > 0) cnt += 1;
		//printf("%d ", tmp[i]);
	}
	//printf(" %d\n", cnt);
	result = min(result, cnt);

}


void comb(int k, int cnt) {
	if (cnt == m_n) {
		for (int i = 0; i < n; i++) {
			tmp[i] = en[i];
		}
		find_min();
		return;
	}
	for (int i = k; i < n; i++) {
		index[cnt] = i;
		comb(i, cnt + 1);
		index[cnt] = 0;
	}
}

int main() {
	freopen("미사일_input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &data[i][0], &data[i][1], &en[i]);
	}
	scanf("%d %d %d", &m_n, &m_fire, &m_range);
	result = 9999999;
	comb(0, 0);
	printf("%d", result);
	return 0;
}