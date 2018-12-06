#include <bits/stdc++.h>

using namespace std;

int max_m,max_d;

void bfs(vector <int> adj[], int s, int e){
    queue <int> q,_q;
    int top,vis[e],m,d=0;
    memset(vis,-1,sizeof vis);
    q.push(s);
    vis[s] = 0;
    while(!q.empty() || !_q.empty()){
        m = 0;
        while(!q.empty()){
            top = q.front();
            q.pop();
            for(int i=0; i<adj[top].size(); i++){
                if(vis[adj[top][i]] == -1){
                    m++;
                    _q.push(adj[top][i]);
                    vis[adj[top][i]] = 0;
                }
            }
        }
        d++;
        if(max_m < m){
            max_m = m;
            max_d = d;
        }
        m = 0;
        while(!_q.empty()){
            top = _q.front();
            _q.pop();
            for(int i=0; i<adj[top].size(); i++){
                if(vis[adj[top][i]] == -1){
                    m++;
                    q.push(adj[top][i]);
                    vis[adj[top][i]] = 0;
                }
            }
        }
        d++;
        if(max_m < m){
            max_m = m;
            max_d = d;
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int e,n,node;
    while(scanf("%d",&e) != EOF){
        vector <int> adj[e];
        for(int i=0; i<e; i++){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&node);
                adj[i].push_back(node);
            }
        }
        int s;
        scanf("%d",&n);
        while(n--){
            max_m = 0;
            max_d = 0;
            scanf("%d",&s);
            bfs(adj,s,e);
            if(max_m == 0)
                printf("0\n");
            else
                printf("%d %d\n",max_m,max_d);
        }
    }
    return 0;
}
