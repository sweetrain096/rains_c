#include <stdio.h>
#include "malloc.h"
int n , m;
int start , end;
int mid;
long long tmpSum;
long long tmpResult;
int main(void) {
	freopen("2805_input.txt" , "r" , stdin);
	scanf("%d %d" , &n , &m);
	start = end = 0;
	int *data = (int *) malloc(sizeof(int)*n);
	for(int i = 0; i<n; i++) {
		scanf("%d" , &data[i]);
		if(end<data[i]) end = data[i];
	}

	while(1) {
		tmpSum = 0;
		mid = (start+end)/2;
		if(mid==tmpResult) break;
		for(int i = 0; i<n; i++) {
			if(data[i]>mid) tmpSum += data[i]-mid;
		}
		if(tmpSum>m) start = mid+1;
		else if(tmpSum==m) {
			tmpResult = mid;
			break;
		}
		else end = mid-1;
		tmpResult = mid;
	}
	printf("%d" , tmpResult);
	return 0;
}