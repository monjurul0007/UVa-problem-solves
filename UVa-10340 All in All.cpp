#include <bits/stdc++.h>

using namespace std;

int main(){
	string s,t;
	int sl,tl,cnt;
	while(cin >> s >> t){
		cnt = 0;
		sl = s.size();
		tl = t.size();
		for(int i=0; i<tl; i++)
			if(t[i] == s[cnt])
				cnt++;
		if(cnt == sl)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
