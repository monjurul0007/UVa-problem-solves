#include <bits/stdc++.h>
using namespace std;
     
typedef long long int ll;     
typedef pair<int , int>  pii;
    
ll bigmod(ll n, ll p, ll m){
    if(p==0)
	return 1;
    if(p%2 == 0){
	ll ans = bigmod(n, p/2, m);
	return ((ans%m)*(ans%m))%m;
    }
    else{
	ll ans = bigmod(n, p-1 , m);
	return ((n%m)*(ans%m))%m;
    }
}
         
int main(){
    ll m,ans;
    while(cin >> m){
	ans = 0;
	for(int i=0; i>=0; i++){
		ans = (bigmod(10,i,m) + ans%m)%m;
		if(ans == 0){
			cout << i+1 << endl;
			break;
		}
	}
    }
    return 0;
}
