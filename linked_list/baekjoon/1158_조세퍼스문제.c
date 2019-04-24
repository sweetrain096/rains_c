#include <stdio.h>
#include "malloc.h"
int n, k;
int wp, rp;

typedef struct node {
	int data;
	struct node *next;
}node;	//구조체 생성
node *head;
node *tail;

void insert_node() {	//1부터 n까지의 리스트
	int i;
	node *t = (node*)malloc(sizeof(node));
	t->data = 1;
	head = t;
	for (i = 2; i <= n; i++) {
		t->next = (node*)malloc(sizeof(node));
		t = t->next;
		t->data = i;
	}
	tail = t;	//tail을 저장해둔다. 시작위치가 0번부터시작하기 때문에 k칸 이동처리를 tail부터 하면 관리가 쉽다.
	t->next = head;
}

void delete_next(node *t) {
	node *d;
	d = t->next;	//d는 그냥 data의 free를 위해 쓰는것같다.
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
	while (t != t->next) {	//data가 한개만 남으면 그것의 next도 자기 자신이기 때문에 break;
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