#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int coin[5] = {1,5,10,25,50};
ll dp[6][7600];

ll solve(int i, int a){
	if(i >= 5){
		if(a == 0)
			return 1;
		else
			return 0;
	}
	if(dp[i][a] != -1)
		return dp[i][a];
	ll com1=0,com2=0;
	if(a-coin[i] >=0){
		dp[i][a-coin[i]] = solve(i,a-coin[i]);
		com1 = dp[i][a-coin[i]];
	}
	else
		com1 = 0;
	dp[i+1][a] = solve(i+1,a);
	com2 = dp[i+1][a];
	return com1+com2; 
} 

int main(){
	//freopen("input.txt","r",stdin);
	memset(dp, -1 , sizeof dp);
	int make;
	while(scanf("%d",&make) != EOF){
		printf("%lld\n",solve(0,make));
	}
	return 0;
}
