//���� ���� n(10�� ����), ���� ���� m�� �־��� �� m���� �ٿ� �� ������ ��ȣ�� �־�����.
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