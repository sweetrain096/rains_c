#include <stdio.h>
#include <malloc.h>

typedef struct Num {
	int Number;
	struct Num* next;
	struct Num* pre;
}Num;

int n, len, cnt;
char strNum[110];
Num* head;
Num* tail;

int main(void) {
	freopen("1234_input.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d %s", &n, strNum);
		Num* number = (Num*)malloc(sizeof(struct Num));
		number->Number = strNum[0] - '0';
		number->pre = NULL;
		head = number;
		
		for (int i = 1; i < n; i++) {
			Num* new_num = (Num*)malloc(sizeof(struct Num));
			new_num->pre = number;
			new_num->Number = strNum[i] - '0';
			number->next = new_num;
			number = new_num;
		}
		number->next = NULL;
		tail = number;

		len = n;
		while (1) {
			number = head;
			cnt = 0;
			while (number != tail) {
				if (number->Number == number->next->Number)
				{
					if (number != head && number->next != tail) {
						Num* del1;
						Num* del2;
						del1 = number;
						del2 = number->next;
						del1->pre->next = del2->next;
						del2->next->pre = del1->pre;

						number = del2->next;
						free(del1);
						free(del2);
					}
					else if (number == head) {
						head = number->next->next;
						head->pre = NULL;
						free(number->next);
						free(number);
						number = head;
					}
					else if (number->next == tail) {
						tail = number->pre;
						tail->next = NULL;
						free(number->next);
						free(number);
						number = tail;
					}
				}
				else {
					number = number->next;
					cnt += 1;
				}
			}

			if (len == cnt) break;
			len = cnt;
		}
		
		printf("#%d ", tc);
		number = head;
		while (number != tail) {
			printf("%d", number->Number);
			number = number->next;
			free(number->pre);
		}
		printf("%d\n", number->Number);
		free(number->next);
		free(number);
	}
	return 0;
}