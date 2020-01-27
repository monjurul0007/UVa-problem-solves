#include<bits/stdc++.h>
     
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
  fasterInOut;
  
	string s;
	set <string> ar;
	
	while(getline(cin,s)){
		
		string x;
		
		f0(int,i,s.size()){
			char c = tolower(s[i]);
			if(c>=97&&c<=122){
				x.pb(c);
			}
			else{
				if(x == "")
					continue;
		
				ar.insert(x);
				x = "";
			}
		}
		
		if(x == "")
			continue;
		
		ar.insert(x);
	}
		
	for(set<string> :: iterator it  = ar.begin(); it!=ar.end(); it++)
		cout << *it << endl;
	
	return 0;
}
