#include <stdio.h>

int TC;
int n, m;
int me, you;
int visited[101] = { 0, };
int result;

typedef struct P {
	int idx = 0;
	int know[101];
};
P people[101];


void make_team(int i) {
	visited[i] = 1;
	int temp;
	for (int j = 0; j < people[i].idx; j++) {
		temp = people[i].know[j];
		if (visited[temp] == 1) continue;
		make_team(temp);
	}
	for (int j = 0; j < people[i].idx; j++) people[i].know[j] = 0;
	people[i].idx = 0;
}

int main(void) {
	freopen("7456_input.txt", "r", stdin);
	scanf("%d ", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		
		result = 0;
		scanf("%d %d ", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d ", &me, &you);
			people[me].know[people[me].idx] = you;
			people[me].idx++;

			people[you].know[people[you].idx] = me;
			people[you].idx++;
		}

		for (int i = 1; i <= n; i++) {
			if (people[i].idx != 0) {
				make_team(i);
				result++;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 1) continue;
			result++;
		}

		
		
		printf("#%d %d\n", tc, result);
		for (int i = 0; i <= n; i++) {
			visited[i] = 0;
			for (int j = 0; j <= people[i].idx; j++) people[i].know[j] = 0;
			people[i].idx = 0;
		}
		
	}



	return 0;
}