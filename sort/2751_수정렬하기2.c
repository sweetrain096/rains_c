#include <stdio.h>
int n;
int data[1000010];

void qSort(int *data, int l, int r){
	int L = l , R = r;
	if(L>R) return;
	int mid = (L+R)/2;
	int pivo = data[mid];
	while(L<=R) {
		while(data[L]<pivo) L++;
		while(data[R]>pivo) R--;
		if(L<=R) {
			int tmp = data[L];
			data[L] = data[R];
			data[R] = tmp;
			L++; R--;
		}
	}
	if(L<r) qSort(data , L , r);
	if(l<R) qSort(data , l , R);
}
int main(void) {
	freopen("2751_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	for(int i = 0; i<n; i++) {
		scanf("%d" , &data[i]);
	}
	qSort(data , 0 , n-1);
	for(int i = 0; i<n; i++) {
		printf("%d\n" , data[i]);
	}
	
	return 0;
}