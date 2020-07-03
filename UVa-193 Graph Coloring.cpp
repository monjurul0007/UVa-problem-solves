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

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};

vector <int> adj[105];
vector <int> ans,vt;
int vis[105],n;

void dfs(int u){
	if(u > n){
		if(ans.size() < vt.size())
			ans = vt;
		return;
	}
	
	dfs(u+1);
	
	bool call = true;
	for(auto v: adj[u])
		if(vis[v] == 1){
			call = false;
			break;
		}
	
	if(call){
		vis[u] = 1;
		vt.pb(u);
		dfs(u+1);
		vis[u] = -1;
		vt.pop_back();
	}
}



int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		int e;
		scanf("%d %d",&n,&e);
		while(e--){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		mem(vis, -1);
		
		dfs(1);
		
		printf("%d\n%d",ans.size(),ans[0]);
		for(int i=1; i<ans.size(); i++)
			printf(" %d",ans[i]);
		printf("\n");
		
		for(int i=1; i<=n; i++){
			adj[i].clear();
		}
		
		vt.clear();
		ans.clear();
	}
	
    return 0;
}
