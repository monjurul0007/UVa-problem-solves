    #include <bits/stdc++.h>
    using namespace std;
         
    #define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
    #define fin(i) freopen(i, "r", stdin)
    #define fout(o) freopen(o, "w", stdout)
    #define pb push_back
    #define inf LLONG_MAX
    #define neginf LLONG_MIN
    #define wk cout << "working" << endl
     
    typedef long long int ll;     
    typedef pair<ll , ll>  pii;
    
    vector<pii> adj[1000005];
    bool vis[1000005];
    
	void init(ll n){
		for(ll i=1; i<=n; i++){
			vis[i] = false;
			adj[i].clear();
		}
	}
	
	ll prim(ll n){
		priority_queue <pii, vector<pii>, greater<pii> > q;
		
		ll v,w,edge=0,mst=0;
		
		vis[1] = true;
		
		for(ll i=0; i<adj[1].size(); i++)
			q.push(adj[1][i]);
			
		while(!q.empty()){
			v = q.top().second;
			w = q.top().first;
			q.pop();
			
			if(vis[v] == true)
				continue;
			
			mst += w;
			vis[v] = true;
			edge++;
			
			if(edge == n-1)
				break;
				
			for(ll i=0; i<adj[v].size(); i++){
				if(vis[adj[v][i].second] == false){
					q.push(adj[v][i]);
				}
			}
		}
		return mst;
	}
         
    int main(){
        //fin("input.txt");
        ll n,k,m,a,b,w,sum,f=0;
        
		while(cin >> n){
        
			init(n);
			sum = 0;
			for(ll i=0; i<n-1; i++){
				cin >> a >> b >> w;
				sum += w;
			}
			
			if(f)
				cout << "\n";
			f = 1;
			
			cout << sum << "\n";
		
			cin >> k;
		
			for(ll i=0; i<k; i++){
				cin >> a >> b >> w;
				adj[a].pb(pii(w,b));
				adj[b].pb(pii(w,a));
			}
		
			cin >> m;
		
			for(ll i=0; i<m; i++){
				cin >> a >> b >> w;
				adj[a].pb(pii(w,b));
				adj[b].pb(pii(w,a));
			}
		
			cout << prim(n) << "\n";
		} 
    	return 0;
    }
