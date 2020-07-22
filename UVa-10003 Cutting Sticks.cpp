/*      bismillahir rahmanir rahim   
 *		     @ monjurul0007
 */


#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 100000007

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};


vector <int> v;
int dp[1005][1005];

int solve(int b, int e){
	if(dp[b][e] != -1)
		return dp[b][e];
		
	if(b >= e)
		return 0;
		
	int res = INT_MAX;
	for(auto i: v) if(b < i && i < e) 
		res = min(res, e-b + solve(b, i) + solve(i, e));
		
	if(res == INT_MAX)
		res = 0;
	
	return dp[b][e] = res;
}
 
int main(){
	fasterInOut;
	
	int n;
	while(cin >> n,n){
		int m,x;
		cin >> m;
		for(int i=0; i<m; i++){
			cin >> x;
			v.pb(x); 
		}
		
		mem(dp,-1);
		cout << "The minimum cutting is " << solve(0,n) << ".\n";
		
		v.clear();
	}
	
    return 0;
}
