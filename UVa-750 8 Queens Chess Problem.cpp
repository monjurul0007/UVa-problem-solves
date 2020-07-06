#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf LLONG_MAX
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
typedef priority_queue <pii, vector<pii> , greater<pii> > pq;

const int dx4[4] = {0,1,0,-1};
const int dy4[4] = {1,0,-1,0};
const int dx8[8] = {0,1,0,-1,1,-1,1,-1};
const int dy8[8] = {1,0,-1,0,1,-1,-1,1};


int u,v,vis[9],ans[9],cnt;
vector <pii> vt;

bool cal(int x, int y){
	bool flag = true;
	for(auto i: vt){
		double num = (double)(i.F - x)/(double)(i.S - y);
		if(num == 1 || num == -1){
			flag = false;
			break;
		}
	}
	return flag;
}


void backtrack(int y){
	if(y > 8){
		printf("%2d     ",cnt++);
		for(int i=1; i<=8; i++){
			printf(" %d",ans[i]);
		}
		printf("\n");
		return;
	}
	
	if(y == v){
		backtrack(y+1);
		return;
	}
	
	for(int i=1; i<=8; i++){
		if(cal(i,y) && vis[i] == -1){
			ans[y] = i;
			vis[i] = 1;
			vt.pb({i,y});
			backtrack(y+1);
			vis[i] = -1;
			vt.pop_back();
		}
	}
}

int main(){
	//fasterInOut;
	
	int t;
	cin >> t;
	bool flag = false;
	while(t--){
		cin >> u >> v;
		vt.pb({u,v});
		mem(vis,-1);
		vis[u] = 1;
		ans[v] = u;
		
		cnt = 1;
		if(flag)
			printf("\n");
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		backtrack(1);
		vt.clear();
		flag = true;
	}
	
    return 0;
}
