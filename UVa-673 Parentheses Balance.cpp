#include <bits/stdc++.h>
 
using namespace std;
 
#define inf 1<<30
#define mx 100005
#define pi acos(-1)
#define sc(a) scanf("%d",&a)
#define scc(a,b) scanf("%d%d",&a,&b)
#define sccc(a,b,c) scanf("%d%d%d",&a,&b,&c)
 
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
typedef long long int ll;
typedef unsigned long long int ull;

 
int main(){
	//freopen("input.txt","r",stdin);
	int T;
	cin >> T;
	cin.ignore();
	string str;
	for(int t=1; t<=T; t++){
		stack <char> s;
		getline(cin , str);
		int l = str.size();
		
		bool flag = false;
		for(int i=0; i<l; i++){
			if(str[i]== '(' || str[i]== '[')
				s.push(str[i]);
			else{
				if(s.empty()){
					flag = true;
					break;
				}
				if(str[i]== ')' && s.top() == '(')
					s.pop();
				else if(str[i]== ']' && s.top() == '[')
					s.pop();
				else{
					flag = true;
					break;
				}
			}
		} 
		
		if(!s.empty())
			flag = true;
			
		if(flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
