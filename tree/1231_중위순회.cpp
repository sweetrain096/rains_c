#include <stdio.h>

struct Node {
	int left, right;
	char text;
};
int n;
char temp[10];
int len, item;
char one;
char result[110];
int cursor;


void inorder(int node, struct Node *tree) {
	if (node) {
		inorder(tree[node].left, tree);
		result[cursor++] = tree[node].text;
		inorder(tree[node].right, tree);
	}
}

int main(void) {
	freopen("1231_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &n);
		struct Node tree[100];
		cursor = 0;
		
		for (int i = 1; i <= n; i++) {
			len = 0;
			item = 0;
			scanf(" %[^\n]", temp);
			while (temp[len] != '\0') {
				if (item == 1 && temp[len] != ' ') one = temp[len];
				if (temp[len] == ' ') item++;
				len++;
			}
			tree[i].text = one;
			if (item == 3) {
				tree[i].left = i * 2;
				tree[i].right = i * 2 + 1;
			}
			else if (item == 2) {
				tree[i].left = i * 2;
				tree[i].right = 0;

			}
			else {
				tree[i].left = 0;
				tree[i].right = 0;
			}
		}

		inorder(1, tree);
		result[cursor] = '\0';
		printf("#%d %s\n", tc, result);
	}
	return 0;
}