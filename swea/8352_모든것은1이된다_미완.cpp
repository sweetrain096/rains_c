#include<stdio.h>
int testcase;
char date[110], time[110];
int running_time[100000];
int main(void) {
	freopen("8352_input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++) {
		printf("%d ", tc);
		scanf("%s ", date);
		scanf("%s ", time);
		
		printf("%s %s %ld\n", date, time, running_time);
		
	}
	return 0;
}