# include <stdio.h>
# include "malloc.h"

struct node {	// 연결 리스트 구조체
	struct node *next;	// 다음 노드 주소 저장 포인터
	int data;			// 데이터 저장할 멤버
};

void add_node(struct node *target, int data) {
	if (target == NULL) return; // 기준 노드가 NULL이면 함수 종료

	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) return;	//메모리 할당에 실패하면 함수 종료
	new_node->next = target->next;
	new_node->data = data;
	target->next = new_node;
}

int main() {
	struct node *head = malloc(sizeof(struct node));	//머리 노드 생성

	head->next = NULL;

	add_node(head, 10);
	add_node(head, 20);
	add_node(head, 30);


	struct node *curr = head->next;	//순회용 포인터
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}

	//데이터 해제
	//추가할 때 따로 노드의 포인터를 저장하지 않아서 while로 순회하여 해제한다.
	curr = head->next;
	while (curr != NULL) {
		struct node *next = curr->next;
		free(curr);
		curr = curr->next;
	}

	free(head);
	return 0;
}