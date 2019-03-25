# include <stdio.h>
int main() {
	char ch[102];
	while (fgets(ch, 102, stdin)) {
		printf("%s", ch);
	}


	return 0;
}