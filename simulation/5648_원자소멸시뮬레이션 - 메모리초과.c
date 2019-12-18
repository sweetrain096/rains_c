#include <stdio.h>
#include <malloc.h>


struct Data {
	int x, y, dir, k;
};

struct Node {
	struct Node *next;
	struct Data data;
};




int T, N;
int x, y;
int new_x, new_y;
int result;
int Map[4002][4002];
int direct[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
struct Node *head;
struct Node *tail;


int main(void) {
	freopen("5648_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		result = 0;
		struct Node *node = malloc(sizeof(struct Node));
		head = node;
		printf("%d\n", N);
		// file input
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &x, &y, &node->data.dir, &node->data.k);
			node->data.x = x * 2;
			node->data.y = y * 2;
			struct Node *next = malloc(sizeof(struct Node));
			node->next = next;
			node = next;
		}
		tail = node;


		struct Node *now;
		struct Node *before;
		while (head != tail) {
			struct Node *remove;
			now = head;
			before = head;
			while (now != tail) {
				// 방향에 따라 위치 구하기
				new_x = now->data.x + direct[now->data.dir][0];
				new_y = now->data.y + direct[now->data.dir][1];
				printf("%d %d new %d %d \n", now->data.x, now->data.y, new_x, new_y);
				// 새로운 위치가 Map을 넘어설 경우
				if (new_x < -2000 || new_x > 2000 || new_y < -2000 || new_y > 2000) {
					remove = now;

					// 현재 삭제할 것이 head라면,
					if (now == before) {
						now = now->next;
						before = now;
						head = now;
						free(remove);
						continue;
					}

					// 아니라면,
					before->next = now->next;
					before = before->next;
					now = now->next;

					free(remove);
					continue;

				}
				
				// 아니라면 새로 구한 x, y 대입
				now->data.x = new_x;
				now->data.y = new_y;

				Map[new_x + 2000][new_y + 2000]++;

				before = now;
				printf("%d %d\n", now->data.x, now->data.y);
				now = now->next;
				
			}

			now = head;
			before = head;
			while (now != tail) {

				printf("check%d %d\n", now->data.x, now->data.y);
				if (Map[now->data.x + 2000][now->data.y + 2000] == 1) {
					printf("in?");
					Map[now->data.x + 2000][now->data.y + 2000] = 0;
				}
				else if (Map[now->data.x + 2000][now->data.y + 2000] > 1) {
					Map[now->data.x + 2000][now->data.y + 2000] *= -1;
					result += now->data.k;
					
					remove = now;
					if (now == before) {
						now = now->next;
						before = now;
						head = now;
					}
					else {
						before->next = now->next;
					}
					free(remove);

					continue;
				}
				else if (Map[now->data.x + 2000][now->data.y + 2000] < 0) {
					result += now->data.k;

					remove = now;
					if (now == before) {
						now = now->next;
						before = now;
						head = now;
					}
					else {
						before->next = now->next;
					}
					free(remove);

					continue;
				}
				before = now;
				printf("now%d %d\n", now->data.x, now->data.y);

				now = now->next;
				printf("next%d %d\n", now->data.x, now->data.y);

			}
		}
		printf("#%d %d\n", tc, result);

	}
	return 0;
}