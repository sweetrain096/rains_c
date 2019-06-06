#include <stdio.h>
#include <malloc.h>
int v , e;
int k;
int **graph;
int u , w , v;
int main(void) {
	freopen("1753_input.txt" , "r" , stdin);
	scanf("%d %d" , &v , &e);
	graph = (int **) malloc(sizeof(int *) * v);
	graph[0] = (int *) malloc(sizeof(int) * v*v);
	for(int i = 1; i<v; i++) {
		graph[i] = graph[i-1]+v;
	}


	scanf("%d" , &k);




	free(graph[0]);
	free(graph);
}