#include <bits/stdc++.h>

using namespace std;

bool adj[91][91],vis[91];
int cnt;

void dfs(int s, int n){
    vis[s] = 1;
    for(int i=65; i<=n; i++){
        if(adj[s][i] && !vis[i]){
            vis[i] = 1;
            dfs(i, n);
        }
    }
}

void setGraph(){
    cnt = 0;
    memset(adj,0,sizeof adj);
    memset(vis,0,sizeof vis);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,n;
    bool flag = false;
    string s;
    scanf("%d",&t);
    while(t--){
        setGraph();
        cin >> s;
        n = (int) s[0];
        getline(cin , s);
        while(getline(cin , s), s!=""){
            adj[s[0]][s[1]] = 1;
            adj[s[1]][s[0]] = 1;
        }
        for(int i=65; i<=n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,n);
            }
        }
        if(flag)
            printf("\n");
        printf("%d\n",cnt);
        flag = true;
    }
    return 0;
}
