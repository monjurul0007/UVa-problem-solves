#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,rs;
    int cnt;
    while(cin >> s){
        set <string> pli;
        int l = s.size();
        rs = s;
        reverse(rs.begin(),rs.end());
        if(rs == s)
            pli.insert(s);
        for(int i = 1; i<= l-1; i++){
            for(int j=0; j<=l-i; j++){
                string s1,rs1;
                for(int k = j; k<j+i; k++)
                    s1.push_back(s[k]);
                rs1 = s1;
                reverse(rs1.begin(),rs1.end());
                if(rs1 == s1)
                    pli.insert(s1);
            }
        }
        cout << "The string '" << s << "' contains " << pli.size() << " palindromes." << endl;
    }
	return 0;
}
