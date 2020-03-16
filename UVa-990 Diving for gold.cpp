#include <bits/stdc++.h>

using namespace std;

int d[35],v[35],e,w;
int dp[35][1003];
int dpCount[35][1003];

int solve(int i, int t){
    if(dp[i][t] != -1)
        return dp[i][t];

    if(i>=e || t <= 0)
        return 0;

    int res1 = 0, res2 = 0;

    if(t-(3*w*d[i]) >= 0)
        res1 = v[i] + solve(i+1, t-(3*w*d[i]));
    res2 = solve(i+1, t);

    dp[i][t] = max(res1,res2);

    if(res1 > res2){
        dpCount[i][t] = 1;
    }
    else{
        dpCount[i][t] = 2;
    }

    return dp[i][t];
}

int main(){
    //freopen("in.txt","r",stdin);

    int t;
    bool flag = false;

    while(scanf("%d %d",&t,&w) == 2){
        scanf("%d",&e);

        for(int i=0; i<e; i++)
            scanf("%d %d",&d[i],&v[i]);

        memset(dp,-1,sizeof(dp));
        vector < pair<int, int> > ans;

        int k = 0,mx = solve(0,t);

        while(t>=0 && k<e){
            if(dpCount[k][t] == 1){
                ans.push_back({d[k],v[k]});
                t -= 3*w*d[k];
                k++;
            }
            else{
                k++;
            }
        }

        if(flag){
            printf("\n");
        }
        flag = true;

        printf("%d\n%d\n",mx,ans.size());
        for(int i=0; i<ans.size(); i++)
            printf("%d %d\n",ans[i].first,ans[i].second);

    }

    return 0;
}
