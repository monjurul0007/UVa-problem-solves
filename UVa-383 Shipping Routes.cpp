#include<bits/stdc++.h>
     
using namespace std;
     
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define all(x) x.begin(),x.end()
         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq; 


int main(){
	ll mat[35][35];
	int m,n,p,t,leg;
	string s,s1;
	
	cin >> t;
	cout << "SHIPPING ROUTES OUTPUT\n\n";
	
	for(int T=1; T<=t; T++){
		cout << "DATA SET  " << T << "\n\n";
		
		cin >> m >> n >> p;
		
		map <string , int> mp;
		
		for(int i=0; i<m; i++){
			cin >> s;
			mp[s] = i;
		}
		
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++){
				mat[i][j] = inf;
				if(i==j)
					mat[i][j] = 0;
			}
		
		int u,v;
		
		for(int i=0; i<n; i++){
			cin >> s >> s1;
			u = mp[s];
			v = mp[s1];
			mat[u][v] = 1;
			mat[v][u] = 1;	
		}
		
		for(int k=0; k<m; k++)
			for(int i=0; i<m; i++)
				for(int j=0; j<m; j++)
					if(mat[i][j] > mat[i][k] + mat[k][j])
						mat[i][j] = mat[i][k] + mat[k][j];
		
		for(int i=0; i<p; i++){
			cin >> leg >> s >> s1;
			
			u = mp[s];
			v = mp[s1];
			
			if(mat[u][v] == inf)
				cout << "NO SHIPMENT POSSIBLE\n";
			else
				cout << "$" << leg*mat[u][v]*100 << "\n";
		}
		cout << "\n";
	}
	
	cout << "END OF OUTPUT" << endl;
	
	return 0;
}
