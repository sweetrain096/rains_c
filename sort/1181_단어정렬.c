#include <stdio.h>
int n;
int data[20010][60];
char word[60];
char now;
int length;

void qSort(int *data, int l, int r) {
	for (int i = 0; i < n; i++) {

	}
	
	int L = l, R = r;
	int mid = (L + R) / 2;
	printf("mid%d\n", mid);
	int pivo = data[mid];
	printf("%d\n", data[mid]);
}

int main(void) {
	freopen("1181_input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &word);
		now = word[0];
		length = 0;
		while (now != '\0') {
			data[i][length + 1] = now;
			now = word[length + 1];
			length++;
		}
		data[i][0] = length;

		printf("%d : ", data[i][0]);
		for (int j = 1; j <= length; j++) {
			printf("%c", data[i][j]);
		}
		printf("\n");

		
	}

	qSort(data, 0, n - 1);
}