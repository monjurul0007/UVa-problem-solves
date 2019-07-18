#include <bits/stdc++.h>
         
using namespace std;

#define inf 1<<15
#define pu(i,j,k) push(iii(i,ii(j,k)))
#define pb(i,j,k) push_back(iii(i,ii(j,k)))

         
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
         
     
int main(){
    //freopen("input.txt","r",stdin);
    int n,m,mat[25][25],mi[25],cnt=1;
    string s[23];
    while(cin >> n  >> m, n){
		int a,b,w;
		
		for(int i =1; i<=n; i++)
			for(int j=1; j<=n; j++){
				mat[i][j] = inf;
				if(i==j)
					mat[i][j] = 0;
			}
			
	
		for(int i=1; i<=n; i++)
			cin >> s[i];
			
		for(int i=1; i<=m; i++){
			cin >> a >> b >> w;
			mat[a][b] = w;
			mat[b][a] = w;
		}
		
		for(int k=1; k<=n; k++)
			for(int i =1; i<=n; i++)
				for(int j=1; j<=n; j++)	
					mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
		
		int  mn = inf;
		for(int j =1; j<=n; j++){
			int sum = 0;
			for(int i=1; i<=n; i++)
				if(mat[i][j] != inf)
					sum += mat[j][i];
			mi[j] = sum;
			mn = min(sum , mn);
		}
		
		for(int i=1; i<=n; i++)
			if(mn == mi[i]){
				printf("Case #%d : ",cnt++);
				cout << s[i] << endl;
				break;
			}
	}
    return 0;
}
