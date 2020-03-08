#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;


int n,k;
int p[1003],wt[1003];
ll dp[1003][35];

ll solve(int i, int w){
	if(dp[i][w] != -1)
		return dp[i][w];
		
    if(i >= n || w < 0)	
		return 0;
		
	ll res1 = 0;
	
	if(wt[i] <= w)
		res1 = p[i] + solve(i+1, w-wt[i]);
	ll res2 = solve(i+1, w);
	
	dp[i][w] = max(res1,res2);
	
	return dp[i][w];
}

int main(){
    int T,q;

    scanf("%d",&T);

    for(int t=1; t<=T; t++){
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            scanf("%d %d",&p[i],&wt[i]);
        }
        
		ll ans = 0;
        scanf("%d",&q);
        
        for(int i=0; i<q; i++){
            scanf("%d",&k);
            mem(dp,-1);
            ans += solve(0,k);
        }
		
        printf("%lld\n",ans);
    }
}
