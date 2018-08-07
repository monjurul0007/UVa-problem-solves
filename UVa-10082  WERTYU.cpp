#include <bits/stdc++.h>

using namespace std;

map <char, char> keybord;

void keys(){
	string ch = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	int l = ch.size();
	for(int i=1; i<l; i++)
		keybord[ch[i]] = ch[i-1];
	keybord['`'] = '`';
	keybord['A'] = 'A';
	keybord['Z'] = 'Z';
	keybord['Q'] = 'Q';
	keybord[' '] = ' ';
}

int main(){
	int l;
	string s;
	keys();
	while(getline(cin,s)){
		l = s.size();
		for(int i = 0; i<l; i++)
			printf("%c",keybord[s[i]]);
		printf("\n");
	}
	return 0;
}
