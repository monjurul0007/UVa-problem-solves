
/// https://www.geeksforgeeks.org/total-number-spanning-trees-graph/

#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first  
#define S second   

#define mod 2000000011

typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 

const int dirx[4] = {0,1,0,-1};
const int diry[4] = {1,0,-1,0};



int main(){
	fasterInOut;

	ll ans[105];
	for(int i=1; i<101; i++)
		ans[i] = 1;
		
	for(int i=3; i<101; i++){
		for(int j=0; j<(i-2); j++)
			ans[i] = (ans[i] * i) % mod;
	}
	
	
	int t,n;
	cin >> t;
	for(int T=1; T<=t; T++){
		cin >> n;
		cout << "Case #" << T << ": " << ans[n] << endl;
	}
    return 0;
}
