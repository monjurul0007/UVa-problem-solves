#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first  
#define S second   

typedef long long int ll;     
typedef pair<ll , ll>  pii;
typedef pair<int , pii > piii; 

const int dirx[4] = {0,1,0,-1};
const int diry[4] = {1,0,-1,0};

int m;
ll n;
vector <ll> v;

ll lcm(ll a, ll b){
	return a/__gcd(a,b) * b;
}

ll count(int i, int cnt, vector<ll>find){
	
	if(find.size() == cnt){
		ll g = find[0];
		for(int i=1; i < find.size(); i++)
			g = lcm(g, find[i]);
		return n/g;
	}
	
	if(i > m)
		return 0;
	
	ll res = 0;
	
	for(; i<m; i++){
		find.pb(v[i]);
		res += count(i+1, cnt, find);
		find.pop_back();
	}
	
	return res;
}

int main(){
	//fasterInOut;
	
	ll x;
	
	while(scanf("%lld %d",&n,&m) != EOF){
		for(int i=0; i<m; i++){
			scanf("%lld",&x);
			v.pb(x);
		}
		
		ll cnt = 0;
		for(int i=1; i<=m; i++){
			vector <ll> find;
			x = count(0,i,find);
			
			if(i%2)
				cnt += x;
			else
				cnt -= x;
		}
		
		printf("%lld\n",n-cnt);
		
		v.clear();
	}
	
	
    return 0;
}
