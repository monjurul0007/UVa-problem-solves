#include <bits/stdc++.h>

using namespace std;

bool adj[100][100];
bool vis[100];
bool tempVis[100];

void dfs(int s, int n){
    vis[s] = 1;
    for(int i=0; i<n; i++)
        if(adj[s][i] && !vis[i]){
            vis[i] = 1;
            dfs(i,n);
        }
}

void dfs(int s, int target, int n){
    if(s == target)
        tempVis[s] = 1;
    else{
        tempVis[s] = 1;
        for(int i=0; i<n; i++)
            if(adj[s][i] && !tempVis[i]){
                tempVis[i] = 1;
                dfs(i,target,n);
            }
    }
}

void showVis(int n){
    for(int i=0; i<n; i++)
        cout << vis[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++)
        cout << tempVis[i] << " ";
    cout << endl;
}

void setGraph(){
    memset(adj,0,sizeof adj);
    memset(vis,0,sizeof vis);
}

int main(){
    //freopen("input.txt","r",stdin);
    int t,n,T=1;
    scanf("%d",&t);
    while(t--){
        setGraph();
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&adj[i][j]);
        dfs(0,n);
       // showVis(n);
        printf("Case %d:\n+",T++);
        for(int i=0; i<2*n-1; i++)
            printf("-");
        printf("+\n");
        for(int i=0; i<n; i++){
            memset(tempVis,0,sizeof tempVis);
            dfs(0,i,n);
            //showVis(n);
            tempVis[i] = !tempVis[i];
            printf("|");
            for(int j=0; j<n; j++)
                if(vis[j] != tempVis[j] && vis[j])
                    printf("Y|");
                else
                    printf("N|");
            printf("\n+");
            for(int i=0; i<2*n-1; i++)
                printf("-");
            printf("+\n");
        }
    }
    return 0;
}
