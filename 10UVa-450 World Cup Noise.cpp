#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int arr[51],t,n;
	scanf("%lld",&t);
	arr[1] = 2;
	arr[2] = 3;
	for(int i=3; i<51; i++)
		arr[i] = arr[i-1] + arr[i-2];
	for(long long int T=1; T<=t; T++){
		scanf("%lld",&n);
		printf("Scenario #%lld:\n%lld\n\n",T,arr[n]);
	}
	return 0;
}
