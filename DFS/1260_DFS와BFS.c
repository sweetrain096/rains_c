#include <stdio.h>

int n, m;
int v;
int graph[1010][10010];
int in_row, in_col;

struct st {
	int r, c;
};

void bfs() {

}



int main(void) {
	freopen("1260_input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &in_row, &in_col);
		graph[in_row][in_col] = 1;
		graph[in_col][in_row] = 1;
	}

	return 0;
}