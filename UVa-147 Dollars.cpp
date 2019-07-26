#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[12][300010];

ll solve(int i, int a){
	if(i >= 11){
		if(a == 0)
			return 1;
		else
			return 0;
	}
	if(dp[i][a] != -1)
		return dp[i][a];
	ll com1=0,com2=0;
	if(a-coin[i] >= 0){
		dp[i][a-coin[i]] = solve(i,a-coin[i]);
		com1 = dp[i][a-coin[i]];
	}
	dp[i+1][a] = solve(i+1,a);
	com2 = dp[i+1][a];
	return com1+com2; 
} 

int main(){
	//freopen("input.txt","r",stdin);
	memset(dp, -1 , sizeof dp);
	int a,b;
	while(scanf("%d.%d",&a,&b)){
		if(a == 0 && b == 0)	
			break;
		ll dolor = a*100+b;
		printf("%3d.%02d%17lld\n",a,b,solve(0,dolor));
	}
	return 0;
}
