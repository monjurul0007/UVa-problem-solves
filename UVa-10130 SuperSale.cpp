#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
#define all(x) x.begin(),x.end()
#define mem(arr,value) memset(arr, value, sizeof(arr))
#define mod 100000007
#define F first
#define S second
         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq; 


int main(){
	fasterInOut;
	
	int t;
	
	cin >> t;
	
	while(t--){
		ll n,q,x;		
		cin >> n >> q;
		
		ll a[n],even = 0,odd = 0;
		for(int i=0; i<n; i++){
			cin >> a[i];
			
			if(a[i]%2)
				odd++;
			else 
				even++;
		}
		
		for(int i=0; i<q; i++){
			cin >> x;
			
			if(x%2)
				cout << odd << " " << even << "\n";
			else
				cout << even << " " << odd << "\n";
		}
		
	}
	return 0;
}
