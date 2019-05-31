#include <stdio.h>
#include <malloc.h>

int list[10];

int tc , n , index;
int max_data;
int cnt;

typedef struct node {
	int data;
	struct node *next;
}node;
node *head;
node *tail;
node *pp;//print point

void init(int n) {
	int tmp_input;
	node *t = (node *) malloc(sizeof(node));
	head = t;
	for(int i = 0; i<n; i++) {
		scanf("%d" , &tmp_input);
		list[tmp_input] += 1;
		t->data = tmp_input;
		if(i==index) {
			pp = t;
		}
		if(i==n-1) break;
		t->next = (node *) malloc(sizeof(node));
		t = t->next;
	}
	tail = t;
	t->next = head;
	
	for(int i = 9; i>=0; i--) {
		if(list[i]!=0) {
			max_data = i;
			break;
		}
	}
}
int print() {
	node *tmp = head;
	node *prev = tail;
	node *check = head;
	node *delete_node;
	while(1) {
		if(max_data==-1) {
			for(int i = 9; i>=0; i--) {
				if(list[i]!=0) {
					max_data = i;
					break;
				}
			}
		}
		if(tmp==pp && max_data==pp->data) break;
		if(tmp->data==max_data) {
			delete_node = tmp;
			if(tmp==tmp->next) break;
			prev->next = tmp->next;
			tmp = tmp->next;
			if(delete_node==tail) tail = prev;
			if(delete_node==head) head = tmp;
			free(delete_node);
			list[max_data] -= 1;
			cnt++;
		}
		else {
			prev = tmp;
			tmp = tmp->next;
		}
		if(list[max_data]==0) max_data = -1;
		

	}
	return ++cnt;
}

void free_data() {
	node *tmp = head;
	node *delete_node;
	while(tmp!=NULL) {
		delete_node = tmp;
		if(tmp->next==tmp || tmp == tail) {
			break;
		}
		tmp = tmp->next;
		free(delete_node);
		//printf("check\n");
	}
	free(tmp);
	//printf("ok\n");
}

int main(void) {
	freopen("1966_input.txt" , "r" , stdin);
	scanf("%d" , &tc);
	for(int i = 0; i<tc; i++) {
		for(int j = 0; j<10; j++) list[j] = 0;
		max_data = 0;
		cnt = 0;
		scanf("%d %d" , &n , &index);
		init(n);
		printf("%d\n" , print());
		free_data();
	}

	return 0;
}