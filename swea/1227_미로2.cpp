#include <stdio.h>

int test_num;
int maze[100][100];
int sr, sc;
int er, ec;
int rp, wp;
int nr, nc;
int drs[4] = { -1, 1, 0, 0 };
int dcs[4] = { 0, 0, -1, 1 };
int dr, dc, tr, tc;

typedef struct Queue {
	int r, c;
}Queue;
Queue Q[100*100];

void inQue(int r, int c) {
	Q[wp].r = r;
	Q[wp].c = c;
	wp++;
}



int bfs(int sr, int sc, int er, int ec) {
	inQue(sr, sc);
	while (rp < wp) {
		nr = Q[rp].r;
		nc = Q[rp].c;
		

		for (int i = 0; i < 4; i++) {
			dr = drs[i];
			dc = dcs[i];
			tr = nr + dr;
			tc = nc + dc;

			if (tr == er && tc == ec) {
				return 1;
			}

			if (maze[tr][tc] == 0) {
				inQue(tr, tc);
				maze[tr][tc] = 9;
			}
		}
		

		rp++;
	}


	return 0;
}

int main(void) {
	freopen("1227_input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &test_num);

		for (int r = 0; r < 100; r++) {
			for (int c = 0; c < 100; c++) {
				scanf("%1d", &maze[r][c]);
				if (maze[r][c] == 2) {
					sr = r;
					sc = c;
				}
				else if (maze[r][c] == 3) {
					er = r;
					ec = c;
				}
			}
		}

		rp = wp = 0;
		
		

		printf("#%d %d\n", tc, bfs(sr, sc, er, ec));
	}

	return 0;
}