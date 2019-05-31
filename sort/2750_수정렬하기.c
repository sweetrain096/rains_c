#include <stdio.h>
int n;
int data[1010];
int tmp;

int main(void) {
	freopen("2750_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	for(int i = 0; i<n; i++) {
		scanf("%d" , &data[i]);
	}

	for(int i = 0; i<n-1; i++) {
		for(int j = i + 1; j<n; j++) {
			if(data[i]>data[j]) {
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
	for(int i = 0; i<n; i++) {
		printf("%d\n" , data[i]);
	}
}