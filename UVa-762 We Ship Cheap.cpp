#include <bits/stdc++.h>

using namespace std;

map <string, vector < string > > adj;
map <string, string> vis;

void addEdge(int n){
    adj.clear();
    vis.clear();
    string a,b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vis[a] = "-1";
        vis[b] = "-1";
    }
}

void bfs(string s){
    queue <string> q;
    string u;
    q.push(s);
    vis[s] = s;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
            if(vis[adj[u][i]] == "-1"){
                vis[adj[u][i]] = u;
                q.push(adj[u][i]);
            }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int n;
    bool flag = false;
    string a,b;
    while(scanf("%d",&n) != EOF){
        addEdge(n);
        cin >> a >> b;
        bfs(b);
        if(flag)
            printf("\n");
        flag = true;
        if(vis[a] == "" || vis[a] == "-1")
            cout << "No route" << endl;
        else
            while(a!=b){
                cout << a << " " << vis[a] << endl;
                a = vis[a];
            }
    }
    return 0;
}
