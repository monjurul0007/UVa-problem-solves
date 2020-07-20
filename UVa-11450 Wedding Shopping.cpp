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

 
int main(){
	fasterInOut;
	
	int t;
	cin >> t;
	
	while(t--){
		int m,c,x;
		cin >> m >> c;
		
		vector <int> v[c];
		
		for(int i=0; i<c; i++){
			cin >> x;
			while(x--){
				int n; cin >> n;
				v[i].pb(n);
			}
		}
		
		int reach[c+1][201] = {0};
		
		for(auto i: v[0])
			if(m-i >= 0)
				reach[0][m-i] = 1;
		
		for(int j=1; j<c; j++)
			for(int p=1; p<201; p++) if(reach[j-1][p])
				for(auto i: v[j]) if(p-i >= 0)
					reach[j][p-i] = 1;
	
				
		int in = -1;
		
		for(int p=0; p<201; p++)
			if(reach[c-1][p]){
				in = p;
				break;
			}
		
		
		if(in == -1)
			cout << "no solution" << endl;
		else
			cout << m - in << endl;
	}
	
    return 0;
}
