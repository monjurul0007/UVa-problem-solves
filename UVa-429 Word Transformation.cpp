#include <bits/stdc++.h>

using namespace std;

map <string, vector <string> > adj;
map <string, int> vis;

void addEdge(string s){
    string node;
    int cnt;
    vis[s] = -1;
    adj[s];
    for(map <string, vector <string> > :: iterator it = adj.begin(); it != adj.end(); it++){
        cnt = 0;
        node = it->first;
        if(node.size() == s.size())
            for(int i=0; i<node.size(); i++)
                if(node[i] != s[i])
                    cnt++;
        if(cnt == 1){
            adj[node].push_back(s);
            adj[s].push_back(node);
        }
    }
}

void bfs(string a){
    string top;
    queue <string> q;
    q.push(a);
    vis[a] = 0;
    while(!q.empty()){
        top = q.front();
        q.pop();
        int l = adj[top].size();
        for(int i = 0; i<l; i++){
            if(vis[adj[top][i]] == -1){
                q.push(adj[top][i]);
                vis[adj[top][i]] = vis[top] + 1;
            }
        }
    }
}

/*void showAdj(){
    for(map <string, vector <string> > :: iterator it = adj.begin(); it != adj.end(); it++){
        cout << it->first << " : ";
        int l = it->second.size();
        for(int i=0; i<l; i++)
            cout << it->second[i] << " ";
        cout << endl;
    }
}*/

void setGraph(){
    adj.clear();
    vis.clear();
}

void setVis(){
    for(map <string, int> :: iterator it = vis.begin(); it != vis.end(); it++)
        it->second = -1;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    bool flag = false;
    string s,a,b;
    scanf("%d",&t);
    while(t--){
        setGraph();
        while(cin >> s){
            if(s == "*")
                break;
            addEdge(s);
        }
        getline(cin , s);
        if(flag)
            cout << endl;
        flag = true;
        while(getline(cin , s), s != ""){
            stringstream ss(s);
            ss >> a >> b;
            setVis();
            bfs(a);
            cout << a << " " << b << " " << vis[b] << endl;

        }
        //showAdj();
    }
    return 0;
}
