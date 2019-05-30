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
		if(tmp==pp && max_data==pp->data) break;
		printf("%d  " , tmp->data);
		if(max_data==-1) {
			for(int i = 9; i>=0; i--) {
				if(list[i]!=0) max_data = i;
				break;
			}
		}
		if(tmp->data==max_data) {
			printf("in");
			delete_node = tmp;
			tmp = tmp->next;
			prev->next = tmp;
			free(delete_node);
			list[max_data] -= 1;
			cnt++;
		}
		else {
			prev = tmp;
			tmp = tmp->next;
		}
		printf("list: %d, max: %d\n" , list[max_data], max_data);
		if(list[max_data]==0) max_data = -1;
		

	}
	printf("print:ok");
	return ++cnt;
}

void free_data() {
	node *tmp = head;
	node *delete_node;
	while(tmp!=NULL) {
		delete_node = tmp;
		printf("%d" , tmp->data);
		if(tmp->next==tmp) {
			break;
		}
		tmp = tmp->next;
		free(delete_node);
	}
	free(tmp);
	print("ok\n");
}

int main(void) {
	freopen("1966_input.txt" , "r" , stdin);
	scanf("%d" , &tc);
	for(int i = 0; i<tc; i++) {
		printf("start");
		for(int j = 0; j<10; j++) list[j] = 0;
		max_data = 0;
		cnt = 0;
		scanf("%d %d" , &n , &index);
		init(n);
		printf("%d\n" , print());
		//free_data();
	}

	return 0;
}