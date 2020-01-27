#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define wk cout << "working" << endl

#define f0(data,i,n) for(data i=0; i<n; i++)
#define f1(data,i,n) for(data i=1; i<=n; i++) 
#define all(x) x.begin(),x.end()

int main(){
    int t = 1,n,m;
    
    ll x;
    string s;
    
    while(cin >> n,n){
		map <ll, int> arr;
		queue <int> team;
		queue <ll> element[n+5];
		bool cteam[n+5] = {false};
		
		f1(int,i,n){
			cin >> m;
			f0(int,j,m){
				cin >> x;
				arr[x] = i;
			}
		}
		
		cout << "Scenario #" << t++ << "\n";
		
		while(cin >> s){
			if(s == "STOP")
				break;
				
			if(s == "ENQUEUE"){
				cin >> x;
				
				if(cteam[arr[x]]){
					element[arr[x]].push(x);
				}
				else{
					cteam[arr[x]] = true;
					team.push(arr[x]);
					element[arr[x]].push(x);
				}
			}
			else{
				int num = team.front();
				cout << element[num].front() << "\n";
				element[num].pop();
				
				if(element[num].empty()){
					team.pop();
					cteam[num] = false;
				}
			}
		}
		
		cout  << endl;
	}
    
    return 0;
}
