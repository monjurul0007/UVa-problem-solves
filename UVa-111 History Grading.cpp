/*      bismillahir rahmanir rahim   
 *		     @monjurul0007
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define F first
#define S second
#define mod 11092019
#define pi acos(-1)
#define endl "\n"
 
typedef long long int ll;
typedef long double ld;        
typedef unsigned long long int ull;   
typedef pair<ll , ll>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;
 
const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};

int n,dp[30][30];
vector <int> a,b;

ll lcs(int i, int j){
	int &res = dp[i][j];
		
	if(i >= n || j >= n)
		return 0;
	
	if(res != -1)
		return res;
		
	if(a[i] == b[j])
		return res = 1 + lcs(i+1, j+1);
	
	return res = max(lcs(i+1, j) , lcs(i, j+1));
} 

int main(){
	fasterInOut;
	
	int state = 0;
	string s;
	
	while(getline(cin, s)){
		stringstream ss(s);
		
		int x;
		vector <int> temp;
		while(ss >> x)
			temp.pb(x);
			
		if(temp.size() == 1){
			n = temp[0];
			state = 1;
			continue;
		}
		
		if(state){
			for(int i=0; i<=n; i++) a.pb(0);
			for(int i=0; i<n; i++)
				a[temp[i] - 1] = i;
			
			state = 0;
			continue;
		}
		
		mem(dp, -1);
		for(int i=0; i<=n; i++) b.pb(0);
		for(int i=0; i<n; i++)
			b[temp[i] - 1] = i;
		
		cout << lcs(0,0) << endl;
	}

	return 0;
}
