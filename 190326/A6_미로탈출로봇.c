# include <stdio.h>

int map[110][110];
int R, C;
int sr, sc, er, ec;
struct st { // 큐 구조체 설계
	int r, c, time;
};
struct st Q[110 * 110];	//큐 배열은 맵의 최대 크기
int rp, wp;	// 큐에서 읽을 위치, 쓸 위치

void InQue(int r, int c, int time) {	// 큐에 저장함수
	Q[wp].r = r;
	Q[wp].c = c;
	Q[wp].time = time;
	wp++;
}
int BFS(void) {
	int nr, nc;
	int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
	rp = wp = 0;
	struct st data; // 큐에서 꺼낼 데이터
	InQue(sr, sc, 0);//1]큐에 시작점을 저장
	map[sr][sc] = 1; // 방문표시
	while (rp < wp) { //큐에 데이터가 있을 동안 반복
		data = Q[rp++];//2] 큐에서 데이터 읽기
		if (data.r == er && data.c == ec) return data.time;
		//3] 사방탐색하면서 연결점(길)을 찾아 큐에 저장
		for (int i = 0; i < 4; i++) {
			nr = data.r + dr[i];
			nc = data.c + dc[i];
			if (nr < 1 || nr>R || nc < 1 || nc > C) continue; //맵 범위 벗어나면 스킵
			if (map[nr][nc] != 0) continue; // 길이 아니면 스킵
			InQue(nr, nc, data.time + 1);
			map[nr][nc] = 1;
		}
	}
	return -1;		//4] 큐가 비었을 경우
}

int main(void) {
	int i, j, sol;
	scanf("%d %d", &C, &R);//가로 세로
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);//시작 도착
	
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	sol = BFS();
	printf("%d", sol);
}