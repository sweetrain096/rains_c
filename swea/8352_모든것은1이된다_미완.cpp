#include<stdio.h>
int testcase;
char date[110], time[110], running_time_char[40];
unsigned long long running_int;
int Y, M, D, h, m, s;
int len;
char now;
int check_len, check_type;

void sum(int Y, int M, int D, int h, int m, int s, 
		int running_int,
		int *nY, int *nM, int *nD, int *nh, int *nm, int *ns) {
	int tmp = 0;
	printf("%d ", running_int);
	if (running_int < 86400) {
		*nh = h + running_int / 3600;
		printf("%d ", *nh);
		tmp = running_int % 24;
	}
	if (running_int < 3600) {
		*nm = m + running_int / 60;
		tmp = running_int % 60;
		printf("%d ", *nm);
		running_int = tmp;
	}
	if (running_int < 60) *ns = s + running_int;
	printf("%d ", *ns);
}
int main(void) {
	freopen("8352_input.txt", "r", stdin);
	scanf("%d", &testcase);
	for (int tc = 1; tc <= testcase; tc++) {
		printf("%d ", tc);
		scanf("%s %s %s ", date, time, running_time_char);
		Y = M = D = h = m = s = 0;
		check_len = check_type = 0;
		while (date[check_len] != '\0') {
			if (date[check_len] == '/') check_type++;
			else if (check_type == 0) {
				Y *= 10;
				Y += date[check_len] - 48;
			}
			else if (check_type == 1) {
				M *= 10;
				M += date[check_len] - 48;
			}
			else if (check_type == 2) {
				D *= 10;
				D += date[check_len] - 48;
			}
			check_len++;
		}
		check_len = check_type = 0;
		while (time[check_len] != '\0') {
			if (time[check_len] == ':') check_type++;
			else if (check_type == 0) {
				h *= 10;
				h += time[check_len] - 48;
			}
			else if (check_type == 1) {
				m *= 10;
				m += time[check_len] - 48;
			}
			else if (check_type == 2) {
				s *= 10;
				s += time[check_len] - 48;
			}
			check_len++;
		}
		


		len = 0;
		now = running_time_char[len];
		while (now == '1') {
			now = running_time_char[++len];
		}
		running_int = 1 << len;
		running_int--;

		int nY, nM, nD, nh, nm, ns;
		sum(Y, M, D, h, m, s, running_int, &nY, &nM, &nD, &nh, &nm, &ns);
		
		

		printf("%s %s %s\n", date, time, running_time_char);
		
		
	}
	return 0;
}