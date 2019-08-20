#include <stdio.h>
int testcase;
int sx, sy, ex, ey;
int map[220][220];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int result;
typedef struct st {
	int x, y, time, deg;
}st;
st Q[220 * 220];
int rp, wp;
void Inque(int x, int y, int time, int deg) {
	Q[wp].x = x;
	Q[wp].y = y;
	Q[wp].time = time;
	Q[wp].deg = deg;
	wp++;
}
int BFS(void) {
	int nx, ny, nd;
	rp = wp = 0;
	st data;
	Inque(sx, sy, 0, 0);
	while (rp < wp) {
		data = Q[rp++];
		if (data.x == ex && data.y == ey) return data.time;
		// printf("%d %d %d %d \n", data.x, data.y, data.time, data.deg);
		for (int i = 0; i < 4; i++) {
			if (data.deg == 1 && (i == 0 || i == 1)) continue;
			if (data.deg == 2 && (i == 2 || i == 3)) continue;
			nx = data.x + dx[i];
			ny = data.y + dy[i];
			if (i <= 1) nd = 1;
			else if (i > 1) nd = 2;
			Inque(nx, ny, data.time + 1, nd);
		}
	}
}
int main(void) {
	freopen("78-1_input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++) {
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		printf("#%d ", tc); 
		result = BFS();
		printf("%d \n", result);
	}
	return 0;
}