# include <stdio.h>

int main() {
	char ch[102];

	
	while (fgets(ch, 102, stdin) != NULL) {
		printf("%s", ch);
		//fgets(ch, 102, stdin);
	}
	
	return 0;
}
