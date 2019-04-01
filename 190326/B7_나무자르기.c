# include <stdio.h>
int n, m;
int data[1000010];
int start, end, mid;
long long result, sum;
int main(void) {
	scanf("%d %d", &n, &m);
	end = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		if (end < data[i]) end = data[i];
	}
	start = 0;

	while (1) {
		sum = 0;
		mid = (start + end) / 2;
		if (mid == result) {
			//printf("%d", result);
			break;
		}
		for (int i = 0; i < n; i++) {
			if (data[i] > mid) sum += data[i] - mid;
			
		}
		if (sum > m) {
			start = mid + 1;
			//result = mid;
		}
		else if (sum == m) {
			result = mid;
			
			break;
		}
		else {
			end = mid - 1;
			
		}
		result = mid;
		
	}
	printf("%d", result);
}