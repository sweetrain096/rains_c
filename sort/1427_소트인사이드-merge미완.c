#include <stdio.h>
char string[20];
int data[20];





int main(void) {
	freopen("1427_input.txt" , "r" , stdin);
	scanf("%s" , &string);
	char now = string[0];
	int i = 0;
	while(now!='\0') {
		data[i] = now;
		now = string[i+1];
		i++;
	}

	for(int j = 0; j<i; j++) {
		printf("%c" , data[j]);
	}
}