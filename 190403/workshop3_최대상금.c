# include <stdio.h>
int t;
int total, n_cnt;
int data[10];
char tmp[10];
int blank;
int result;
int check;
int visited[1000000];
int int_data;

int pow(int num, int n) {
	int i, result = num;
	for (i = 1; i < n; i++) {
		result *= num;
	}
	if (n == 0) return 1;
	else return result;
}

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int make_int(void) {
	int i;
	check = 0;
	for (i = 0; i < total; i++) {
		// printf("%d %d \t", data[total - i - 1], pow(10, i));
		check += (data[total - i - 1] * pow(10, i));
	}
	return check;
}
void make_max(int int_data) {
	int i;
	/*check = 0;
	//printf("hi");
	for (i = 0; i < total; i++) {
		// printf("%d %d \t", data[total - i - 1], pow(10, i));
		check += (data[total - i - 1] * pow(10, i));
	}*/
	result = max(result, int_data);
}


void make_perm(int cnt) {
	int i, j, tmp;
	int_data = make_int();
	/*int_data = make_int();
	if (visited[int_data] == 0) {
		visited[int_data] = cnt + 1;
	}
	else {
		visited[int_data] = 1 + visited[int_data];
		return;
	}

	if (visited[int_data] == n_cnt) {
		make_max();
		return;
	}*/

	if (cnt == n_cnt) {
		//if(data[0] * pow(10, total) < result) return;
		int_data = make_int();
		make_max(int_data);
		return;
	}
	for (i = 0; i < total - 1; i++) {
		for (j = i + 1; j < total; j++) {
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
			
			//printf("%d %d\n", int_data, cnt);
			//make_perm(cnt + 1);
			int_data = make_int();
			if (visited[int_data] == 0) {
				visited[int_data] = cnt + 1;
				make_perm(cnt + 1);
			}
			else {
				visited[int_data] = 1 + visited[int_data];

			}
			tmp = data[j];
			data[j] = data[i];
			data[i] = tmp;
		}
	}
}


int main(void) {
	freopen("input.txt", "r", stdin);

	int tc, cnt;
	scanf("%d", &t);
	
	for (tc = 0; tc < t; tc++) {
		
		scanf("%s", tmp);
		scanf("%d", &n_cnt);
		printf("%s\n", tmp);
		cnt = 0;
		while (tmp[cnt] != NULL) {
			data[cnt] = tmp[cnt] - 48;
			cnt++;
		}
		total = cnt;


		result = 0;
		//int_data = make_int();
		//visited[int_data] = cnt;
		
		make_perm(0);


		printf("#%d %d %d \n", tc + 1, result, cnt);
	}
}










/*
void perm(int k, int cnt) {
	int i, j;
	
	if (cnt == n_cnt) {
		check = 0;
		for (i = 0; i < total; i++) {
			// printf("%d %d \t", data[total - i - 1], pow(10, i));
			check += (data[total - i - 1] * pow(10, i));
		}

		result = max(result, check);


		for (j = 0; j < total; j++) {
			//printf("%d ", data[j]);
		}
		//printf("%d \n", check);
		// return;
	}
	else {
		if (n_cnt > total) total = n_cnt;
		for (i = k; i < total; i++) {
			perm(k + 1, cnt);
			blank = data[k];
			data[k] = data[i];
			data[i] = blank;
			perm(k + 1, cnt + 1);
			blank = data[k];
			data[k] = data[i];
			data[i] = blank;

		}
	}
}
*/