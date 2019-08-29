#include <stdio.h>
#include <malloc.h>

int n, m, v;
int **Map;
int x, y;
int *dfs_visit;
int *bfs_visit;
int *Q;
int rp, wp;

void DFS(int v) {
	for (int i = 1; i <= n; i++) {
		if (Map[v][i] == 1 && dfs_visit[i] != 1) {
			dfs_visit[i] = 1;
			printf("%d ", i);
			DFS(i);
		}
		
	}
}

void BFS(int v) {
	int now;
	Q[wp++] = v;
	bfs_visit[v] = 1;
	while (rp < wp) {
		now = Q[rp++];
		printf("%d ", now);
		for (int i = 1; i <= n; i++) {
			if (Map[now][i] == 1 && bfs_visit[i] != 1) {
				Q[wp++] = i;
				bfs_visit[i] = 1;
			}
		}
	}
}

int main(void) {
	freopen("1260_input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &v);
	Map = (int**)malloc(sizeof(int*) * (n + 1));
	dfs_visit = (int*)malloc(sizeof(int) * (n + 1));
	bfs_visit = (int*)malloc(sizeof(int) * (n + 1));
	Q = (int*)malloc(sizeof(int)*(2 * n));
	for (int i = 1; i <= n; i++) {
		Map[i] = (int*)malloc(sizeof(int) * (n + 1));
	}
	for (int cnt = 0; cnt < m; cnt++) {
		scanf("%d %d", &x, &y);
		Map[x][y] = 1;
		Map[y][x] = 1;
	}

	dfs_visit[v] = 1;
	printf("%d ", v);
	DFS(v);
	rp = wp = 0;
	printf("\n");
	BFS(v);



	for (int i = 0; i < n + 1; i++) {
		free(Map[i]);
	}
	free(Map);
	free(dfs_visit);
	free(bfs_visit);
	free(Q);
	return 0;
}