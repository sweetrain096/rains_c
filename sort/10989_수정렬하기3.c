#include <stdio.h>

int n, data;
int arr[10010];

int main(void) {
	freopen("10989_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	/*for(int i = 0; i<(n/5); i += 5) {
		arr[i] = 0;
		arr[i+1] = 0;
		arr[i+2] = 0;
		arr[i+3] = 0;
		arr[i+4] = 0;
	}*/
	for(int i = 0; i<n; i++) {
		scanf("%d" , &data);
		arr[data] += 1;
	}
	int index = 1;
	while(1) {
		if(index==10001) break;
		if(arr[index]!=0) {
			printf("%d\n" , index);
			arr[index] -= 1;
		}
		else {
			index++;
		}
	}
	return 0;
}