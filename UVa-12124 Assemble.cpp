#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 100000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;


const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};

ll n,comp,bg;
map <string, int> type;
vector <pair<ll,ll> > product[1005];
vector <ll> lt;

void clear(){
	type.clear();
	lt.clear();
	for(int i=0; i<1005; i++){
		product[i].clear();
	}
}


bool find(int i, ll price, ll target){
	if(i > comp){
		return true;
	}
	
	bool res = false;
	ll p = 100005;
	for(auto j: product[i]){
		if(j.F >= target){
			p = min(j.S,p);
		}
	}
	
	if(p + price <= bg)
		res = backtrack(i+1, price+p, target);
	
	return res;
}


ll bs(){
	ll l=0,r=lt.size()-1,mid,in = lt.size();
	while(l <= r){
		mid = (l+r)/2;
		if(find(1,0,lt[mid])){
			l = mid + 1;
			in = lt[mid];
		}
		else{
			r = mid - 1;
		}
	}
	return in;
}


int main(){
	fasterInOut;
	
	int t;
	ll a,b,cnt;
	string s,junk;
	cin >> t;
	
	while(t--){
		set <ll> st;
		cnt = 1;
		clear();
		
		cin >> n >> bg;
		
		for(int i=0; i<n; i++){
			cin >> s >> junk >> a >> b;
			st.insert(b);
			if(type[s] == 0)
				type[s] = cnt++;
			product[type[s]].pb({b,a});
		}
		
		comp = type.size();
		for(int i=1; i<=comp; i++)
			sort(all(product[i]));
			
		for(auto i: st)
			lt.pb(i);
					
		cout << bs() << endl;
	}
	
    return 0;
}
