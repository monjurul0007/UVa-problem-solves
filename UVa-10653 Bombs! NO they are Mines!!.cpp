#include <bits/stdc++.h>

using namespace std;

int adj[1001][1001];
int vis[1001][1001];
int _x[4] = {0,-1,0,1};
int _y[4] = {1,0,-1,0};

void bfs(int x, int y){
    int topx,topy;
    queue <int> qx,qy;
    qx.push(x);
    qy.push(y);
    vis[x][y] = 0;
    while(!qx.empty() && !qy.empty()){
        topx = qx.front();
        topy = qy.front();
        qx.pop();
        qy.pop();
        for(int i=0; i<4; i++){
            if((topx+_x[i]>=0 && topx+_x[i]<1000) && (topy+_y[i]>=0 && topy+_y[i]<1000))
                if(vis[topx+_x[i]][topy+_y[i]] == -1 && !adj[topx+_x[i]][topy+_y[i]]){
                    qx.push(topx+_x[i]);
                    qy.push(topy+_y[i]);
                    vis[topx+_x[i]][topy+_y[i]] = vis[topx][topy] + 1;
                }
        }
    }
}

int main(){
   // freopen("input.txt","r", stdin);
    int r,c,n,rn,num,boom,x,y;
    while(scanf("%d %d",&r,&c), (r||c)){
        memset(adj,0,sizeof adj);
        memset(vis,-1,sizeof vis);
        scanf("%d",&n);
        while(n--){
            scanf("%d %d",&rn,&num);
            for(int i = 0; i<num; i++){
                scanf("%d",&boom);
                adj[rn][boom] = 1;
            }
        }
        scanf("%d %d",&x,&y);
        bfs(x,y);
        scanf("%d %d",&x,&y);
        printf("%d\n",vis[x][y]);
    }
    return 0;
}
