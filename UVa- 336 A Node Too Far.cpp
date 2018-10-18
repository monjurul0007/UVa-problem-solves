#include <bits/stdc++.h>

using namespace std;

map <long long int, int> visited; 

void bfs(long long int a, map <long long int , vector <long long int>> adj_f){
	queue <long long int> q;
	long long int node;
	visited[a] = 0;
	q.push(a);
	while(!q.empty()){
		node = q.front();
		q.pop();
		for(int i=0; i<adj_f[node].size(); i++)
			if(visited[adj_f[node][i]] == -1){
					q.push(adj_f[node][i]);
					visited[adj_f[node][i]] = visited[node] + 1;
			}
	}
}

int main(){
	long long int n,a,b,count,cnt=1;
	while(cin >> n){
		map <long long int , vector <long long int>> adj;
		if(n==0)
			break;
		while(n--){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			visited[a] = -1;
			visited[b] = -1;
		}
		while(cin >> a >> b){
			if(a==0 && b==0)
				break;
			bfs(a,adj);
			map<long long int, int>::iterator it;
			count = 0;
			for(it = visited.begin(); it!=visited.end(); it++){
				if((*it).second>b || (*it).second==-1)
					count++;
				(*it).second = -1;
				}
			printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",cnt++,count,a,b);
		}
		visited.clear();
	}
    return 0;
}
