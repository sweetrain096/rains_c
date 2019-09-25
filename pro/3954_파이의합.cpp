#include <stdio.h>
#include <malloc.h>
int T;
int a, b;
int *arr;

void eratos() {
	for (int i = 0; i < b; i++) {
		arr[i] = 1;
	}
	
	for (int i = 2; i < b / 2; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j < b/2; j += i) {
			printf("%d\n", j);
			arr[j] = 0;
			
		}
		
	}
	for (int i = 0; i < b; i++) {
		printf("%d ", arr[i]);
	}
	for (int i = 2; i < b; i++) {
		if (arr[i]) printf("%d, ", i);
	}
}

int main(void) {
	freopen("3954_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &a, &b);
		arr = (int *)malloc(sizeof b);
		eratos();

		printf("#%d ", tc);
	}
	return 0;
}