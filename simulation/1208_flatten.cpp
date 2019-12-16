#include <stdio.h>
int row[100];
int n;
struct Data {
	int min, max;
	int min_index, max_index;
};
struct Data getData(int row[100]) {
	struct Data data;
	int min = 1100;
	int max = 0;
	int min_index, max_index;
	for (int i = 0; i < 100; i++) {
		if (max < row[i]) {
			max = row[i];
			max_index = i;
		}
		if (min > row[i]) {
			min = row[i];
			min_index = i;
		}
	}
	data.max = max;
	data.min = min;
	data.max_index = max_index;
	data.min_index = min_index;

	return data;
}
int main(void) {
	freopen("1208_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < 100; i++) {
			scanf("%d", &row[i]);
		}
		struct Data temp;
		for (int j = 0; j < n; j++) {
			temp = getData(row);
			row[temp.max_index]--;
			row[temp.min_index]++;
		}
		temp = getData(row);
		printf("#%d %d\n", tc, temp.max - temp.min);
	}
	return 0;
}