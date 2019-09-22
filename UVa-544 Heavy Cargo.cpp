#include <bits/stdc++.h>
using namespace std;
 
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define fin(i) freopen(i, "r", stdin)
#define fout(o) freopen(o, "w", stdout)
#define pb push_back
#define ll long long int
#define inf	LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
 
typedef pair<long long int, string> pis; 
map <string, vector <pis> > adj;


ll prim(string s, string d){
	priority_queue <pis> pq;
	map <string, ll> vis;
	for(auto const& x : adj){
		vis[x.first] = inf;
	}
	pis u;
	string prv = s;
	pq.push(pis(inf - 5,s));
	while(!pq.empty()){
		u = pq.top();
		pq.pop();
		
		if(vis[u.second] != inf)
			continue;
		
		
		vis[u.second] = min(vis[prv] , u.first);
		prv = u.second;
		
		int l = adj[u.second].size();
		
		for(int i=0; i<l; i++){
			string v = adj[u.second][i].second;
			if(vis[v] == inf){
				pq.push(adj[u.second][i]);
			}
		}
	}
	
	return vis[d];
}

int main(){
    fin("input.txt");
    int n,r,w,t=1;
    string s1,s2;
    
	while(cin >> n >> r){
		if(!n && !r)
			break;
		for(int i=0; i<r; i++){
			cin >> s1 >> s2 >> w;
			adj[s1].pb(pis(w,s2));
			adj[s2].pb(pis(w,s1));
		}
		
		cin >> s1 >> s2;
		
		cout << "Scenario #" << t++ << "\n";
		cout << prim(s1,s2) << " tons\n" << endl;
		
		adj.clear();
	}
    return 0;
}
