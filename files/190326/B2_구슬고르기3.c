#include <stdio.h>
int a[3] = { 1, 2, 3 }; // ����
int b[3];     // ������ ���� ����
int chk[3];     // üũ�迭
int N = 3;      // ������ 3��
void DFS(int no)
{
	//1] �������� : 3���� ���� �μ��� ����
	//2] a�迭���� 0���� N������ ���� ��� ���(�� ������ �ߺ��� ����)
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