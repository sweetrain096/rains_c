#include <stdio.h>
int n;
char data[300];
char post_data[300], operators[300];
char token;
int stack[300], result;

int is_int(char a) {
	if (a - '0' >= 0 && a - '0' < 10) {
		return 1;
	}
	return 0;
}

void operation() {
	int i = 0, stack_p = 0;
	int element1, element2, tmp;
	token = post_data[i];
	while (token != '\0') {
		token = post_data[i++];
		if (is_int(token)) {
			stack[stack_p] = token - '0';
			//printf("%d: %d  ", i, stack[stack_p]);
			stack_p++;
		}
		else {
			element1 = stack[stack_p - 2];
			element2 = stack[stack_p - 1];
			if (token == '+') tmp = element1 + element2;
			else if (token == '*') tmp = element1 * element2;

			//printf("%d %d %d   ", element1, element2, tmp);
			stack[stack_p - 2] = tmp;
			stack[stack_p - 1] = 0;
			stack_p = stack_p - 1;
		}

	}

	result = tmp;
}

void makepost() {
	int i = 0, in_oper, in_post;
	int check_oper;
	post_data[0] = '\0';
	operators[0] = '\0';
	token = data[i];
	in_oper = in_post = 0;
	while (token != '\0') {
		if (i == 0) {
			i++;
			continue;
		}
		if (token == '+' || token == '*') {
			if (in_oper == 0) {
				if (operators[in_oper] != '+' && operators[in_oper] != '*') {
					operators[in_oper] = token;
				}
				in_oper++;
			}
			else {
				check_oper = in_oper - 1;
				if (token == '+') {
					while (1) {
						if (operators[check_oper] != '+' && operators[check_oper] != '*') break;
						post_data[in_post] = operators[check_oper];
						operators[check_oper] == '\0';
						in_post++;
						check_oper--;
						if (check_oper == -1) break;
					}
					in_oper = check_oper + 1;
					operators[in_oper] = token;
					in_oper++;
				}
				else {
					while (1) {
						if (operators[check_oper] != '*') break;
						post_data[in_post] = operators[check_oper];
						operators[check_oper] = '\0';
						in_post++;
						check_oper--;
						if (check_oper == -1) break;
					}
					in_oper = check_oper + 1;
					operators[in_oper] = token;
					in_oper++;

				}
		
			}
		}
		else {
			post_data[in_post] = token;
			in_post++;
		}
		token = data[i++];
	}

	operators[in_oper--] = '\0';
	post_data[in_post] = '\0';

	
	while (in_oper > -1) {
		post_data[in_post] = operators[in_oper];
		in_oper--;
		in_post++;
	}
	post_data[in_post] = '\0';

	//printf("%s\n", post_data);
	operation();
}

int main() {
	freopen("1223_input.txt", "r", stdin);
	int tc;
	for (tc = 1; tc <= 10; tc++) {
		scanf("%d", &n);
		scanf("%s", data);
		result = 0;
		
		makepost();
		printf("#%d %d\n", tc, result);
	}



	return 0;
}