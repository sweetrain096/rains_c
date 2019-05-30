#include <stdio.h>
int n , input_data;
char order[10];
int rp , wp;
struct st {
	int data;
};

struct st Q[100010];

void push(int inputData) {
	Q[wp].data = inputData;
	wp++;
}
int pop() {
	if(Q[rp].data==NULL) return -1;
	else {
		int tmp = Q[rp].data;
		Q[rp].data = NULL;
		rp++;
		return tmp;
	}
}
int size() {
	return wp-rp;
}
int empty() {
	if(wp-rp==0) return 1;
	else return 0;
}
int front() {
	if(Q[rp].data==NULL) return -1;
	else return Q[rp].data;
}
int back() {
	if(Q[wp-1].data==NULL) return -1;
	else return Q[wp-1].data;
}


int main(void) {
	freopen("10845_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	rp = wp = 0;
	for(int i = 0; i<n; i++) {
		scanf("%s" , &order);
		if(order[1]=='u') {//push
			scanf("%d" , &input_data);
			push(input_data);
		}
		else if(order[1]=='o') printf("%d\n", pop());//pop
		else if(order[1]=='i') printf("%d\n", size());//size
		else if(order[1]=='m') printf("%d\n", empty());//empty
		else if(order[1]=='r') printf("%d\n", front());//front
		else printf("%d\n", back());//back
	}
	return 0;
}