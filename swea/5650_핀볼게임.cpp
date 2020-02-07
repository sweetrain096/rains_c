#include <stdio.h>

int TC;
int n;
int map[100][100];
// ������ ������� ��, ��, ��, �� == 0, 1, 2, 3
int deg[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int CNT;

int is_wall(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) return 1;
	return 0;
}

int Run(int r, int c, int dir) {
	int cnt = 0;
	int dr = deg[dir][0];
	int dc = deg[dir][1];
	int nr = r;
	int nc = c;
	while (1) {
		nr += dr;
		nc += dc;
		if (nr == r && nc == c) return cnt;
		// ���� ����� ��
		if (is_wall(nr, nc)) {
			cnt = cnt * 2 + 1;
			return cnt;
		}
		// �ƹ��͵� ���� ��
		if (map[nr][nc] == 0) continue;

		// ����� ���� ��
		if (map[nr][nc] >= 1 && map[nr][nc] <= 5) {
			

			if (map[nr][nc] == 1) {
				if (dir == 0) dir = 1;
				else if (dir == 3) dir = 2;
				else {
					cnt = cnt * 2 + 1;
					return cnt;
				}
			}
			else if (map[nr][nc] == 2) {
				if (dir == 1) dir = 2;
				else if (dir == 0) dir = 3;
				else {
					cnt = cnt * 2 + 1;
					return cnt;
				}
			}
			else if (map[nr][nc] == 3) {
				if (dir == 2) dir = 3;
				else if (dir == 1) dir = 0;
				else {
					cnt = cnt * 2 + 1;
					return cnt;
				}
			}
			else if (map[nr][nc] == 4) {
				if (dir == 2) dir = 1;
				else if (dir == 3) dir = 0;
				else {
					cnt = cnt * 2 + 1;
					return cnt;
				}
			}
			else {
				cnt = cnt * 2 + 1;
				return cnt;
			}
			cnt++;
			dr = deg[dir][0];
			dc = deg[dir][1];
		}
		// ��Ȧ�� ���� ��
		else if (map[nr][nc] == -1) return cnt;
		// ��Ȧ�� ���� ��
		else {
			int flag = 1;
			for (int i = 0; i < n; i++) {
				if (flag == 0) break;
				for (int j = 0; j < n; j++) {
					if (flag == 0) break;
					if (map[i][j] == map[nr][nc]) {
						if (i != nr || j != nc) {
							nr = i;
							nc = j;
							flag = 0;
						}
					}
				}
			}
		}
	}
}

int main(void) {
	freopen("5650_input.txt", "r", stdin);
	scanf("%d ", &TC);
	int cnt;
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d ", &n);
		CNT = 0;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				scanf("%d ", &map[r][c]);
			}
		}
		/*for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				printf("%d ", map[r][c]);
			}
			printf("\n");
		}*/
		int dir;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				if (map[r][c] == 0) {
					for (int i = 0; i < 4; i++) {
						//printf("%d %d %d ", r, c, i);
						cnt = Run(r, c, i);
						//printf("%d\n", cnt);
						if (cnt > CNT) CNT = cnt;
					}
				}
			}
		}
		printf("#%d %d\n", tc, CNT);
	}
	return 0;
}