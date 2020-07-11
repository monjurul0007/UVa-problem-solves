#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 1000000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};

string s1,s2;
ll dp[105][105];

ll solve(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
		
	if(i >= s1.size() || j >= s2.size())
		return dp[i][j] = 0;
		
	if(s1[i] == s2[j])
		return dp[i][j] = solve(i+1,j+1) + 1;
	
	
	return dp[i][j] = max(solve(i+1, j) , solve(i, j+1));
}

int main(){
	fasterInOut;
	
	int t = 1;
	while(getline(cin , s1)){
		if(s1 == "#")
			break;
		getline(cin , s2);
		
		mem(dp,-1);
		cout << "Case #" << t++ << ": you can visit at most " << solve(0,0) << " cities.\n";
	}
	
	return 0;
}
