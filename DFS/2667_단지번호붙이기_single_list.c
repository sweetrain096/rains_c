#include <stdio.h>
int n;
int map[30][30];
int cnts[30*30];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int cnt;

dfs(int row , int col) {
	cnt++;
	map[row][col] = 0;
	for(int k = 0; k<4; k++) {
		int nr = dr[k] , nc = dc[k];
		if(row+nr<0||row+nr>=n||col+nc<0||col+nc>=n) continue;
		if(map[row+nr][col+nc]==1) {
			dfs(row+nr , col+nc);
		}
	}

}

int main(void) {
	freopen("2667_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			scanf("%1d" , &map[i][j]);
		}
	}
	int n_cnt = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(map[i][j]==1) {
				cnt = 0;
				dfs(i , j);
				cnts[n_cnt++] = cnt;
			}
		}
	}
	int tmp;
	for(int i = 0; i<n_cnt - 1; i++) {
		for(int j = i; j<n_cnt; j++) {
			if(cnts[i]>cnts[j]) {
				tmp = cnts[i];
				cnts[i] = cnts[j];
				cnts[j] = tmp;
			}
		}
	}

	printf("%d\n" , n_cnt);
	for(int i = 0; i<n_cnt; i++) {
		printf("%d\n" , cnts[i]);
	}

}