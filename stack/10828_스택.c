#include <stdio.h>
int n, plus;
char order[10];

int wp;
struct st {
	int data;
};
struct st Q[10010];

void push(int data) {
	Q[wp].data = data;
	wp++;
	return;
}

int pop() {
	if(wp==0) return -1;
	int now = Q[wp - 1].data;
	Q[wp-1].data = 0;
	wp--;
	return now;
}
int size() {
	return wp;
}
int empty() {
	if(wp==0) return 1;
	else return 0;
}
int top() {
	if(wp==0) return -1;
	else return Q[wp-1].data;
}
int main(void) {
	freopen("10828_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	wp = 0;
	for(int i = 0; i<n; i++) {
		scanf("%s" , &order);
		if(order[0]=='p') {
			if(order[1]=='u') {//push
				scanf("%d" , &plus);
				push(plus);
			}
			else printf("%d\n", pop());//pop
		}
		else if(order[0]=='s') printf("%d\n", size());//size
		else if(order[0]=='e') printf("%d\n", empty());//empty
		else if(order[0]=='t') printf("%d\n", top());//top
	}

	return 0;
}