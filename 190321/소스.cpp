# include <stdio.h>


int main() {
	//freopen("input.txt", "r", stdin);

	int a, n, m;
	int arr[10][10];

	scanf("%d", &a);
	scanf("%d %d", &n, &m) ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	printf("%d", a);
	printf("%d %d", n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}



	return 0;
}