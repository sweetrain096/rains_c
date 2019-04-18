#include <stdio.h>
int a[3] = { 1, 2, 3 };      // 구슬이 담긴 a배열
int b[3];          // 조합하여 담을 상자 b배열
int N = 3;      // 구슬은 3개
void DFS(int no)    //no는 구슬(a배열의 index)
{	
	if (no == N) {
		printf("%d %d %d\n", b[0], b[1], b[2]);
		return;
	}
	for (int i = 1; i >= 0; i--) {
		if (i == 1) {
			b[no] = a[no];
		}
		else {
			b[no] = 0;
		}
		DFS(no + 1);
		b[no] = 0;
	}
	//1] 리턴조건 : N번째이면 인쇄후 리턴
	//2] 현재구슬을 고르기(b배열에 담기)
	//3] 현재 구슬을 고르지 않기(b배열에 담지 않기)
}
int main(void)
{
	DFS(0);   //a[0]번 구슬부터 조합
}