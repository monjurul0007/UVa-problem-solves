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

int ar[105],n;
int dp[105][25005];

int solve(int i, int p){
	if(dp[i][p] != -1)
		return dp[i][p];
		
	if(p == 0)
		return dp[i][p] = 1;
		
	if(i >= n){
		return dp[i][p] = 0;;
	}
	
	int res1 = 0, res2 = 0;
	if(p - ar[i] >= 0)
		res1 = solve(i+1, p-ar[i]);
	res2 = solve(i+1, p);
	
	return dp[i][p] = res1 | res2;
}

int main(){
	fasterInOut;
	
	int t,sum;
	cin >> t;
	while(t--){
		cin >> n;
		sum = 0;
		for(int i=0; i<n; i++){
			cin >> ar[i];
			sum += ar[i];
		}
		
		mem(dp,-1);
		ll ans = 0;
		for(int i = sum/2; i>=1; i--){
			if(solve(0, i) > 0){
				ans = i;
				break;
			}
		}
		
		cout << sum - 2*ans << endl;
		
	}
	
	return 0;
}
