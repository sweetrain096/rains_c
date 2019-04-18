# include <stdio.h>
# include "malloc.h"

struct node {	// 연결 리스트 구조체
	struct node *next;	// 다음 노드 주소 저장 포인터
	int data;			// 데이터 저장할 멤버
};

int main() {
	struct node *head = malloc(sizeof(struct node));	//머리 노드 생성

	struct node *node1 = malloc(sizeof(struct node));
	head->next = node1;
	node1->data = 10;

	struct node *node2 = malloc(sizeof(struct node));
	node1->next = node2;
	node2->data = 20;

	node2->next = NULL;

	struct node *curr = head->next;	//순회용 포인터
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	free(node2);
	free(node1);
	free(head);
	return 0;
}