#include <stdio.h>
int T;
char data[60];
int length;
int main(void) {
	freopen("4751_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%s", &data);	 //문자열 입력
		length = 0;
		while (data[length] != '\0') length++; // 문자열 길이
		// 1번줄
		printf("..#");
		for (int i = 0; i < length - 1; i++) {
			printf("...#");
		}
		printf("..\n");
		//2번줄
		for (int i = 0; i < length * 2; i++) {
			printf(".#");
		}
		printf(".\n");
		//3번줄
		for (int i = 0; i < length; i++) {
			printf("#.%c.", data[i]);
		}
		printf("#\n");
		//4번줄
		for (int i = 0; i < length * 2; i++) {
			printf(".#");
		}
		printf(".\n");
		//5번줄
		for (int i = 0; i < length; i++) {
			printf("..#.");
		}
		printf(".\n");
	}
	return 0;
}