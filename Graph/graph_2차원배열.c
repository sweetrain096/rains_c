//정점 개수 n(10개 이하), 간선 개수 m가 주어진 후 m개의 줄에 두 정점의 번호가 주어진다.
#include <stdio.h>
int n , m;
int graph[15][15];
int pre , next;

int main(void) {
	freopen("graph_input.txt" , "r" , stdin);
	scanf("%d %d" , &n , &m);
	for(int i = 0; i<m; i++) {
		scanf("%d %d" , &pre , &next);
		graph[pre][next] = 1;
		graph[next][pre] = 1;
	}

	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=n; j++) {
			printf("%d " , graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}