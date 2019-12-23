#include <stdio.h>
int T;
int N;
char dir[6];
int map[20][20];
int row, col;
int index, temp;

void sort_left(void) {
	for (row = 0; row < N; row++) {
		index = -1;
		for (col = 0; col < N; col++) {
			if (map[row][col] == 0 && index == -1) index = col;
			else if (map[row][col] != 0 && index != -1) {
				map[row][index++] = map[row][col];
				map[row][col] = 0;
			}
		}
	}
}

void sort_right(void) {
	for (row = 0; row < N; row++) {
		index = N;
		for (col = N - 1; col >= 0; col--) {
			if (map[row][col] == 0 && index == N) index = col;
			else if (map[row][col] != 0 && index != N) {
				map[row][index--] = map[row][col];
				map[row][col] = 0;
			}
		}
	}
}

void sort_up(void) {
	for (col = 0; col < N; col++) {
		index = -1;
		for (row = 0; row < N; row++) {
			if (map[row][col] == 0 && index == -1) index = row;
			else if (map[row][col] != 0 && index != -1) {
				map[index++][col] = map[row][col];
				map[row][col] = 0;
			}
		}
	}
}

void sort_down(void) {
	for (col = 0; col < N; col++) {
		index = N;
		for (row = N - 1; row >= 0; row--) {
			if (map[row][col] == 0 && index == N) index = row;
			else if (map[row][col] != 0 && index != N) {
				map[index--][col] = map[row][col];
				map[row][col] = 0;
			}
		}
	}
}

int main(void) {
	freopen("6109_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %s", &N, dir);
		for (row = 0; row < N; row++) {
			for (col = 0; col < N; col++) {
				scanf("%d", &map[row][col]);
			}
		}

		// left
		if (dir[0] == 'l') {
			// 왼쪽으로 다 옮기기
			sort_left();
			
			for (col = 0; col < N - 1; col++) {
				for (row = 0; row < N; row++) {
					if (map[row][col] == map[row][col + 1]) {
						map[row][col] *= 2;
						map[row][col + 1] = 0;
					}
				}
			}

			sort_left();
		}

		// right
		else if (dir[0] == 'r') {
			// 오른쪽으로 다 옮기기
			
			sort_right();
			for (col = N - 1; col > 0; col--) {
				for (row = 0; row < N; row++) {
					if (map[row][col] == map[row][col-1]) {
						map[row][col] *= 2;
						map[row][col - 1] = 0;
					}
				}
			}
			sort_right();
		}

		// up
		else if (dir[0] == 'u') {
			// 위로 다 옮기기
			
			sort_up();
			for (row = 0; row < N - 1; row++) {
				for (col = 0; col < N; col++) {
					if (map[row][col] == map[row + 1][col]) {
						map[row][col] *= 2;
						map[row + 1][col] = 0;
					}
				}
			}
			sort_up();
		}

		// down
		else {
			// 아래로 다 내리기
			sort_down();

			for (row = N - 1; row > 0; row--) {
				for (col = 0; col < N; col++) {
					if (map[row][col] == map[row - 1][col]) {
						map[row][col] *= 2;
						map[row - 1][col] = 0;
					}
				}
			}
			sort_down();
		}

		printf("#%d\n", tc);
		for (row = 0; row < N; row++) {
			for (col = 0; col < N; col++) {
				printf("%d ", map[row][col]);
			}
			printf("\n");
		}
	}

	return 0;
}