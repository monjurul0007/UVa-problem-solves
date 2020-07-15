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

int n,k,arr[10005];
int dp[10004][102];

int solve(int i, int m){
	if(dp[i][m] != -1)
		return dp[i][m];	
	
	if(i >= n)
		if(m == 0)
			return dp[i][m] = 1;
		else
			return dp[i][m] = 0;
	
	bool res = solve(i+1, (m+arr[i]+k)%k);
	
	if(!res)
		res = solve(i+1, (m-arr[i]+k)%k);
	
	return dp[i][m] = res;
}

int main(){
	fasterInOut;
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i] = abs(arr[i]);
		}
		
		mem(dp,-1);
		
		if(solve(1,(arr[0]+k)%k))
			cout << "Divisible\n";
		else
			cout << "Not divisible\n";
		
	}
	
    return 0;
}
