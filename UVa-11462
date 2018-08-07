#include <bits/stdc++.h>

int arr[2000000],temp[2000000];

void mergesort(int lo, int hi){
	if(lo == hi)
		return;
	int mid = (lo+hi)/2;
	
	mergesort(lo,mid);
	mergesort(mid+1,hi);
	
	int i,j,k;
	for(i = lo, j = mid+1, k = lo; k<=hi; k++)
		if(i == mid + 1)
			temp[k] = arr[j++];
		else if(j == hi +1)	
			temp[k] = arr[i++];
		else if(arr[i] < arr[j])
			temp[k] = arr[i++];
		else
			temp[k] = arr[j++];
	for(int k = lo; k<=hi; k++)
		arr[k] = temp [k];
}

int main(){
	long long int i,n;
	while(scanf("%lld",&n)){
		if(n==0)
			break;
		for(i=0; i<n; i++)
			scanf("%d",&arr[i]);
		mergesort(0,n-1);
		printf("%d",arr[0]);
		for(i=1; i<n; i++)
			printf(" %d",arr[i]);
		printf("\n");
	}
	return 0;
}
