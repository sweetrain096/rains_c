#include <stdio.h>
int a[3] = { 1, 2, 3 };      // ������ ��� a�迭
int b[3];          // �����Ͽ� ���� ���� b�迭
int N = 3;      // ������ 3��
void DFS(int no)    //no�� ����(a�迭�� index)
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
	//1] �������� : N��°�̸� �μ��� ����
	//2] ���籸���� ����(b�迭�� ���)
	//3] ���� ������ ���� �ʱ�(b�迭�� ���� �ʱ�)
}
int main(void)
{
	DFS(0);   //a[0]�� �������� ����
}