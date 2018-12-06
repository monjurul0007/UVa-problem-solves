#include <bits/stdc++.h>

using namespace std;

 map <string , string> level;
 map <string , vector <string> > mp;

string bfs(string b, string a){
    string top,path;
    queue <string> q;
    q.push(b);
    level[b] = "0";
    while(!q.empty()){
        top = q.front();
        q.pop();
        for(int i=0; i<mp[top].size(); i++){
            if(level[mp[top][i]] == "-1"){
                q.push(mp[top][i]);
                level[mp[top][i]] = top;
            }
		}
    }
    top = a;
    while(top != "0"){
        path.push_back(top[0]);
        top = level[top];
    }
    return path;
}

void setLevel(){
	for(map<string, string>::iterator it = level.begin(); it != level.end(); it++)
		it->second = "-1";
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,m;
    bool flag = false;
    string a,b;
    scanf("%d",&t);
    while(t--){
	if(flag)
	    cout << endl;
	flag = true;
	level.clear();
        mp.clear();
        scanf("%d %d",&n ,&m);
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
            level[a] = "-1";
            level[b] = "-1";
        }
        while(m--){
            setLevel();
            cin >> a >> b;
            cout << bfs(b,a) << endl;
        }
    }
    return 0;
}
