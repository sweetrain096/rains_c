#include <stdio.h>
#include "malloc.h"
int n, k;
int wp, rp;

typedef struct node {
	int data;
	struct node *next;
}node;	//����ü ����
node *head;
node *tail;

void insert_node() {	//1���� n������ ����Ʈ
	int i;
	node *t = (node*)malloc(sizeof(node));
	t->data = 1;
	head = t;
	for (i = 2; i <= n; i++) {
		t->next = (node*)malloc(sizeof(node));
		t = t->next;
		t->data = i;
	}
	tail = t;	//tail�� �����صд�. ������ġ�� 0�����ͽ����ϱ� ������ kĭ �̵�ó���� tail���� �ϸ� ������ ����.
	t->next = head;
}

void delete_next(node *t) {
	node *d;
	d = t->next;	//d�� �׳� data�� free�� ���� ���°Ͱ���.
	if (d == NULL) {
		return 0;
	}
	t->next = t->next->next;
	free(d);
}

void start() {
	insert_node();
	node *t;
	t = tail;
	printf("<");
	while (t != t->next) {	//data�� �Ѱ��� ������ �װ��� next�� �ڱ� �ڽ��̱� ������ break;
		for (int i = 0; i < k - 1; i++) {
			t = t->next;
		}
		printf("%d, ", t->next->data);
		delete_next(t);
	}
	printf("%d>", t->data);
}

int main() {
	freopen("1158_input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	start();
	return 0;
}