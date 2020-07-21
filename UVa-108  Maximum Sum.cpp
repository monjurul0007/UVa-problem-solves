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



int main(){
	fasterInOut;
	
	int n;
	cin >> n;
	
	int ar[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> ar[i][j];
			
			if(i > 0) ar[i][j] += ar[i-1][j];
			if(j > 0) ar[i][j] += ar[i][j-1];
			if(i > 0 && j > 0) ar[i][j] -= ar[i-1][j-1];
		}
	}
	
	
	int ans = INT_MIN;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k = 0; k<=i; k++)
				for(int l = 0; l<=j; l++){
					int num = ar[i][j];
					
					if(l > 0) num -= ar[i][l-1];
					if(k > 0) num -= ar[k-1][j];
					if(k > 0 && l > 0) num += ar[k-1][l-1];
					
					ans = max(ans, num);
				}
				
	cout << ans << endl;
	
	return 0;
}

