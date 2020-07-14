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

vector <int> v[30];
int ar[30],n;

void return_initial(int m){
	int in = 0,cur = ar[m];
	
	for(auto i: v[cur]){
		in++;
		if(i == m)
			break;
	}
	
	for(int i=in; i<v[cur].size(); i++){
		int num = v[cur][i];
		v[num].pb(num);
		ar[num] = num;
	}
	
	v[cur].erase(v[cur].begin()+in, v[cur].end());
}

void pile_over(int m, int k){
	int in = 0,cur = ar[m];
	
	for(auto i: v[cur]){
		if(i == m)
			break;
		in++;
	}
	
	for(int i=in; i<v[cur].size(); i++){
		int num = v[cur][i];
		v[ar[k]].pb(num);
		ar[num] = ar[k];
	}
	
	v[cur].erase(v[cur].begin()+in, v[cur].end());
}


int main(){
	fasterInOut;
	
	int a,b;
	cin >> n;
	string s,s1;
	
	for(int i=0; i<n; i++){
		v[i].pb(i);
		ar[i] = i;
	}
	
	while(cin >> s){
		if(s == "quit")
			break;
			
		cin >> a >> s1 >> b;
		
		if(ar[a] == ar[b])
			continue;
			
			
		if(s == "move"){
			return_initial(a);
			
			if(s1 == "onto")
				return_initial(b);
			
			v[ar[a]].pop_back();
			v[ar[b]].pb(a);
			ar[a] = ar[b];	
		}
		else{
			if(s1 == "onto")
				return_initial(b);;

			pile_over(a,b);
		}
	}
	
	for(int i=0; i<n; i++){
		cout << i << ":";
		for(auto j: v[i])
			cout << " " << j;
		cout << "\n";
	}
	
    return 0;
}
