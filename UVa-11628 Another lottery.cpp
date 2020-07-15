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
	
	ll ar[10004],x,sum;
	int n,m;
	
	while(cin >> n >> m, n, m){
		sum = 0;
		for(int j=0; j<n; j++)
			for(int i=0; i<m; i++){
				cin >> x;
				if(i==m-1){
					ar[j] = x;
					sum += x;
				}
			}
		
		for(int i=0; i<n; i++)
			cout << ar[i]/__gcd(ar[i],sum) << " / " << sum/__gcd(ar[i],sum) << "\n";
	}
	
	return 0;
}

