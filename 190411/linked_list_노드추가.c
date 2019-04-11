# include <stdio.h>
# include "malloc.h"

struct node {	// ���� ����Ʈ ����ü
	struct node *next;	// ���� ��� �ּ� ���� ������
	int data;			// ������ ������ ���
};

void add_node(struct node *target, int data) {
	if (target == NULL) return; // ���� ��尡 NULL�̸� �Լ� ����

	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) return;	//�޸� �Ҵ翡 �����ϸ� �Լ� ����
	new_node->next = target->next;
	new_node->data = data;
	target->next = new_node;
}

int main() {
	struct node *head = malloc(sizeof(struct node));	//�Ӹ� ��� ����

	head->next = NULL;

	add_node(head, 10);
	add_node(head, 20);
	add_node(head, 30);


	struct node *curr = head->next;	//��ȸ�� ������
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}

	//������ ����
	//�߰��� �� ���� ����� �����͸� �������� �ʾƼ� while�� ��ȸ�Ͽ� �����Ѵ�.
	curr = head->next;
	while (curr != NULL) {
		struct node *next = curr->next;
		free(curr);
		curr = curr->next;
	}

	free(head);
	return 0;
}