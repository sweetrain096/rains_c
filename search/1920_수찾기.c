#include <stdio.h>
int n, m;
int arr[100010], search_arr[100010];

//ÀÌÁøÅ½»ö
int Binary(int *arr , int search_data, int l , int r) {
	int R = r , L = l;
	while(L<=R) {
		int mid = (L+R)/2;

		if(arr[mid]==search_data) return 1;

		if(search_data<arr[mid]) R = mid-1;
		else L = mid+1;
	}
	return 0;
}



//Äü¼ÒÆ®
int quick(int *data , int l , int r) {
	int L = l , R = r;
	if(L>R) return;

	int mid = (L+R)/2;
	int pivo = data[mid];

	while(L<=R) {
		while(data[L]<pivo) L++;
		while(data[R]>pivo) R--;

		if(L<=R) {
			int c;
			c = data[L];
			data[L] = data[R];
			data[R] = c;
			L++;
			R--;
		}
	}
	if(L<r) quick(data , L , r);
	if(l<R) quick(data , l , R);
}

int main(void) {
	freopen("1920_input.txt" , "r" , stdin);
	scanf("%d" , &n);
	for(int i = 0; i<n; i++) {
		scanf("%d" , &arr[i]);
	}
	quick(arr , 0 , n-1);

	scanf("%d" , &m);
	for(int i = 0; i<m; i++) {
		scanf("%d" , &search_arr[i]);
		printf("%d\n" , Binary(arr , search_arr[i] , 0 , n-1));
	}

	return 0;
}