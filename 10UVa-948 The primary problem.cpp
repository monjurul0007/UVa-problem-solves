#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
bool mark[1000000];
vector <ll> prime;

void prime_seive(ll n){
	ll lim = sqrt(n*1.)+2;
	for(ll i=4; i<=n; i+=2)
		mark[i] = true;
	mark[0] = true;
	mark[1] = true;
	prime.push_back(2);
	for(ll i=3; i<=n; i++){
		if(!mark[i]){
			prime.push_back(i);
			if(i<=lim)
				for(ll j=i*i; j<=n; j += i*2)
					mark[j] = true;
		}
	}
}

int main(){
	prime_seive(1000000);
	ll n;
	int l = prime.size();
	bool flag;
	while(scanf("%lld",&n)){
		if(n==0)
			break;
		flag = false;
		for(int i=0; i<l; i++){
			if(prime[i]>n/2)
				break;
			if(!mark[n-prime.at(i)]){
				flag = true;
				printf("%lld:\n%lld+%lld\n",n,prime.at(i),n-prime.at(i));
				break;
			}
		}
		if(!flag)
			printf("%lld:\nNO WAY!\n",n);
	}
	return 0;
}
