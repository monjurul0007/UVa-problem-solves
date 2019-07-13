#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30

typedef pair<int , int> ii;
typedef pair<int, ii> iii;

int _x[] = {1,0,-1,0};
int _y[] = {0,1,0,-1};

int n,m;
vector <ii> adj
void dia(){
	priority_queue <iii , vector<iii>, greater<iii>> pq;
	pq.push( iii(adj[1][1], ii(1,1) ) );
	vis[1][1] = adj[1][1];
	while(!pq.empty()){
		int X = pq.top().second.first;
		int Y = pq.top().second.second;
		pq.pop();
		for(int i=0; i<4; i++){
			int x = X+_x[i];
			int y = Y+_y[i];
			if((x>=1 && x<=n) && (y>=1 && y<=m))
				if(vis[x][y] > adj[x][y] + vis[X][Y]){
					vis[x][y] = adj[x][y] + vis[X][Y];
					pq.push( iii(vis[x][y], ii(x,y) ) );
				}
		}
	}
	
}

int main(){
	//freopen("input.txt","r",stdin);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++){
				cin >> adj[i][j];
				vis[i][j] = inf;
			}
		dia();
		cout << vis[n][m] << endl;
	}
	return 0;
}
