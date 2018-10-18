#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
bool mark[20000000];
vector <ll> prime_twin[2];

void prime_seive(ll n){
	ll lim = sqrt(n*1.)+2;
	for(ll i=4; i<=n; i+=2)
		mark[i] = true;
	mark[0] = true;
	mark[1] = true;
	for(ll i=3; i<=n; i++){
		if(!mark[i]){
			if(!mark[i-2]){
				prime_twin[0].push_back(i-2);
				prime_twin[1].push_back(i);
			}
			if(i<=lim)
				for(ll j=i*i; j<=n; j += i*2)
					mark[j] = true;
		}
	}
}

int main(){
	prime_seive(20000000);
	ll n;
	while(scanf("%lld",&n) != EOF){
		printf("(%lld, %lld)\n",prime_twin[0].at(n-1),prime_twin[1].at(n-1));
	}
	return 0;
}
