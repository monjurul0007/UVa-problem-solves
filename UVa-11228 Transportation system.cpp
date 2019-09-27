#include <bits/stdc++.h> 

using namespace std;
         
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define fin(i) freopen(i, "r", stdin)
#define fout(o) freopen(o, "w", stdout)
#define pb push_back
#define inf LLONG_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl
     
typedef long long int ll;     
typedef pair<long double , int>  pii;
typedef priority_queue<pii, vector<pii> , greater<pii> > pq;

vector <pii> adj[1005];
bool vis[1005];

ll road,rail,state;
    
void init(int n){
	for(int i=1; i<=n; i++){
		vis[i] = false;
		adj[i].clear();
	}
}
 
void input(int n){
	long double d,x[n+1],y[n+1];
		
	for(int i=1; i<=n; i++)
		cin >> x[i] >> y[i];
			
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			d = ((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
			adj[i].pb(pii(d,j));
			adj[j].pb(pii(d,i));
		}
	}
}

void prims(int n,int r){
	pq q;
		
	long double w,m,a,b;
	int edge = 0,v;
  
	a = 0;
	b = 0;
	state = 0;
  
	vis[1] = true;
		
	for(const auto &i: adj[1])
		q.push(i);
			
	while(!q.empty()){
		v = q.top().second;
		w = q.top().first;
			
		q.pop();
			
		if(vis[v])
			continue;
			
		m = sqrt(w);
		if(m <= r)
			a += m;
		else {
			b += m;
			state++;
		}

		vis[v] = true;
		edge++;
			
		if(edge == n-1)
			break;
				
		for(const auto &i: adj[v]){
			if(vis[i.second] == false)
				q.push(i);
		}
	}
	road = roundl(a);
	rail = roundl(b);
}
    
int main(){
	//fin("input.txt");
	int T,n,r;
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> n >> r;
		
		init(n);
		input(n);
		prims(n,r);
		
		cout << "Case #" << t << ": "  << state+1 << " " << road << " " << rail << endl;
		
	}
	return 0;
}


