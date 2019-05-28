#include <stdio.h>
#include <malloc.h>

int n;
char order;
char predata[100010];
typedef struct node {
	char data;
	struct node *next;
	struct node *pre;
}node;
node *cursor;

void init() {
	node *t = (node *) malloc(sizeof(node*));
	char now = predata[0];
	int i = 0;
	/*t->data = now;
	t->next = (node *) malloc(sizeof(node*));
	t->next->pre = t;
	t = t->next;
	now = predata[++i];*/

	while(now!='\0') {
		t->data = now;
		t->next = (node *) malloc(sizeof(node*));
		t->next->pre = t;
		t = t->next;
		now = predata[++i];
	}
	t->next = cursor;
	cursor->pre = t;
}


int main(void) {
	freopen("1406_input.txt" , "r" , stdin);
	scanf("%s" , &predata);
	init();
	scanf("%d" , &n);
	for(int i = 0; i<n; i++) {
		scanf("%c" , &order);

	}



	return 0;
}