#include <stdio.h>
int tc;
int data[8];
int fivot;
int miner;
int main(void) {
	freopen("1225_input.txt", "r", stdin);
	
	while (scanf("%d", &tc) != EOF) {
		fivot = 0;
		miner = 1;
		for (int i = 0; i < 8; i++) {
			scanf("%d", &data[i]);
		}
		while (true) {
			data[fivot] -= miner;
			if (data[fivot] <= 0) {
				data[fivot] = 0;
				break;
			}
			fivot++;
			miner++;
			if (fivot == 8) fivot = 0;
			if (miner == 6) miner = 1;
		}
		printf("#%d ", tc);
		for (int i = 0; i < 8; i++) {
			fivot++;
			if (fivot == 8) fivot = 0;
			printf("%d ", data[fivot]);
		}
		printf("\n");
	}
	return 0;
}