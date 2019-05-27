#include <stdio.h>
#include "malloc.h"
int n , m;
int search;

int binary(int *data , int search , int l , int r) {
	int L = l , R = r;
	while(L<=R) {
		int mid = (L+R)/2;
		
		if(search==data[mid]) return 1;
		if(search<data[mid]) R = mid-1;
		else L = mid+1;
	}
	return 0;
}


void qSort(int *data , int l , int r) {
	int R = r , L = l;
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
			L++; R--;
		}
	}
	if(L<r) qSort(data , L , r);
	if(R>l) qSort(data , l , R);
}

int main(void) {
	freopen("10815_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	int *data = (int *) malloc(sizeof(int)*n);
	for(int i = 0; i<n; i++) {
		scanf("%d" , &data[i]);
	}
	qSort(data , 0 , n-1);
	
	scanf("%d" , &m);
	for(int i = 0; i<m; i++) {
		scanf("%d", &search);
		printf("%d " , binary(data , search , 0 , n-1));
	}
	return 0;
}