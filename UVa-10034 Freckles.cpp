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
    
vector <pii> adj[105];
bool vis[105];
    
void init(){
  for(int i=1; i<=100; i++){
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
    
    
long double prims(int n){
  pq q;
		
  long double w,mst = 0;
  int edge = 0,v;
		
  vis[1] = true;
		
  for(const auto &i: adj[1])
    q.push(i);
		
  while(!q.empty()){
    v = q.top().second;
    w = q.top().first;
			
    q.pop();
			
    if(vis[v])
      continue;
			
    mst += sqrt(w);
    vis[v] = true;
    edge++;
			
    if(edge == n-1)
      break;
				
    for(const auto &i: adj[v]){
      if(vis[i.second] == false)
        q.push(i);
    }
  }
  return mst;
}
	
int main(){
  //fin("input.txt");
  int t,n;
  cin >> t;
  bool f = 0;
  while(t--){
    cin >> n;
			
    init();
			
    input(n);
		
    if(f)
      cout << endl;
    f = 1;
			
    cout << setprecision(2) << fixed << prims(n) << endl;
  }
  return 0;
}
