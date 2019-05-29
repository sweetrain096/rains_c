#include <stdio.h>
#include <malloc.h>

char data[100010];
int n;
char order , plus_data;
typedef struct node {
	char data;
	struct node *pre;
	struct node *next;
}node;
node *head;
node *tail;
node *cursor;

void init() {
	char tmp_data = data[0];
	int i = 0;
	node *t = (node *) malloc(sizeof(node));
	t->pre = NULL;
	t->data = '\0';
	head = t;
	while(tmp_data!='\0') {
		t->data = tmp_data;
		tmp_data = data[++i];
		t->next = (node *) malloc(sizeof(node));
		t->next->pre = t;
		t = t->next;
	}
	t->data = '0';
	t->next = NULL;
	cursor = t;
	tail = t;
}
void print() {
	node *tmp;
	tmp = head;
	while(tmp->data!='0') {
		printf("%c" , tmp->data);
		//if(tmp==cursor) printf("!");
		tmp = tmp->next;
	}
}

void move_left() {
	if(cursor==head) return;
	cursor = cursor->pre;
}

void move_right() {
	if(cursor==tail) return;
	cursor = cursor->next;
}

void delete() {
	if(cursor==head) return;
	if(cursor->pre==head) {
		cursor->pre = NULL;
		head = cursor;
		free(cursor->pre);
	}
	else {
		node *tmp;
		tmp = cursor->pre;
		cursor->pre = tmp->pre;
		tmp->pre->next = cursor;
		free(tmp);
	}
}

void insert(char add) {
	node *add_node = (node*) malloc(sizeof(node));
	add_node->data = add;
	if(head==cursor) {
		add_node->pre = NULL;
		add_node->next = cursor;
		cursor->pre = add_node;
		head = add_node;
	}
	else {
		add_node->pre = cursor->pre;
		add_node->next = cursor;
		add_node->pre->next = add_node;
		cursor->pre = add_node;

	}
}

int main(void) {
	freopen("1406_input.txt" , "r" , stdin);
	scanf("%s" , &data);
	init();
	//print();

	scanf("%d" , &n);
	for(int i = 0; i<n; i++) {
		scanf(" %c" , &order);
		if(order=='L') move_left();
		else if(order=='D') move_right();
		else if(order=='B') delete();
		else {
			scanf(" %c" , &plus_data);
			insert(plus_data);
		}
	}
	print();

	return 0;
}