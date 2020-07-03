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

int a[6];
int o[6];
vector <int> v,phi[120];
int cnt = 0;

void permutation(){
	if(v.size() == 5){
		phi[cnt++] = v;
		return;
	}	
	
	for(int i=1; i<=5; i++){
		if(o[i] == 1)
			continue;
		v.pb(i);
		o[i] = 1;
		permutation();
		v.pop_back();
		o[i] = -1;
	}
}

bool flag;

void backtrack(int num,int in, int cur){
	if(cur >= 5){
		if(num == 23){
			flag = true;
		}
		
		return;
	}
	
	backtrack(num+a[phi[in][cur]], in, cur+1);
	backtrack(num-a[phi[in][cur]], in, cur+1);
	backtrack(num*a[phi[in][cur]], in, cur+1);
}

int main(){
	mem(o,-1);
	permutation();
	while(scanf("%d %d %d %d %d",&a[1],&a[2],&a[3],&a[4],&a[5]),a[5],a[1],a[2],a[3],a[4]){
		flag = false;
		for(int i=0; i<120; i++){
			backtrack(a[phi[i][0]],i,1);
			if(flag)
				break;
		}
		
		if(flag)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
    return 0;
}
