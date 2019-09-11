#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        ll la=0,lb=1,ma=1,mb=1,ra=1,rb=0;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'R'){
                la = ma;
                lb = mb;
                ma = la+ra;
                mb = lb+rb;
            }
            else{
                ra = ma;
                rb = mb;
                ma = la+ra;
                mb = lb+rb;
            }
        }
        cout << ma << "/" << mb << endl;
    }
    return 0;
}
