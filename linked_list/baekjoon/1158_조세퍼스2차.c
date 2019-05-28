#include <stdio.h>
#include <malloc.h>

int n , k;

typedef struct node {
	int data;
	struct node *next;
}node;//sturct node라는 것을 하나의 def로 사용하기 위해 typedef 사용
node *head;
node *tail;
//이후 head와 tail을 각각 불러오는 하나의 변수처럼 사용하기 위해서 처음 생성해줌

void insert() {
	node *t = (node *) malloc(sizeof(node));
	//새롭게 값이 들어갈 하나의 node를 t라는 이름으로 만들어버린다.
	t->data = 1;//그 node에 맨 처음 데이터 값을 1로 입력한다.
	head = t;//head의 역할을 맨 처음 1이 할 것이기 때문
	for(int i = 2; i<=n; i++) {
		t->next = (node *) malloc(sizeof(node)); //t라는 node의 next를 바로바로 만들어서 넣어준다.
		t = t->next;//t의 next에 연결된 것을 다시 t로 치환한다.
		t->data = i;//새로 연결된 다음 node에 새롭게 data를 넣는다.
	}
	t->next = head;	//마지막에 연결된 t의 next를 head node로 연결한다.
	tail = t; // 마지막에 연결된 node의 주소를 tail에 넣는다.
}


void start() {
	node *t = tail;//k칸씩 이동하게 될 때 tail부터 이동해야만 계산이 용이하다.
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