#include <stdio.h>
#include <malloc.h>

int n , k;

typedef struct node {
	int data;
	struct node *next;
}node;//sturct node��� ���� �ϳ��� def�� ����ϱ� ���� typedef ���
node *head;
node *tail;
//���� head�� tail�� ���� �ҷ����� �ϳ��� ����ó�� ����ϱ� ���ؼ� ó�� ��������

void insert() {
	node *t = (node *) malloc(sizeof(node));
	//���Ӱ� ���� �� �ϳ��� node�� t��� �̸����� ����������.
	t->data = 1;//�� node�� �� ó�� ������ ���� 1�� �Է��Ѵ�.
	head = t;//head�� ������ �� ó�� 1�� �� ���̱� ����
	for(int i = 2; i<=n; i++) {
		t->next = (node *) malloc(sizeof(node)); //t��� node�� next�� �ٷιٷ� ���� �־��ش�.
		t = t->next;//t�� next�� ����� ���� �ٽ� t�� ġȯ�Ѵ�.
		t->data = i;//���� ����� ���� node�� ���Ӱ� data�� �ִ´�.
	}
	t->next = head;	//�������� ����� t�� next�� head node�� �����Ѵ�.
	tail = t; // �������� ����� node�� �ּҸ� tail�� �ִ´�.
}


void start() {
	node *t = tail;//kĭ�� �̵��ϰ� �� �� tail���� �̵��ؾ߸� ����� �����ϴ�.
	node *d;
	printf("<");
	while(t->next!=t) {
		for(int i = 0; i<k-1; i++) {
			t = t->next;
		}
		d = t->next;
		printf("%d, " , d->data);
		t->next = d->next;
		free(d);
	}
	printf("%d>" , t->data);
}

int main(void) {
	freopen("1158_input.txt" , "r" , stdin);
	scanf("%d %d" , &n , &k);
	insert();
	start();
	return 0;
}