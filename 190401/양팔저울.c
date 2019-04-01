# include <stdio.h>
int n;
int data[20], tmp[20];

int check_n;
int check_data[15];
int marble;
int flag;

void powerset(int k, int left_sum, int right_sum) {
	if (flag) return;
	if (k == n) {
		if (left_sum == right_sum) {
			flag = 1;
		}
		return;
	}
	if (k == 0) left_sum = marble;
	tmp[k] = 1;
	powerset(k + 1, left_sum + data[k], right_sum);
	tmp[k] = 2;
	powerset(k + 1, left_sum, right_sum + data[k]);
	tmp[k] = 0;
	powerset(k + 1, left_sum, right_sum);
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &check_n);
	for (i = 0; i < check_n; i++) {
		scanf("%d", &check_data[i]);
		marble = check_data[i];
		flag = 0;
		powerset(0, 0, 0);
		if (flag) printf("Y ");
		else printf("N ");
	}



	return 0;
}