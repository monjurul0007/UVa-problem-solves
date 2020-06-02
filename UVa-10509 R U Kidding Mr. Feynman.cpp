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



int main(){
	fasterInOut;

	double x;
	while(cin >> x, x){
		double a = floor(pow(x,1.0/3.0)+1e-6);
		double dx = (x-(a*a*a))/(3*a*a);
		cout << setprecision(4) << fixed << a + dx << endl;
	}
    return 0;
}
