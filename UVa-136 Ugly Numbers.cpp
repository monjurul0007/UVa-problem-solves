#include <bits/stdc++.h>

using namespace std;

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define inf INT_MAX
#define neginf LLONG_MIN
#define all(x) x.begin(),x.end()
#define wk cout << "working" << endl

         
typedef long long int ll;     
typedef pair<int , int>  pii;
typedef pair<int , pii > piii; 
typedef priority_queue<pii, vector<pii> , greater<pii> > pq;


int main(){
    set <ll> q;
    set <ll> ugly;
    set <ll> :: iterator it;
    
    ugly.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(5);
    
    ll x;
       
    while(ugly.size() < 1500){
		x = *q.begin();
		
		q.erase(q.begin());
		
		ugly.insert(x);
		
		q.insert(x*2);
		q.insert(x*3);
		q.insert(x*5);
	}

	cout << "The 1500'th ugly number is "<< *--ugly.end() << "." << endl;
    
    return 0;
}
