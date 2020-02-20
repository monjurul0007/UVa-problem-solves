#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define all(x) x.begin(),x.end()
         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq; 

vector <int> adj[105];
int vis[105];
stack <int> ts;

void topsort(int s){
	if(vis[s])
		return;
		
	int v;
	vis[s] = 1;
	
	for(int i=0; i<adj[s].size(); i++){
		v = adj[s][i];
		topsort(v);
	}
	ts.push(s);
}

int main(){
	int m,n,u,v;
	
	while(scanf("%d%d",&n,&m)){
		if(!m && !n)
			break;
		
		for(int i=1; i<=n; i++)
			adj[i].clear();
		memset(vis, 0, sizeof(vis));
		
		for(int i=0; i<m; i++){
			scanf("%d%d",&u,&v);
			adj[u].pb(v);
		}
		
		for(int i=1; i<=n; i++)
			topsort(i);
			
		while(!ts.empty()){
			printf("%d ",ts.top());
			ts.pop();
		}
		printf("\n");
		
	} 
	
	return 0;
}
