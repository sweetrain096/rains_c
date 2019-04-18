# include <stdio.h>
int t, n;
int graph[1010][1010];
int min;
int sum;

void make_graph(int start_node) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		//printf("%d\n", i);
		if (i == start_node) continue;
		for (j = i + 1; j < n; j++) {
			//printf("i = %d, j = %d, %d, %d, %d\n", i, j, graph[i][j], graph[i][start_node], graph[start_node][j]);
			if (graph[i][j] > graph[i][start_node] + graph[start_node][j]) {
				graph[i][j] = graph[i][start_node] + graph[start_node][j];
				graph[j][i] = graph[i][start_node] + graph[start_node][j];
			}
			//printf("i = %d, j = %d, %d, %d, %d\n", i, j, graph[i][j], graph[i][start_node], graph[start_node][j]);

		}
	}

}


int main() {
	freopen("1263_input.txt", "r", stdin);

	int tc, i, j;
	scanf("%d", &t);
	for (tc = 0; tc < t; tc++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &graph[i][j]);
				if (i != j && graph[i][j] == 0) graph[i][j] = 9999999;
			}
		}


		

		for (i = 0; i < n; i++) {
			make_graph(i);
		}


		
		min = 9999999;

		for (i = 0; i < n; i++) {
			sum = 0;
			for (j = 0; j < n; j++) {
				sum += graph[i][j];

			}
			if (min > sum) min = sum;
		}

		printf("#%d %d\n", tc + 1, min);
	}
	return 0;
}