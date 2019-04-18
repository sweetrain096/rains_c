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
	in_oper = in_post = 0;
	token = data[i];
	while (token != '\0') {
		token = data[i++];
		if (token == '+' || token == '*' || token == '(' || token == ')') {
			if (in_oper == 0 && operators[in_oper] == '\0')	operators[in_oper++] = token;
			else if (token == '(') operators[in_oper++] = token;
			else if (token == '*') {
				check_oper = --in_oper;
				while (operators[check_oper] == '*') {
					post_data[in_post++] = operators[check_oper];
					operators[check_oper--] = '\0';
					if (check_oper == -1) break;
				}
				operators[++check_oper] = token;
				in_oper = ++check_oper;
			}
			else if (token == '+') {
				check_oper = --in_oper;
				while (operators[check_oper] == '*' || operators[check_oper] == '+') {
					post_data[in_post++] = operators[check_oper];
					operators[check_oper--] = '\0';
					if (check_oper == -1) break;
				}
				operators[++check_oper] = token;
				in_oper = ++check_oper;
			}
			else if (token == ')') {
				check_oper = --in_oper;
				while (operators[check_oper] != '(') {
					post_data[in_post++] = operators[check_oper];
					operators[check_oper--] = '\0';
					if (check_oper == -1) break;
				}

				operators[check_oper] = '\0';
				in_oper = check_oper;
			}
		}
		else {
			post_data[in_post++] = token;
		}
	}
	//printf("%s", post_data);
	operation();
}


int main() {
	freopen("1224_input.txt", "r", stdin);
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