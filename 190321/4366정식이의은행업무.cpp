# include <stdio.h>

int main() {
	freopen("4366_input.txt", "r", stdin);

	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++) {
		char bit2[40];
		char bit3[40];

		scanf("%s", bit2);
		scanf("%s", bit3);

		printf("%s\n", bit2);
		printf("%s\n", bit3);
		
		char vsbit2[40];

		int cnt, num, cnt_in;
		cnt = 0;
		cnt_in = 0;
		while (bit2[cnt] != NULL) {
			while (bit2[cnt_in] != NULL) {
				vsbit2[cnt_in] = bit2[cnt_in];
				cnt_in++;

			}
			vsbit2[cnt_in] = '\0';
			cnt_in = 0;
			
			if (bit2[cnt] == '1'){
				vsbit2[cnt] = '0';
			}
			else {
				vsbit2[cnt] = '1';
			}
			printf("%s\n", bit2);
			printf("%s\n", vsbit2);

			cnt++;

		}
			
			


	}
	





	return 0;
}