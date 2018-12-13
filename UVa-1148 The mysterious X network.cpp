#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int t,n,num,node,c,a,b,top;
    bool flag = false;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector <int> adj[n];
        int vis[n];
        memset(vis,-1,sizeof vis);
        for(int q=0; q<n; q++){
            scanf("%d %d",&node,&num);
            while(num--){
                scanf("%d",&c);
                adj[node].push_back(c);
            }
        }
        scanf("%d %d",&a,&b);

        queue <int> q;
        q.push(a);
        vis[a] = 0;
        while(!q.empty()){
            top = q.front();
            q.pop();
            for(int i=0; i<adj[top].size(); i++)
                if(vis[adj[top][i]] == -1){
                    vis[adj[top][i]] = vis[top] + 1;
                    q.push(adj[top][i]);
                }
        }
        if(flag)
            printf("\n");
        printf("%d %d %d\n",a,b,vis[b]-1); // Excludes endpoint
        flag = true;
    }
    return 0;
}
