#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first
#define S second

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;


int main(){
	fasterInOut;

	ll n,a,b;
	
	while(cin >> n,n){
		cin >> a >> b;
		map<ll, int> mp;
		mp[0] = 1;
		ll x = 0;
		while(mp[x] != 3){
			ll X = (x*x)%n;
			x = ((a*X)%n + b) % n;
			mp[x]++;
		}
		
		ll cnt = 1;
		for(auto i: mp){
			if(i.S == 2)
				cnt++;
		}
				
		cout << n - cnt << "\n";
	}
	
    return 0;
}
