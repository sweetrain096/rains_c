#include <stdio.h>
#include <string.h>


int T, N;
char name_list[20000][52];
int index_list[20000];
int min_index, temp;

int main(void) {
	freopen("7701_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) scanf("%s", name_list[i]), index_list[i] = i;

		for (int i = 0; i < N - 1; i++) {
			min_index = i;
			for (int j = i + 1; j < N; j++) {
				if (strcmp(name_list[index_list[min_index]], name_list[index_list[j]]) > 0) min_index = j;
			}
			if (min_index == i) continue;
			temp = index_list[i];
			index_list[i] = index_list[min_index];
			index_list[min_index] = temp;
		}
		printf("#%d\n", tc);
		for (int i = 0; i < N; i++) {
			if (i != 0 && strcmp(name_list[index_list[i]], name_list[index_list[i - 1]])==0)continue;
			printf("%s\n", name_list[index_list[i]]);
		}

	}
	
	return 0;
}



