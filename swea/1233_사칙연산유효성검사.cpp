#include <stdio.h>
int n, half;
int number, l, r;
char data;
typedef struct Tree {
	char data;
	int left, right;
}Tree;

Tree tree[210];
char formula[210];
int index;
int result;

void inorder(int node) {
	if (node) {
		inorder(tree[node].left);
		formula[index++] = tree[node].data;
		inorder(tree[node].right);
	}
}

int main(void) {
	freopen("1233_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &n);
		half = n / 2;
		tree[210];
		
		for (int num = 1; num <= n; num++) {
			if (num < half) {
				scanf("%d %c %d %d", &number, &data, &l, &r);
				tree[num].data = data;
				tree[num].left = l;
				tree[num].right = r;
			}
			else if (num == half) {
				if (n % 2) {
					scanf("%d %c %d %d", &number, &data, &l, &r);
					tree[num].data = data;
					tree[num].left = l;
					tree[num].right = r;
				}
				else {
					scanf("%d %c %d", &number, &data, &l);
					tree[num].data = data;
					tree[num].left = l;
					tree[num].right = 0;
				}
			}
			else {
				scanf("%d %c", &number, &data);
				tree[num].data = data;
				tree[num].left = 0;
				tree[num].right = 0;
			}
			//printf("%d %c %d %d\n", num, tree[num].data, tree[num].left, tree[num].right);
		}
		
		index = 0;
		inorder(1);
		result = 1;
		for (int i = 0; i < index; i++) {
			if (i % 2) {
				if (formula[i] != '+' && formula[i] != '-' && formula[i] != '*' && formula[i] != '/') {
					result = 0;
					break;
				}
			}
			else {
				if (formula[i] < '0' || formula[i]>'9') {
					result = 0;
					break;
				}
			}
		}
		printf("#%d %d\n", tc, result);

	}
	return 0;
}