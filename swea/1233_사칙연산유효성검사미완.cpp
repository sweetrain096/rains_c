#include <stdio.h>
int n;
int number, l, r;
char data;
typedef struct Tree {
	int n;
	char oper;
	int data;
	int left, right;
}Tree;

int tree[210];


int main(void) {
	freopen("1233_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &n);
		Tree tree[210];
		
		for (int num = 1; num <= n; num++) {
			scanf("%d %c", &number, &data);
			if (data == 45 || data == 43 || data == 42 || data == 47) {
				tree[num].oper = data;
				tree[num].data = 0;
				scanf("%d %d", &tree[num].left, &tree[num].right);
			}
			else {
				tree[num].data = 1;
				tree[num].oper = NULL;
				tree[num].left = 0;
				tree[num].right = 0;
			}
		}
		
	}
	return 0;
}