#include <bits/stdc++.h>
         
using namespace std;

#define inf 1<<15
#define pu(i,j,k) push(iii(i,ii(j,k)))
#define pb(i,j,k) push_back(iii(i,ii(j,k)))

         
typedef pair<int , int> ii;
typedef pair<int, ii> iii;
         
     
int main(){
    //freopen("input.txt","r",stdin);
    int a,b,mat[101][101],mx,cnt=1;
    while(cin >> a >> b){
		if(!a||!b)
			break;
		
		for(int i=1; i<=100; i++)
			for(int j=1; j<=100; j++){
				mat[i][j] = inf;
				if(i==j)
					mat[i][j] = 0;
			}
			
		mat[a][b] = 1;
		mx = max(a,b);
		while(cin >> a >> b){
			if(!a||!b)
				break;
			mat[a][b] = 1;
			mx = max(mx,a);
			mx = max(mx,b);
		}
		
		for(int k=1; k<=mx; k++)
			for(int i=1; i<=mx; i++)
				for(int j=1; j<=mx; j++)
					if(mat[i][j] > mat[i][k] + mat[k][j])
						mat[i][j] = mat[i][k] + mat[k][j];
						
		double sum = 0,links = 0;
		for(int i=1; i<=mx; i++)
			for(int j=1; j<=mx; j++)
				if(mat[i][j] != inf && i!=j){
					sum += mat[i][j];
					links++;
				}
				
		printf("Case %d: average length between pages = %.3f clicks\n",cnt++,sum/links);
	} 
    return 0;
}
