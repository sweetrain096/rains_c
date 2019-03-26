# include <stdio.h>

int map[110][110];
int R, C;
int sr, sc, er, ec;
struct st { // ť ����ü ����
	int r, c, time;
};
struct st Q[110 * 110];	//ť �迭�� ���� �ִ� ũ��
int rp, wp;	// ť���� ���� ��ġ, �� ��ġ

void InQue(int r, int c, int time) {	// ť�� �����Լ�
	Q[wp].r = r;
	Q[wp].c = c;
	Q[wp].time = time;
	wp++;
}
int BFS(void) {
	int nr, nc;
	int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
	rp = wp = 0;
	struct st data; // ť���� ���� ������
	InQue(sr, sc, 0);//1]ť�� �������� ����
	map[sr][sc] = 1; // �湮ǥ��
	while (rp < wp) { //ť�� �����Ͱ� ���� ���� �ݺ�
		data = Q[rp++];//2] ť���� ������ �б�
		if (data.r == er && data.c == ec) return data.time;
		//3] ���Ž���ϸ鼭 ������(��)�� ã�� ť�� ����
		for (int i = 0; i < 4; i++) {
			nr = data.r + dr[i];
			nc = data.c + dc[i];
			if (nr < 1 || nr>R || nc < 1 || nc > C) continue; //�� ���� ����� ��ŵ
			if (map[nr][nc] != 0) continue; // ���� �ƴϸ� ��ŵ
			InQue(nr, nc, data.time + 1);
			map[nr][nc] = 1;
		}
	}
	return -1;		//4] ť�� ����� ���
}

int main(void) {
	int i, j, sol;
	scanf("%d %d", &C, &R);//���� ����
	scanf("%d %d %d %d", &sc, &sr, &ec, &er);//���� ����
	
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	sol = BFS();
	printf("%d", sol);
}