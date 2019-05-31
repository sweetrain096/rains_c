#include <stdio.h>
#include <malloc.h>
int tc;
char data[60];
int rc;//오른쪽 괄호 카운트

typedef struct st {
	char data;
	struct st *prev;
	struct st *next;
}node;

node *head;
node *tail;

void init() {
	char tmp_input;
	int i = 0;
	tmp_input = data[0];
	node* t = (node*) malloc(sizeof(node));
	t->prev = NULL;
	head = t;
	while(tmp_input!='\0') {
		t->data = tmp_input;
		tmp_input = data[i++];
		if(tmp_input=='\0') break;
		t->next = (node*) malloc(sizeof(node));
		t->next->prev = t;
		t = t->next;
	}
	t->next = NULL;
	tail = t;

}

int pop() {
	node *now;
	node *delete_node;
	now = tail;
	if(now->data=='(') return 0;
	while(now->prev!=NULL) {
		delete_node = now;
		if(now->data==')') rc++;
		else rc--;

		if(rc<0) return 0;

		now->prev->next = NULL;
		now = now->prev;
		free(delete_node);
	}
	if(rc==0) return 1;
	else return 0;
}


int main(void) {
	freopen("9012_input.txt" , "r" , stdin);
	scanf("%d" , &tc);
	for(int i = 0; i<tc; i++) {
		data[0] = '\0';
		scanf("%s" , &data);
		rc = 0;
		init();
		if(pop()==1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}