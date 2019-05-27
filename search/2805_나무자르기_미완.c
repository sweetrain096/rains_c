#include <stdio.h>
#include "malloc.h"

int n , m;


int binarySearch(int *data , int l , int r) {
	int L = l , R = r;
	int tmpSum = 0;
	int tmpResult = -1;
	while(L<=R) {
		int mid = (L+R)/2;
		printf("mid%d\n" , mid);
		for(int i = n - 1; i>0; i--) {
			printf("%d" , data[i]);
			if(data[i]<=mid) break;
			printf("ok");
			tmpSum += data[i]-mid;
			if(tmpSum>m) {
				tmpSum = 0;
				break;
			}
		}
		if(tmpSum==m && tmpResult < mid) {
			tmpResult = mid;
			L = mid+1;
		}
	}
	return tmpResult;
}


void qSort(int *data , int l , int r) {
	int L = l , R = r;
	if(L>R) return;
	int mid = (L+R)/2;
	int pivo = data[mid];
	while(L<=R) {
		while(data[L]<pivo) L++;
		while(data[R]>pivo) R--;
		if(L<=R) {
			int tmp;
			tmp = data[L];
			data[L] = data[R];
			data[R] = tmp;
			L++;
			R--;
		}
	}
	if(L<r) qSort(data , L , r);
	if(l<R) qSort(data , l , R);
}
int main(void) {
	freopen("2805_input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	int *data = (int *) malloc(sizeof(int)*n);
	for(int i = 0; i<n; i++) {
		scanf("%d", &data[i]);
	}
	qSort(data , 0 , n-1);
	printf("%d", binarySearch(data , 0 , m));

	return 0;
}