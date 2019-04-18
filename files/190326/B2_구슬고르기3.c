#include <stdio.h>
int a[3] = { 1, 2, 3 }; // 구슬
int b[3];     // 구슬을 담을 상자
int chk[3];     // 체크배열
int N = 3;      // 구슬은 3개
void DFS(int no)
{
	//1] 리턴조건 : 3개를 고른후 인쇄후 리턴
	//2] a배열에서 0부터 N전까지 고르는 모든 경우(단 구슬의 중복을 배제)
	if (no == N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		if (chk[i] != 0) continue;
		b[no] = a[i];
		chk[i] = 1;
		DFS(no + 1);
		b[no] = 0;
		chk[i] = 0;
	}
}
int main(void)
{
	DFS(0);
}