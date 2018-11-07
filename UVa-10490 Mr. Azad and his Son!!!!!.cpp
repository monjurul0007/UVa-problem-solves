#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

bool isprime(ll n){
	ll lim = sqrt(n);
	for(ll i=2; i<=lim; i++)
		if(n%i==0){
			return false;
		}
	return true;
}

ll power(int n){
	ll num = 1;
	for(int i=0; i<n; i++)
		num *= 2;
	return num;
}

int main(){
	ll n,num;
	while(scanf("%lld",&n)){
		if(n == 0)
			break;
		if(n>2 && n%2==0){
			printf("Given number is NOT prime! NO perfect number is available.\n");
			continue;
		}
		num = power(n);
		if(isprime(num-1))
			printf("Perfect: %llu!\n",(num/2)*(num-1));
		else{
			if(isprime(n))
				printf("Given number is prime. But, NO perfect number is available.\n");
			else
				printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}
	return 0;
}
