# include <stdio.h>
# include "malloc.h"

struct node {	// ���� ����Ʈ ����ü
	struct node *next;	// ���� ��� �ּ� ���� ������
	int data;			// ������ ������ ���
};

int main() {
	struct node *head = malloc(sizeof(struct node));	//�Ӹ� ��� ����

	struct node *node1 = malloc(sizeof(struct node));
	head->next = node1;
	node1->data = 10;

	struct node *node2 = malloc(sizeof(struct node));
	node1->next = node2;
	node2->data = 20;

	node2->next = NULL;

	struct node *curr = head->next;	//��ȸ�� ������
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	free(node2);
	free(node1);
	free(head);
	return 0;
}