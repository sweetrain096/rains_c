#include <stdio.h>
int w , h;
int data[60][60];
int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cnt;

void DFS(int row, int col) {
	data[row][col] = 0;
	for(int k = 0; k<8; k++) {
		int nr = dr[k] , nc = dc[k];
		//printf("row, col: %d, %d" , row , col);
		if(row+nr<0||row+nr>=h||col+nc<0||col+nc>=w) continue;
		if(data[row+nr][col+nc]==0) continue;
		DFS(row+nr , col+nc);
	}
}

int main(void) {
	freopen("4963_input.txt" , "r" , stdin);
	scanf("%d %d" , &w , &h);
	while(w+h!=0) {
		for(int i = 0; i<60; i++) {
			for(int j = 0; j<60; j++) {
				if(data[i][j]==-1) break;
				data[i][j] = -1;
			}
		}
		for(int i = 0; i<h; i++) {
			for(int j = 0; j<w; j++) {
				scanf("%d" , &data[i][j]);
			}
		}

		//dfs
		cnt = 0;
		for(int i = 0; i<h; i++) {
			for(int j = 0; j<w; j++) {
				if(data[i][j]==1) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n" , cnt);
		scanf("%d %d" , &w , &h);
	}
	
	return 0;
}