#include <bits/stdc++.h>

using namespace std;

vector <int> adj[101];
int vis[101][101];
int cnt;

void dfs(int s,int n){
	stack <int> st;
	st.push(s);
	while(!st.empty()){
		int top = st.top();
		st.pop();
		for(int i=0; i<adj[top].size(); i++)
			if(vis[n][adj[top][i]] == 0){
				vis[n][adj[top][i]] = 1;
				st.push(adj[top][i]);
			}
	}
}

int main(){
//	freopen("input.txt","r",stdin);
	int n,t;
	while(scanf("%d",&n), n){
		int node,v;
		while(scanf("%d",&node), node){
			while(scanf("%d",&v), v)
				adj[node].push_back(v);
		}
		memset(vis,0,sizeof vis);
		for(int j=1; j<=n; j++)
			dfs(j,j);
		scanf("%d",&t);
		for(int i=0; i<t; i++){
			cnt = 0;
			scanf("%d",&node);
			for(int j=1; j<=n; j++)
				if(vis[node][j] == 0)
					cnt++;
			printf("%d",cnt);
			for(int j=1; j<=n; j++)
				if(vis[node][j] == 0)
					printf(" %d",j);
			printf("\n");
		}
		for(int j=1; j<=n; j++){
			adj[j].clear();
		}
	}
	return 0;
}
